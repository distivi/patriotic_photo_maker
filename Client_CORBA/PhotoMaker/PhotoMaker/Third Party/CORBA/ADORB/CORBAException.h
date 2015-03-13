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
#import "CORBAObject.h"
#import "IDLInterface.h"

typedef enum _completion_status {
    CORBA_CompletedYes,
    CORBA_CompletedNo,
    CORBA_CompletedMaybe
} CORBACompletionStatus;

typedef enum _exception_type {
	CORBA_NO_EXCEPTION,
	CORBA_USER_EXCEPTION,
	CORBA_SYSTEM_EXCEPTION,
	CORBA_LOCATION_FORWARD // = GIOP_LocationForward
} CORBAExceptionType;

@interface CORBAException : NSException
{
}

+ systemException:(NSString*)name minorCode:(long)code completed:(CORBACompletionStatus)status;
+ (void) raise:(NSString*)name minorCode:(long)code completed:(CORBACompletionStatus)status;
+ (NSDictionary*)standardExceptionInfoForName:(NSString*)name;
+ (void) registerStandardExceptionInfo:(NSDictionary*)info forExceptionName:(NSString*)name;
+ exceptionWithName:(NSString*)name interface:(IDLInterface*)interface;
+ userException:(NSString*)namePath info:(NSDictionary*)info;

// Creates a LOCATION_FORWARD exception
// When received on client this exception redirects the request to the new target 'object'
+ forwardRequestExceptionWithObject:object;
+ (BOOL) isForwardRequestException:(NSException*)exception;
@end

@interface CORBAObject(CORBAException)
- (CORBAException*) exceptionWithName:(NSString*)name;
@end

@interface IDLInterface(CORBAException)
- (CORBAException*) exceptionWithName:(NSString*)name;
@end

extern NSString* CORBASystemException;
extern NSString* CORBAUserException;
extern NSString* CORBANotImplemented;
extern NSString* CORBAForwardRequest;

extern NSString* IDLExceptionTypeKey;
extern NSString* IDLExceptionIDKey;
extern NSString* IDLExceptionKey;
extern NSString* IDLMinorCodeKey;
extern NSString* IDLCompletionStatusKey;

