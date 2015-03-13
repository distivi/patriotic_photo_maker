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

#import "ORB.h"
#import "CORBAObject.h"
#import "CORBAException.h"
#import "IDLNameComponent.h"
#import "IDLGIOPVersion.h"

#import "IDLDefinition.h"
#import "IDLInterface.h"
#import "IDLDefinitionScope.h"
#import "IDLFunction.h"
#import "IDLAttribute.h"
#import "IDLValueType.h"
#import "IDLObject.h"
#import "IDLAnyObject.h"

#import "IDLServiceContext.h"
#import "IDLTaggedComponent.h"

#import "ORBNotificationCenter.h"

extern BOOL VXDecodeEmptyStringAsNil;  // = YES
// If YES the empty string @"" (encoded length = 1) is un-marshaled as nil, otherwise it is un-marshaled as empty string @""
// The string with encoded length = 0 always is un-marshaled to 'nil' string


extern BOOL VXEncodeNilStringAsEmpty;  // = YES
// If NO the 'nil' string is marshaled with encoded length = 0 (May be not compatible with other CORBA
// If YES the 'nil' string is marshaled as empty string @"" (encoded length = 1)


