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

enum _ORBServiceContext {
	ORB_TransactionService = 0,
	ORB_CodeSets = 1,
	ORB_ChainBypassCheck = 2,
	ORB_ChainBypassInfo = 3,
	ORB_LogicalThreadId = 4,
	ORB_BI_DIR_IIOP = 5,
	ORB_SendingContextRunTime = 6,
	ORB_INVOCATION_POLICIES = 7,
	ORB_FORWARDED_IDENTITY = 8,
	ORB_UnknownExceptionInfo = 9,
	ORB_RTCorbaPriority = 10,
	ORB_RTCorbaPriorityRange =11,
	ORB_FT_GROUP_VERSION = 12,
	ORB_FT_REQUEST = 13,
	ORB_ExceptionDetailMessage = 14,
	ORB_SecurityAttributeService = 15,
	ORB_ActivityService = 16
};

@protocol IDLDefinition;
@class CORBAObject;

@interface IDLServiceContext : NSObject 
{
    unsigned _context_id;
    NSData* _context_data;
    id _context;
}

- initWithContextId:(unsigned)tag context:context;
+ serviceContextWithContextId:(unsigned)tag context:context;
- init;

// Register IDL path for the service context with contextId, so it can be marshaled and un-marshaled
// If a contextId for an incoming service context is not registered then the context is not un-marshaled
// if a contextId is not registered for an outgoing service context or if the path is incorrect 
// the exception will be raised
// The already know contexts are CodeSets and BI_DIR_IIOP
+ (void) registerContextId:(unsigned)ctxtId withIDLPath:(NSString*)path;

- (unsigned) contextId;
- context;

// Returns the current request context dictionary with key/values pairs contextId/IDLServiceContext
// on client the current request context will be sent to the server with invocation,
// on the server the current request context is received from the client
+ (NSDictionary*) currentContextDictionary;
+ (IDLServiceContext*) currentContextForContextId:(unsigned)contextId;

// The client can add a context to the current contexts that will be sent to server along with the request
// unless modified by interceptors
+ (void) addContext:(IDLServiceContext*)context;

// Removes context with contextId from the current context dictionary
+ (void) removeContextWithContextId:(unsigned)contextId;


+ codeSetsServiceContext:(unsigned)charData:(unsigned)wcharData;
+ codeSetsWithStringEncodings:(NSStringEncoding)stringEnc :(NSStringEncoding)wstringEnc;
+ (NSStringEncoding) stringEncodingWithCode:(unsigned)code;
+ (NSStringEncoding) wstringEncodingWithCode:(unsigned)code;

// Default string encodings are used to create the CodeSets context if no CODE_SETS tagged component 
// is present in the IOR (for example, if IOR is created from a corbaloc:).
// If defaultStringEncoding is 0 (default value), no CodeSets service context is sent to the server.
// The values can be set also in the user defaults or as parameters in a command line using 
// -ORBDefaultStringEncoding <uint> and -ORBDefaultWStringEncoding <uint>, the values are defined in NSString.h

+ (NSStringEncoding) defaultStringEncoding;
+ (NSStringEncoding) defaultWStringEncoding;
+ (void) setDefaultStringEncoding:(NSStringEncoding)encoding;
+ (void) setDefaultWStringEncoding:(NSStringEncoding)encoding;

@end
