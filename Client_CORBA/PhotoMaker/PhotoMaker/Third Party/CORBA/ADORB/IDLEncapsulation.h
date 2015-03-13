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
#import "IDLStream.h"

@class IDLOctetStream;

@interface IDLEncapsulation : IDLStream
{
    IDLEncapsulation* _parentStream;
    NSMutableDictionary* _ref;
    long _location; // location of the 1-st byte of data in parent stream
}

+ encapsulationWithData:(NSMutableData*)data; // in-stream
+ encapsulation; // out-stream
- initWithStreamData:(NSMutableData*)data;
- init;

- (void) setParentStream:stream location:(long)location;
- (void) encodeIndirection:(long)location;
- (IDLDefinition*) definitionWithLocation:(long)location;
- (void) registerDefinition:(IDLDefinition*)def forLocation:(long)location;
- (void) registerDefinition:(IDLDefinition*)def;
- (void) registerLocation:(long)location forDefinition:(IDLDefinition*)def;
- (long) locationForDefinition:(IDLDefinition*)def;

@end
