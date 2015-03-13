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

@class IDLGIOPVersion, IDLTaggedComponent;

@interface IDLProfileBody : NSObject
{
    IDLGIOPVersion* _iiop_version;
    NSString* _host;
    unsigned short _port;
    NSData* _object_key;
    NSMutableArray* _components;
}

+ profileWith:version host:host port:(unsigned)port objectID:(NSData*)objID;
- initWithCorbaloc:(NSString*)corbaloc;
+ profileWithCorbaloc:(NSString*)corbaloc;
- (NSString*) hostName;
- (unsigned short) portNumber;
- (NSData*) objectID;
- (IDLGIOPVersion*) iiopVersion;
- (NSNumber*)port;

- (NSArray*) components;
- (void) addComponent:(IDLTaggedComponent*)component;
- (IDLTaggedComponent*) componentWithTag:(unsigned)tag;

@end
