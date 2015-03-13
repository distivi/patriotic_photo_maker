/*
 *  AdORB
 *  Copyright (C) 2007 Victor Ananiev
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

@class IDLFunction, CORBAObject, IDLServiceContext;

@interface ORBNotificationCenter : NSObject 
{
	NSLock* _lock;
	NSMutableSet* _data;
	NSMutableSet* _set;
}

- init;

// standard notification center methods
- (void)addObserver:anObserver selector:(SEL)aSelector name:(NSString *)notificationName object:anObject;
- (void)postNotification:(NSNotification *)notification;
- (void)postNotificationName:(NSString *)notificationName object:(id)anObject;
- (void)postNotificationName:(NSString *)notificationName object:(id)anObject userInfo:(NSDictionary *)userInfo;
- (void)removeObserver:(id)anObserver;
- (void)removeObserver:(id)anObserver name:(NSString *)notificationName object:(id)anObject;

// Interceptor registration

// A client interceptor should register with [ORB notificationCenter] for ORBWillSendRequest notification
// and optionally for ORBDidReceiveResponse, ORBDidReceiveException, and/or ORBDidReceiveOther notifications
// All the client interceptor notifications are posted on the invocation thread
// Several interceptors may be registered, they will be called by ORBWillSendRequest in the order they were registered

// A server interceptor should register for ORBDidReceiveRequest notification and optionally for
// ORBDidReceiveRequestContext, ORBWillSendResponse, ORBWillSendException, and/or ORBWillSendOther notifications.
// A server interceptor can also register itself for the ORBDidReceiveRequestContext notification only.
// All the server interceptor notifications are posted on the invocation thread.

// An interceptor can raise an exception
// by default only CORBASystemException and ForwardRequest exceptions are allowed, all other exceptions are ignored
// Methods below add exception that  will be passed to the other interceptors or returned.
// (for the regular notifications all the exceptions are ignored)
- (void) addAllowedExceptionName:(NSString*)name;
- (void) addAllowedExceptionNamesFromArray:(NSArray*)names;

// removes allowed exception name
- (void) removeAllowedExceptionName:(NSString*)name;

@end

@protocol ORBRequestInfo
- (SEL) selector;
- (NSDictionary*) requestContext;
- (IDLServiceContext*) requestContextWithContextId:(unsigned)contextId;
- (void) addRequestContext:(IDLServiceContext*)context;
- (void) removeRequestContextWithContextId:(unsigned)contextId;
- (NSDictionary*) responseContext;
- (IDLServiceContext*) responseContextWithContextId:(unsigned)contextId;
- (void) addResponseContext:(IDLServiceContext*)context;
- (void) removeResponseContextWithContextId:(unsigned)contextId;
- (unsigned) completionStatus;
- (NSDictionary*) arguments;
- (IDLFunction*) operationObject;
- (CORBAObject*) object;
@end

// IOR interceptor notification
// notification's object is a CORBAObject which profile is created
// notification's userInfo contains 1 key/value pair: IDLIOPProfile for key @"profile"
// this notification allows to add IDLTaggedComponents to the profile when CORBAObject is created implicitly
extern NSString* ORBDidCreateObjectProfile;

// CORBA server request interceptor notifications
// notification's object conforms to the protocol ORBRequestInfo

extern NSString* ORBDidReceiveRequestContext;
extern NSString* ORBDidReceiveRequest;

// server interceptor will receive these notifications only if it did receive ORBDidReceiveRequest
extern NSString* ORBWillSendResponse;
extern NSString* ORBWillSendException;
extern NSString* ORBWillSendOther; // method call will return ForwardRequest exception

// CORBA client request interceptor notifications
// notification's object conforms to protocol ORBRequestInfo

extern NSString* ORBWillSendRequest;

// client intercepor will receive these notification only if it did receive ORBWillSendRequest
extern NSString* ORBDidReceiveResponse;
extern NSString* ORBDidReceiveException;
extern NSString* ORBDidReceiveOther; // ForwardRequest exception is returned

// notification's userInfo contains key/value pairs for these keys:

// ORBServiceContextKey: NSDictionary with key/value pairs contextId/IDLServiceContext which is request context 
// for ORBDidReceiveRequestContext, ORBDidReceiveRequest and ORBWillSendRequest
// and response context for the rest
extern NSString* ORBServiceContextKey;

// ORBOperationNameKey: operation name (NSString) as in IDL
extern NSString* ORBOperationNameKey;

// ORBObjectKey: target CORBAObject
extern NSString* ORBObjectKey;

// ORBRequestIdKey: requestId (NSNumber)
extern NSString* ORBRequestIdKey;

// ORBExceptionKey: exception, if any; 
// valid for ORBDidReceiveException, ORBDidReceiveOther, ORBWillSendException, ORBWillSendOther
extern NSString* ORBExceptionKey;

// ORBReplyStatusKey: reply status; 
extern NSString* ORBReplyStatusKey;

// ORBOnewayKey: whether the operation is oneway, NSNumber(BOOL)
extern NSString* ORBOnewayKey;

extern NSString* ORBCompletionStatusKey;

