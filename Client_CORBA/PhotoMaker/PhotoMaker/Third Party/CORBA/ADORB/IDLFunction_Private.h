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

#import "IDLFunction.h"
#import "CORBACoding.h"

@interface IDLFunction(Private)
+ function:(NSString*)name returning:retType args:(NSArray*)args;
- (void) setInterfaceObject:(IDLInterface*) anObj;
- (void) setExceptionList:(NSArray*)list;
- (void) setContextList:(NSArray*)list;
- (void) setIsFactory:(BOOL)flag;
- (NSLock*) getLock;

@end

@interface IDLFunction(CORBACoding)

- (NSMethodSignature*)methodSignature;
- (NSMutableDictionary*)getArgValues:(NSMutableDictionary*) dict fromInvocation:(NSInvocation*)inv;
- (void) setValues:(NSDictionary*)dict forInvocation:(NSInvocation*)inv;

- (void) decodeRequest:(id*)obj withCoder:(id <CORBADecoder>)coder;
- (void) encodeReply:obj withCoder:(id <CORBACoder>)coder;
- (NSInvocation*) invocation;
- (NSInvocation*) invocationWithArguments:(NSMutableDictionary*)args;
- (NSInvocation*) invocationWithArguments:(NSMutableDictionary*)dict methodSignature:(NSMethodSignature*)ms;
- (NSMutableDictionary*)takeValues:(NSMutableDictionary*) dict fromInvocation:(NSInvocation*)inv;

- (IDLException*) exceptionWithTypeID:(NSString*)typeId;

- (void) _encodeContextList:context withCoder:(id <CORBACoder>)coder;
- (void) _decodeContextList:(id*)context withCoder:(id <CORBADecoder>)coder;

- (BOOL) willSendReference;

@end
