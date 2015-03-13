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
#import "IDLDefinition_Private.h"
#import "IDLNamedDefinition.h"
#import "IDLDefinitionScope_Private.h"
#import "IDLEnum.h"
#import "IDLArgument.h"
#import "IDLFunction_Private.h"
#import "IDLInterface_Private.h"
#import "IDLAttribute_Private.h"
#import "IDLSequence.h"
#import "IDLPrimitive.h"
#import "IDLStruct.h"
#import "IDLStructMember.h"
#import "IDLException.h"
#import "IDLOctetStream.h"
#import "IDLEncapsulation.h"
#import "IDLOctetSequence.h"
#import "IDLOctetArray.h"
#import "IDLUnion.h"
#import "IDLSwitchCase.h"
#import "IDLParser.h"
#import "IDLAny.h"
#import "IDLTypedef.h"
#import "IDLNative.h"
#import "IDLValueType_Private.h"
#import "IDLReference.h"
#import "IDLLink.h"
#import "IDLArray.h"
#import "IDLArrayIdentifier.h"
#import "IDLTypedValue.h"

extern NSString* CORBADefinitionException;
extern NSString* CORBANotImplemented;
extern NSString* IDLInvalidArgumentException;