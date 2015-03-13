/*
 *  AdORB
 *  Copyright (C) 2006 Victor Ananiev
 *
 *  This file is part of ADORB.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#import <Foundation/Foundation.h>

@class IDLInterface, IDLGIOPVersion, IDLServiceContext;
@class IDLFunction;
@class IDLTaggedComponent;

#define TAG_INTERNET_IOP 0
#define TAG_MULTIPLE_COMPONENTS 1

typedef struct _CORBAObject_Flags{
    unsigned int activated:1;
    unsigned int unique:1;
	unsigned int waitConnect:1;
    unsigned int reserved:29;
} CORBAObjectFlags;

@protocol CORBAObject <NSObject>
- (IDLInterface*)interface;
@end

@interface CORBAObject : NSObject <CORBAObject>
{
@private
    IDLInterface* _interface; // not retained
    NSString* _typeId;
    NSMutableArray* _profiles;
    id _connection;
    id _implementation;
	id _delegate;
	NSError* _error;
	IDLServiceContext* _codeSetsContext;
    NSTimeInterval _replyTimeout;
    NSTimeInterval _connectTimeout;
    CORBAObjectFlags _flags;
}

- initWithInterface:(IDLInterface*)interface;
+ objectWithIOR:(NSString*)iorString;

// URL may have the following formats:
//
// corbaloc:<the-rest-of-corbaloc> 
//    - only single host address is supported, the object's interface must be set then
//
// corbaname:<the-rest-of-corbaname>  
//    - only single host address is supported
//
// IOR:<the-rest-of-IOR>
//
// file://<file-path> - path of CORBA URL/IOR file
//
// http://<rest-of-URL> - URL of CORBA URL/IOR 

+ objectWithURL:(NSString*)url;

- delegate;
- (void) setDelegate:delegate;

// Sets receiver's interface to 'interface'
// and sets receiver's typeID to interface's typeID
// Can be used after +objectWithURL: when url is 'corbaloc:' since this url 
// does not give any information about object's interface or typeID

- (void) setInterface:(IDLInterface*)interface;

- (NSString*) toString;

- (IDLInterface*)interface;

// Sets interface with object's typeId, if found.
// Raises CORBADefinitionException if interface's version does not match object's typeId
- (void) narrowInterface;

- (BOOL) implementsInterfaceNamed:(NSString*)name;
- (BOOL) respondsToSelector:(SEL)selector;

- (NSMutableDictionary*) invokeMethod:(NSString*)operationName with:(NSDictionary*)arguments;
- (NSMutableDictionary*) invokeFunction:(IDLFunction*)fo with:(NSDictionary*)args;
- valueForAttribute:(NSString *)name;
- (void) setValue:value forAttribute:(NSString *)name;

- (NSData*)objectID;
- (NSArray*)profiles;
- profileWithTag:(int)tag;
- (IDLGIOPVersion*) iiopVersion;

- (BOOL) isLocal;
- implementation;

// Registers the 'object' in ORB with the key 'stringKey'. ORB retains the 'object'
// Raises CORBAAlreadyBoundException if 'object' has implementation, or CORBADuplicateKey
// The implementation 'object' is retained by the receiver, the receiver is retained by ORB
- (void) registerImplementation:object withKey:(NSString*)stringKey;
- (void) registerImplementation:object withObjectID:(NSData*)data;

// Returns receiver's connection creating it if necessary
- connection;
- (BOOL) isConnected;

// Connect object in background and posts notification CORBAObjectDidConnect on main thread when connected
// and CORBAObjectDidNotConnect of failed to connect
// If failed, notification's userInfo contains NSError for key @"error"
- (BOOL) connectInBackgroundAndNotify:(NSError**)error;

// Returns NSError that caused object to invalidate
// The detailed reason is not available in the exception and this method can be used
- (NSError*) lastError;

- (NSTimeInterval) replyTimeout;
- (void) setReplyTimeout:(NSTimeInterval)timeout;

- (NSTimeInterval) connectTimeout;

// Sets connect timeout
// If object cannot connect within timeout the object is invalidated and 
// method lastError will return NSError with domain NSPOSIXErrorDomain and code ETIMEDOUT
- (void) setConnectTimeout:(NSTimeInterval)timeout;

+ (double) defaultReplyTimeout;
+ (double) defaultConnectTimeout;
+ (void) setDefaultReplyTimeout:(double)timeout;
+ (void) setDefaultConnectTimeout:(double)timeout;

- (NSNumber*) enumValueForName:(NSString*)namePath andKey:(NSString*)key;

// Returns hostname from IIOP profile, i.e. remote host for reference object, local host for local object.
- (NSString*) host;
// Returns port number from IIOP profile.
- (NSNumber*) port;

- (BOOL) isA:(NSString*)logicalTypeID; // IDL: is_a(in type_id)

@end

@interface CORBAObject(TaggedComponents)
- (NSArray*) taggedComponents;
- (void) addTaggedComponent:(IDLTaggedComponent*)component;
- (IDLTaggedComponent*) taggedComponentWithTag:(unsigned)tag;
@end

@protocol CORBAActivation
- interface;
@end

// To be portable, the NSObject should implement '-interface' method that returns IDLInterface
@interface NSObject(CORBAActivation)
- (void) activate;
- (void) activateWithObjectID:(NSData*)key;
- (void) activateWithObjectKey:(NSString*)key;
- (void) deactivate;
- (CORBAObject*) objectReference;
@end

// Protocol is used in CORBAObject delegate
@protocol CORBAInvocation
- (SEL) selector;
- (NSString*) selectorString;
- (void) setObjectReturnValue:(id)value;
- returnValue;
@end

// Delegate methods
// Messages are sent only if implemented by delegate
@interface NSObject(CORBAObjectDelegate)

// This method is called when the object's connection is invalidated
// Notification name is ORBInvalidateObject
// userInfo contains NSError for key @"error"
// The notification is posted on the main thread only if NSRunLoop is running
- (void) objectDidInvalidate:(NSNotification*)notification;

// This method is called when server returns GIOP_LocationForward or GIOP_LocationForwardPerm
// The newObject is a CORBAObject the message will be forwarded to.
// The newObject is autoreleased.
// The delegate can cancel forwarding invocation by returning NO.
// The method that caused the exception will return nil (if it is not void). Other arguments are unchanged.
// The delegate can change the return value (if of type id) by sending -setObjectReturnValue: to invocation.
// If the delegate does not implement this method or there is no delegate
// the invocation is forwarded to newObject. The newObject and its connection will be release.
- (BOOL) object:(CORBAObject*)object willForwardInvocation:(id <CORBAInvocation>)invocation toObject:(CORBAObject*)newObject permanently:(BOOL)perm;

@end

extern NSString* CORBAErrorDomain; /* NSError domain */
enum _CORBADomainErrorCode
{
	kENoProfile = -19101,			// No profile with tag TAG_INTERNET_IOP in CORBAObject 
	kEInvocationException = -19102, // exception in invocation
	kEInvalidMessage = -19103,		// incorrect message type
	kEEndOfFile = -19104,			// read end of file
	kECloseConnection = -19105,		// received message GIOP_CloseConnection
	kELocalObject = -19106			// try to connect local object
};

extern NSString* ORBInvalidateObject; /* Notification */
extern NSString* CORBAObjectDidConnect; /* Notification */
extern NSString* CORBAObjectDidNotConnect; /* Notification */

extern NSString* IDLUnionDescriptorKey; /* = @"descriptor" */
extern NSString* IDLUnionDataKey; /* = @"value" */

// If YES, checks interface version whether it matches typeId when narrowing interface, otherwise not.
extern BOOL VXVerifyInterfaceVersion; /* = YES */

// Exceptions

extern NSString* CORBATimeoutException;
extern NSString* CORBADefinitionException;
extern NSString* CORBACommunicationException;
extern NSString* InvalidFormatException;
extern NSString* CORBAMarshalException;
extern NSString* IDLDefinitionException;
extern NSString* CORBAAlreadyBoundException;
extern NSString* CORBANotActivatableException;
extern NSString* CORBAInvalidArgumentException;
extern NSString* ConnectionException;

// Notifications
extern NSString *ORBLocalAddressDidChange;

// Deprecated
extern NSString* VXInvalidateObject; // renamed to ORBInvalidateObject
