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

@interface IDLEnum:IDLDefinition
{
	NSDictionary* _enumNames;
	NSString* _name;
	NSNumber* _value;
	NSArray* _strings;
}

+ enumWithDictionary:(NSDictionary*)dict name:(NSString*)aName;
+ enumWithDictionary:(NSDictionary*)dict;
- (NSString*)name;
- valueFromString:(NSString*)string;
- (NSNumber*) enumValueForKey:(NSString*)key; // raises exception
- (NSString*) stringFromValue:(NSNumber*)value;
// string -->number
- convertValue:aValue;
@end
