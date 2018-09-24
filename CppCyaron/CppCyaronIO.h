/*
    This Project "Project CppCyaron" is created for people
    who want to generate many data files without using
    "CyaRon" by LuoGu Dev-Team.
    This file is a part of "Project CppCyaron".

    you can redistribute it and/or modify it under the
    terms of the GNU General Public License as published by the
    Free Software Foundation; either version 3, or (at your option)
    any later version.

    Copyright(C) 2018~2018, GD_ItzABC(Kirisame_Marisa_ sometimes)
*/
#ifndef CppCyaronIO
#define CppCyaronIO

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<ctime>
#include<cstdarg>
#include<climits>
#include<random>
#include"CppCyaronGraph.h"
#pragma GCC optimize("O2")

        //basic IO operations
    #define __NO_PARAMETER (int)-512
    FILE * __input_pointer, * __output_pointer, * __input_tempfile_pointer;
    char __current_input_filename[105];
    char __current_output_filename[105];
    void __IO_init_cppcyaron()
    {
        __input_pointer=fopen(__current_input_filename,"a+");
        __output_pointer=fopen(__current_output_filename,"a+");
        __input_tempfile_pointer=fopen("input.tmp","a+");
    }
    void __IO_close_cppcyaron()
    {
        fclose(__input_pointer);
        fclose(__output_pointer);
        fclose(__input_tempfile_pointer);
    }
    void IOinit(const char * __file_prefix_cppcyaron,const int data_id=__NO_PARAMETER)
    {
        if(__input_pointer!=NULL)fclose(__input_pointer);
        if(__output_pointer!=NULL)fclose(__output_pointer);
        if(__input_tempfile_pointer!=NULL)fclose(__input_tempfile_pointer);
        if(strlen(__file_prefix_cppcyaron)>=32)
        {
            fprintf(stderr,"Parameter String is too long.\n");
            return;
        }

        char __input_name[105],__output_name[105];
        memset(__input_name,0,sizeof(char));
        memset(__output_name,0,sizeof(char));
        strcpy(__input_name,__file_prefix_cppcyaron);
        strcpy(__output_name,__file_prefix_cppcyaron);
        if(data_id==__NO_PARAMETER)
        {
            strcat(__input_name,".in");
            strcat(__output_name,".out");
        }
        else
        {
            char __input_suffix[15]="",__output_suffix[15]="";
            sprintf(__input_suffix,"%d.in",data_id);
            sprintf(__output_suffix,"%d.out",data_id);
            strcat(__input_name,__input_suffix);
            strcat(__output_name,__output_suffix);
        }
        strcpy(__current_input_filename,__input_name);
        strcpy(__current_output_filename,__output_name);

        __input_pointer=fopen(__current_input_filename,"w");
        __output_pointer=fopen(__current_output_filename,"w");
        __input_tempfile_pointer=fopen("input.tmp","w");
        fclose(__input_pointer);
        fclose(__output_pointer);
        fclose(__input_tempfile_pointer);
    }
    void InputWriteln(char * __format_string, ...)
    {
        if(strlen(__format_string)>=512)
        {
            fprintf(stderr,"Output String too long.\n");
            return;
        }
        __IO_init_cppcyaron();
        char __output_string[1005];
        memset(__output_string,0,sizeof(char));
        strcpy(__output_string,__format_string);
        strcat(__output_string,"\n");
        va_list __vaPlist=NULL;
        va_start(__vaPlist,__output_string);
        vfprintf(__input_pointer,__output_string,__vaPlist);
        vfprintf(__input_tempfile_pointer,__output_string,__vaPlist);
        __IO_close_cppcyaron();
    }
    void OutputWriteln(char * __format_string, ...)
    {
        if(strlen(__format_string)>=512)
        {
            fprintf(stderr,"Output String too long.\n");
            return;
        }
        __IO_init_cppcyaron();
        char __output_string[1005];
        memset(__output_string,0,sizeof(char));
        strcpy(__output_string,__format_string);
        strcat(__output_string,"\n");
        va_list __vaPlist=NULL;
        va_start(__vaPlist,__output_string);
        vfprintf(__output_pointer,__output_string,__vaPlist);
        vfprintf(__input_tempfile_pointer,__output_string,__vaPlist);
        __IO_close_cppcyaron();
    }
    void InputWrite(char * __output_string, ...)
    {
        __IO_init_cppcyaron();
        va_list __vaPlist=NULL;
        va_start(__vaPlist,__output_string);
        vfprintf(__input_pointer,__output_string,__vaPlist);
        vfprintf(__input_tempfile_pointer,__output_string,__vaPlist);
        __IO_close_cppcyaron();
    }
    void OutputWrite(char * __output_string, ...)
    {
        __IO_init_cppcyaron();
        va_list __vaPlist=NULL;
        va_start(__vaPlist,__output_string);
        vfprintf(__output_pointer,__output_string,__vaPlist);
        vfprintf(__input_tempfile_pointer,__output_string,__vaPlist);
        __IO_close_cppcyaron();
    }
    void InputWriteGraph(__Graph __G)
    {
        __IO_init_cppcyaron();
        fprintf(__input_pointer,"%d\n",__G.__vertex_amount);
        for(int i=0;i<__G.__edgelist.size();++i)
            fprintf(__input_pointer,"%d %d\n",__G.__edgelist[i].__from,__G.__edgelist[i].__to);
        fprintf(__input_tempfile_pointer,"%d\n",__G.__vertex_amount);
        for(int i=0;i<__G.__edgelist.size();++i)
            fprintf(__input_tempfile_pointer,"%d %d\n",__G.__edgelist[i].__from,__G.__edgelist[i].__to);
        __IO_close_cppcyaron();
    }
    /**
     *  To use this function (OutputGen), please prove that
     *  your output-generator program can read input data
     *  from a file named "input.tmp" and is able to write
     *  a file named "output.tmp"
    */
    void OutputGen(char * __dir)
    {
        system(__dir);
        FILE * __output_tempfile_pointer=fopen("output.tmp","r");
        FILE * __output_file_pointer=fopen(__current_output_filename,"a+");
        char __tempfile_character=1;
        while((__tempfile_character=getc(__output_tempfile_pointer))!=EOF)
            putc(__tempfile_character,__output_file_pointer);
        fclose(__output_tempfile_pointer);
        fclose(__output_file_pointer);
        system("del input.tmp");
        system("del output.tmp");
    }

#endif // CppCyaronIO
