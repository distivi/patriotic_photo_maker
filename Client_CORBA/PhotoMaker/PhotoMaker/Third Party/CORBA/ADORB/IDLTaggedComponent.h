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

#define TAG_ORB_TYPE 		    0
#define TAG_CODE_SETS 		    1
#define TAG_POLICIES                2
#define TAG_ALTERNATE_IIOP_ADDRESS  3
#define TAG_ASSOCIATION_OPTIONS     13
#define TAG_SEC_NAME                14
#define TAG_SPKM_1_SEC_MECH         15
#define TAG_SPKM_2_SEC_MECH         16
#define TAG_KerberosV5_SEC_MECH     17
#define TAG_CSI_ECMA_Secret_SEC_MECH 18
#define TAG_CSI_ECMA_Hybrid_SEC_MECH 19
#define TAG_SSL_SEC_TRANS           20
#define TAG_CSI_ECMA_Public_SEC_MECH 21
#define TAG_GENERIC_SEC_MECH        22
#define TAG_JAVA_CODEBASE           25
#define TAG_TRANSACTION_POLICY		26
#define TAG_MESSAGE_ROUTERS			30
#define TAG_OTS_POLICY				31
#define TAG_INV_POLICY				32
#define TAG_CSI_SEC_MECH_LIST		33
#define TAG_NULL_TAG				34
#define TAG_SECIOP_SEC_TRANS		35
#define TAG_TLS_SEC_TRANS			36
#define TAG_ACTIVITY_POLICY			37
#define TAG_INET_SEC_TRANS			123

#define TAG_COMPLETE_OBJECT_KEY     5
#define TAG_ENDPOINT_ID_POSITION    6
#define TAG_LOCATION_POLICY         12
#define TAG_DCE_STRING_BINDING      100
#define TAG_DCE_BINDING_NAME        101
#define TAG_DCE_NO_PIPES            102
#define TAG_DCE_SEC_MECH            103


@interface IDLTaggedComponent : NSObject
{
    unsigned _tag;
    NSData* _component_data;
    id _component;
}

- initWithTag:(unsigned)tag component:component;
- init;

// The ORB must know how to marshal and un-marshal a particular tagged component
// This method sets an IDL path to use for marshaling and un-marshaling
// The already known tags are TAG_ORB_TYPE, TAG_CODE_SETS and TAG_ALTERNATE_IIOP_ADDRESS
// If a tag is not registered the tagged component with this tag is not un-marshaled
// For a local object a tagged component added to the object's profile must be registered
+ (void) registerComponentTag:(unsigned)tag withIDLPath:(NSString*)path;

- (unsigned) componentTag;

- component;

+ codeSetsComponent;
- (unsigned)charEncoding;
- (unsigned)wcharEncoding;
+ (void) setNativeCharCode:(unsigned)code;
+ (void) setTransmissionCharCodes:(NSArray*)array;

@end
