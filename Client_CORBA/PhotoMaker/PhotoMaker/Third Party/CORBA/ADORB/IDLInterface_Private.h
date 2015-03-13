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

#import "IDLInterface.h"
#import "IDLDefinitionScope_Private.h"

@interface IDLInterface(Private) <IDLScopePrivate>
+ interface:(NSDictionary*)functions inherited:(NSArray*)namesList;
- initWith:(NSDictionary*)functions inherited:(NSArray*)namesList;
- (void) setName:(NSString*)aName;
- (void) setIsAbstract:(BOOL)flag;
- (void) setIsLocal:(BOOL)flag;
- (NSArray*) allKeys;
- (void) setInheritanceList:(NSArray*)aList;

- (void) resetSelectors;

@end

@interface IDLInterface(CORBACoding)

- interfaceConnection;
- (void) setInterfaceConnection:aConn;

@end
