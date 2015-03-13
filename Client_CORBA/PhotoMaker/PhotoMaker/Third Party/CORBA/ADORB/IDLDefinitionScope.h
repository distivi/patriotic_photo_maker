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

@class IDLDefinitionScope;

@protocol IDLDefinitionScope

- (id <IDLDefinition>)definitionNamed:(NSString*)name;
- (id <IDLDefinition>)localDefinitionNamed:(NSString*)name;
- (id <IDLDefinitionScope>) parentScope;
- (IDLDefinitionScope*) rootScope;
- (NSString*)name;
- (id <IDLDefinition>) definitionForNamePath:(NSString*)path;
- (id <IDLDefinition>) definitionForTypeId:(NSString*)typeId;
- (NSNumber*) enumValueForName:(NSString*)name andKey:(NSString*)key; 
@end

@interface IDLDefinitionScope : NSObject <IDLDefinitionScope, IDLDefinition, NSCoding>
{
    NSMutableDictionary* _definitionDict;
    id <IDLDefinitionScope> _parentScope;
    NSString* _scopeName;
    //NSMutableDictionary* _dict;
    NSString* _namePath;
    NSString* _prefix;
	NSMutableDictionary* _defineDict;
    NSMutableDictionary* _versions;
}

+ (IDLDefinitionScope*)rootScope;
+ (IDLDefinitionScope*)currentScope;

// #define and #undef 
- (void) defineValue:(NSString*)value forKey:(NSString*)key;
- (void) undefineValueForKey:(NSString*)key;
- (NSString*) definedValueForKey:(NSString*)key;

@end

