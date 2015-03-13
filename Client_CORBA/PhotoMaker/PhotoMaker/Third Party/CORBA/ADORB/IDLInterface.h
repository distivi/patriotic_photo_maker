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

#import "IDLDefinition.h"
#import "IDLDefinitionScope.h"

@class IDLAttribute;

@interface IDLInterface:IDLDefinition <IDLDefinitionScope>
{
    NSMutableDictionary* _list; // Definitions
    NSArray* _inheritance; // Parent interfaces
    NSString* _name;
    id _connection;
    id <IDLDefinitionScope> _parentScope;
    NSMutableDictionary* _selectorList; // Functions by selectorName
    NSMutableDictionary* _methodList; // Functions by name
    BOOL _isAbstract;
    BOOL _isLocal;
}

- (BOOL) isAbstract;
- (BOOL) isLocal;
- (BOOL) isRootInterface; // i.e. "Object"
- (BOOL) implementsInterfaceNamed:(NSString*)aName;
- (BOOL) adoptsInterface:(IDLInterface*)ifObj;

- functionNamed:(NSString*)name;
- (IDLAttribute*) attributeNamed:(NSString*)name;
- functionWithSelectorNamed:(NSString*)selector;
- (NSArray*) allFunctions;
- (NSMutableDictionary*) selectorList;
- (NSMutableDictionary*) methodList;

@end

@interface IDLInterface(Header)
- (NSString*)generateHeader;
@end
