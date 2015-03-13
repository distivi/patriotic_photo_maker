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

@class IDLInterface,IDLException;

@interface IDLFunction:IDLDefinition
{
    NSString* _name;
    NSArray* _args;
    IDLDefinition* _returnType;
    IDLInterface* _interfaceObject;
    NSArray* _exceptionList;
    NSArray* _contextList;
    NSString* _selector;
    NSString* _objCTypeString;
    void* _signature;
    void* _data;
    BOOL _isFactory;
}

- (IDLInterface*)interfaceObject;
- (IDLDefinition*) returnType;
- (NSArray*) arguments;

- (BOOL) isOneWay;
- (BOOL) isFactory;

@end

@interface IDLFunction(Selectors)
- (NSString*) selectorName;
- (void) setSelector:(SEL)selector;
- (void) setSelectorName:(NSString*)selName;
@end
