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
#import "CORBACoding.h"

@class IDLGIOPVersion, VXMessage;

@interface IDLStream : NSObject <CORBACoder,CORBADecoder>
{
    NSMutableData* _data;
	NSStringEncoding _stringEncoding;
	NSStringEncoding _wstringEncoding;
    unsigned int _cursor;
    struct _flags{
        unsigned _offset:8;
        unsigned _major:8;
        unsigned _minor:8;
        unsigned _isOutStream:1;
        unsigned _shouldSwap:1;
        unsigned _byteOrderInFirstOctet:1;
        unsigned _needsAlign:1;
        unsigned inChunk:1;
        unsigned useChunks:1;
        unsigned reserved:2;
    }_flags;
}

- init; // Create Out stream
- initWithOffset:(unsigned)offset;
- initWithStreamData:(NSMutableData*)data offset:(unsigned)offset;
+ octetStream;
+ octetStreamWithOffset:(unsigned)offset;
+ octetStreamWithData:(NSMutableData*)data offset:(unsigned)offset;

- initWithStreamData:(NSMutableData*)data; // Create In stream
+ octetStreamWithData:(NSMutableData*)data; 
+ inputStream; // In stream
+ inputStreamWithOffset:(unsigned)offset;

- (void) reset;
// 0 - BigEndian, 1 - LittleEndian
- (void) useByteOrderFromFirstOctet;
- (BOOL) setByteOrder:(unsigned)order; // 0 - BigEndian, 1 - LittleEndian
- (void) peepObject:(id*)object;
- (void) peepStruct:(id*)object usingObjectCoder:coder;
- (void) decodeStruct:(id*)object usingObjectCoder:coder objectClass:objectClass;
- (void) decodeObject:(id*)object usingClass:objectClass;

- (void) encodeRawData:(NSData*)stream;
- (BOOL) decodeRawData:(NSData**)stream length:(long)length;
- (unsigned) length;
- (long) location; // for sizeof(long)
- (NSData*) data;
- (void) encodeLong:(long)value atOffset:(unsigned)offset;

- (BOOL) isInputStream;
- (void) _alignTo:(unsigned int)b;

- (void) setNeedsAlign:(BOOL)flag;

- (void) setIIOPVersion:(IDLGIOPVersion*)version;

- (void) registerObject:object withLocation:(long)location;
- objectWithLocation:(long)location;

- (VXMessage*)message;
- (void) setMessage:(VXMessage*)message;
- invocationObject;

- (NSStringEncoding) wstringEncoding;
- (NSStringEncoding) stringEncoding;
- (void) setStringEncoding:(NSStringEncoding)encoding;
- (void) setWStringEncoding:(NSStringEncoding)encoding;

- (unsigned) cursorPosition;
- (void)setCursorPosition:(unsigned)position;
@end

@interface IDLStream(Private)
- (void) _swapBytes:(unsigned char*)buffer length:(unsigned)length;
- (void) _alignCursorTo:(unsigned int)b;
- (BOOL) isAtEOF:(unsigned int)b;
@end

extern BOOL VXDecodeEmptyStringAsNil; 
// If YES the empty string @"" (length = 1) is un-marshaled as nil, otherwise it is un-marshaled as empty string @""
// The string with length = 0 always is un-marshaled to 'nil' string


extern BOOL VXEncodeNilStringAsEmpty; 
// If NO the 'nil' string is marshaled with length = 0 (May be not compatible with other CORBA
// If YES the 'nil' string is marshaled as empty string @""

extern NSStringEncoding VXWStringTransmissionEncoding; // Default wstring encoding
extern NSStringEncoding VXStringTransmissionEncoding; // Default string encoding (UTF-8)

