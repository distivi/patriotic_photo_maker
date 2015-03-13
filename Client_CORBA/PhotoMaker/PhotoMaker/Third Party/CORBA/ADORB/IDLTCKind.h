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

enum _TCKind {                               // PIDL
    tk_null,
    tk_void,
    tk_short,
    tk_long,
    tk_ushort,
    tk_ulong, 
    tk_float,
    tk_double,
    tk_boolean,
    tk_char, 
    tk_octet,
    tk_any,
    tk_TypeCode,
    tk_Principal,
    tk_objref, 
    tk_struct,
    tk_union,
    tk_enum,
    tk_string, 
    tk_sequence,
    tk_array,
    tk_alias,
    tk_except,
    tk_longlong,
    tk_ulonglong,
    tk_longdouble,
    tk_wchar,
    tk_wstring,
    tk_fixed,
    tk_value,
    tk_value_box,
    tk_native,
    tk_abstract_interface,
    tk_local_interface
};

typedef enum _TCKind TCKind;
