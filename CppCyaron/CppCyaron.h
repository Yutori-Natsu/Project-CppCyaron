/*
    This Project "Project CppCyaron" is created for people
    who want to generate many data files without using
    "CyaRon" by LuoGu Dev-Team.
    This file is a part of "Project CppCyaron".

    you can redistribute it and/or modify it under the
    terms of the GNU General Public License as published by the
    Free Software Foundation; either version 3, or (at your option)
    any later version.

    Copyright(C) 2018~2018, CppCyaron Developers
*/
#ifndef CppCyaron
#define CppCyaron

#include"CppCyaronIO.h"
#include"CppCyaronMath.h"
#include"CppCyaronGraph.h"

extern void IOinit(const char* __file_prefix_cppcyaron, const int data_id);
extern void InputWrite(char* __output_string, ...);
extern void InputWriteln(char* __format_string, ...);
extern void OutputWrite(char* __output_string, ...);
extern void OutputWriteln(char* __format_string, ...);
extern void OutputGen(char* __dir);
extern void InputWriteGraph(__Graph __G);
template<typename T> extern T gcd(T __a__gcd_parameter, T __b__gcd_parameter);
template<typename T> extern T abs(const T __parameter);
#endif // CppCyaron
