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
#import "IDLStruct.h"

enum _reply_status {
    GIOP_NoException,
    GIOP_UserException,
    GIOP_SystemException,
    GIOP_LocationForward,
    GIOP_LocationForwardPerm,
    GIOP_NeedsAddressingMode
};

typedef enum completion_status {
    COMPLETED_YES,
    COMPLETED_NO,
    COMPLETED_MAYBE
} CORBA_CompletionStatus;

@interface IDLException : IDLStruct
{
}

+ exceptionWithName:(NSString*)aName members:(NSArray*)members;
+ exceptionWithStruct:(IDLStruct*)obj andName:(NSString*)name;

+ (NSDictionary*) systemInfoForException:(NSException*)exc;
+ (NSDictionary*) systemInfoWithName:(NSString*)excName;
+ (NSDictionary*) systemExceptionInfo:(NSString*)corbaName minor:(long)minor completed:(CORBA_CompletionStatus)cs;

@end

extern NSString* IDLExceptionTypeKey;
extern NSString* IDLExceptionIDKey;
extern NSString* IDLExceptionKey;
extern NSString* IDLMinorCodeKey;
extern NSString* IDLCompletionStatusKey;

