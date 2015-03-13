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
#import "IDLDefinition.h"
#import "IDLDefinitionScope.h"

@class IDLInterface;
@protocol CORBADecoder, CORBACoder;

@interface IDLValueType : IDLDefinition <IDLDefinitionScope, IDLClassMap>
{
    NSString* _name;
    id	_support; // either TypeSpec for box value or ClassSpec
    NSString* _className;
    short _modifier;
}

- (BOOL) isAbstract;

+ valueBase;
- superValue;
- (BOOL) isDerivedFrom:(IDLValueType*)value;
- (BOOL) isDerivedFromInterface:(IDLInterface*)interface;

// Looks for valuetype that supports interface and can encode 'object'
+ valuetypeForObject:object interface:(IDLInterface*)interface;

// Looks for valuetype that can encode 'object'
+ valuetypeForObject:object;

// Looks for valuetype derived from 'self' that can encode 'object'
- valuetypeForObject:object;

// Register valuetype for a class
+ (void) registerValuetype:(IDLValueType*)value forClass:(Class)objectClass;

+ (void) invalidateValuetypeCache;

+ defaultObjectClass;
+ (void) setDefaultObjectClass:aClass;

@end

@interface IDLValueType(ChunkEncoding)
// Valuetypes can be encoded in chunks
// The default value is YES
+ (BOOL) encodeValuesUsingChunks;
+ (void) setEncodeValuesUsingChunks:(BOOL)useChunks;
@end

// Notification
extern NSString* IDLValuetypeNeededForObject;

@interface NSObject(IDLValueType)
- (IDLValueType*) valuetype;
- (void) setValuetype:(IDLValueType*)type;
@end

