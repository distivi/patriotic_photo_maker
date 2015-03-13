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

@class IDLDefinitionScope, IDLDefinition, IDLInterface, CORBAObject, IDLParser, ORBNotificationCenter;
@protocol IDLDefinition;

@interface ORB : NSObject
{
@private
    IDLParser* _parser;
    IDLDefinitionScope* _rootScope;
    NSMutableDictionary* _cache;
}

+ (NSZone*)zone;
+ (void) ORBInit; // Does nothing 
+ (ORB*) defaultORB;
+ resolveInitialReferences:(NSString*)service;

+ (ORBNotificationCenter*) notificationCenter;

// PIDL: get_default_context()
// Returns the default context
// The members are the dictionaries (or NSObject) with the keys: 'name', 'value'; both values are NSString
// Initially, the array is empty; used by the operations, which IDL definition contains 'context'
// Nested contexts are not supported and not allowed
+ (NSMutableArray*) defaultContext; 


+ (void) run;

+ (void) shutdown;

// Post notification to ORB thread
+ (void) postNotification:(NSNotification*)note;

// Initializes new instance of ORB
- initWithIDLFiles:(NSArray*)paths;
- initWithIDLFiles:(NSArray*)paths searchPaths:(NSArray*)serachPaths;

// Parses IDL files with paths passed in the 'idlFies' array
- (void) loadFiles:(NSArray*)idlFiles;

// Add 'paths' to parser's search paths for #include and #import
- (void) addToSearchPath:(NSArray*)paths;

- (IDLInterface*) interfaceNamed:(NSString*)namePath;
- (id <IDLDefinition>) definitionWithTypeID:(NSString*)typeId;
- (IDLDefinition*) definitionNamed:(NSString*)namePath;

// Creates local object, not autoreleased
- (CORBAObject*) createObjectWithInterface:(IDLInterface*)interface;

// Create remote object (object reference), autoreleased
- (CORBAObject*) objectWithIOR:(NSString*)iorString;
- (CORBAObject*) objectWithURL:(NSString*)corbaurl;

+ (void) unregisterObject:(CORBAObject*)object;

// Sets ORB as a current ORB in the current thread
- (void) set;

// Incoming requests will be served on the main thread
// By default the incoming requests are handled on a dedicated thread
+ (BOOL) handlesRequestsOnMainThread;
+ (void) setHandlesRequestsOnMainThread:(BOOL)flag;

// Maximum number of simultaneous threads for incoming requests (default 10)
+ (unsigned) maxNumberOfInvocationThreads;
+ (void) setMaxNumberOfInvocationThreads:(unsigned)num;

+ (BOOL) allowsIndirection;
// Set whether to allow using indirections when marshaling TypeCode (default is YES)
+ (void) setAllowsIndirection:(BOOL)flag;

+ (BOOL) allowsUndefinedKeys;
+ (void) setAllowsUndefinedKeys:(BOOL)flag;

@end

@interface ORB(OctetMapping)
// octet is mapped now to unsigned char
// these methods provide compatibility with previous version where octet was mapped to NSData*
// The method '[setMapsOctetToNSData:YES]' should be called before ORB initialization
// The types octet[] and sequence<octet> continue to be mapped to NSData *
+ (void) setMapsOctetToNSData:(BOOL)flag;
+ (BOOL) mapsOctetToNSData;
@end
