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
#import "IDLDefinitionScope.h"

@class IDLInterface, IDLValueType;
@protocol CORBADecoder, CORBACoder;

@interface IDLValueClass : NSObject <IDLDefinitionScope, NSCoding>
{
	IDLValueType* _valuetype; /* parent valuetype */
    NSMutableDictionary* _definitionDict; /* export */
    id <IDLDefinitionScope> _parentScope;
    IDLInterface* _interface; /* concrete supported interface */
    IDLValueType* _super; /* concrete super valuetype */
    NSMutableArray*	_supportArray; /* abstract supported interfaces */
    NSMutableArray*	_inheritance; /* abstract valuetypes */
    NSMutableArray* _members;
    short _modifier;
    BOOL _truncatable;
}

- initWithValueType:(IDLValueType*)valuetype;
- (void) setModifier:(int)modifier;
- (void) setInheritance:(NSArray*)list truncatable:(BOOL)flag;
- (void) setSupportedInterfaces:(NSArray*)list;
- (BOOL) addMembers:(NSArray*)nameArray ofType:(IDLDefinition*)type withMode:(int)accessMode;
- (IDLDefinition*)_definitionNamed:(NSString*)name;
- (BOOL) isAbstract;
- (int) modifier;
- (BOOL) isDerivedFrom:(IDLValueType*)value;
- (NSString*) typeId;

@end

@interface IDLValueClass(CORBACoding)
- (void) encodeObjectState:obj withCoder:(id<CORBACoder>)coder;
- (void) decodeObjectState:(id*)obj withCoder:(id <CORBADecoder>)coder;
- (void) decodeFromCoder:(id <CORBADecoder>)coder;
@end

#import "IDLDefinitionScope_Private.h"

@interface IDLValueClass(Private) <IDLScopePrivate>

@end
