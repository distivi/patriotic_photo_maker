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

#define GIOP_MINOR 2
#define GIOP_MAJOR 1
#define GIOP_MAX_MINOR 2

@interface IDLGIOPVersion : NSObject 
{
    unsigned char _major;
    unsigned char _minor;
}

// Returns autoreleased instance with the default 'major' and 'minor' values
// The default version is 1.1 unless changed
+ (IDLGIOPVersion*)defaultIIOPVersion;

// Sets default GIOP version
+ (void) setDefaultIIOPVersion:(unsigned)major:(unsigned)minor;
// Sets maximum minor version
+ (void) setMaxMinorVersion:(unsigned)minor;

// Returns instance initialized with 'major' and 'minor'
// If minor > giop_max_minor then it is set to maximum minor version
- initVersion:(unsigned)major:(unsigned)minor;

// Calls 'initVersion:: with default 'major' and 'minor'
- init;

- (unsigned) majorVersion;
- (unsigned) minorVersion;
- (void) decodeVersion:coder;
- (void) encodeVersion:coder;
@end
