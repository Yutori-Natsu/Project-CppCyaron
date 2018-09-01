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
#ifndef CppCyaronMath
#define CppCyaronMath

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
#pragma GCC optimize("O2")
namespace CppCyaronMathFunctions
{
        //some math functions
    template<typename T> T gcd(T __a__gcd_parameter,T __b__gcd_parameter)
    {
        while(__b__gcd_parameter)
        {
            __a__gcd_parameter%=__b__gcd_parameter;
            std::swap(__a__gcd_parameter,__b__gcd_parameter);
        }
        return __a__gcd_parameter;
    }
    template<typename T> T abs(const T __parameter)
    {
        return __parameter>0?__parameter:-__parameter;
    }

    uint64_t __lastseed=1954136;

    uint64_t __rand_uint64(){return ((uint64_t)rand()<<62)+((uint64_t)rand()<<30)+((uint64_t)rand()<<15)+((uint64_t)rand());}
    int64_t __rand_int64(){return ((int64_t)rand()<<62)+((int64_t)rand()<<30)+((int64_t)rand()<<15)+((int64_t)rand());}
    uint32_t __rand_uint32(){return ((uint32_t)rand()<<30)+((uint32_t)rand()<<15)+((uint32_t)rand());}
    int32_t __rand_int32(){return ((int32_t)rand()<<30)+((int32_t)rand()<<15)+((int32_t)rand());}
    /**
    * These functions(rand_int32,rand_uint32,rand_int64,rand_uint64)
    * are used for spawning an integer in the range of [lower,upper].
    */
    int32_t rand_int32(int32_t __lower_limit=INT_MIN,int32_t __upper_limit=INT_MAX)
    {
        int32_t __random_value;
        srand(time(0)+(int32_t)ceil(clock()*100000)-__random_value^__lastseed);
        __random_value=(__lastseed^=__rand_int32());
        if(__upper_limit<__lower_limit)
        {
            fprintf(stderr,"Upper limit is less than the lower limit.\n");
            return 1;
        }
        if(__upper_limit-__lower_limit+1==0)return __random_value;
        return __lower_limit+abs(__random_value%(__upper_limit-__lower_limit+1));
    }
    /**
    * These functions(rand_int32,rand_uint32,rand_int64,rand_uint64)
    * are used for spawning an integer in the range of [lower,upper].
    */
    uint32_t rand_uint32(uint32_t __lower_limit=0,uint32_t __upper_limit=UINT_MAX)
    {
        uint32_t __random_value;
        srand(time(0)+(uint32_t)ceil(clock()*100000)-__random_value^__lastseed);
        __random_value=(__lastseed^=__rand_uint32());
        if(__upper_limit<__lower_limit)
        {
            fprintf(stderr,"Upper limit is less than the lower limit.\n");
            return 1;
        }
        if(__upper_limit-__lower_limit+1==0)return __random_value;
        return __lower_limit+abs(__random_value%(__upper_limit-__lower_limit+1));
    }
    /**
    * These functions(rand_int32,rand_uint32,rand_int64,rand_uint64)
    * are used for spawning an integer in the range of [lower,upper].
    */
    int64_t rand_int64(int64_t __lower_limit=LLONG_MIN,int64_t __upper_limit=LLONG_MAX)
    {
        int64_t __random_value;
        srand(time(0)+(int64_t)ceil(clock()*100000)-__random_value^__lastseed);
        __random_value=(__lastseed^=__rand_int64());
        if(__upper_limit<__lower_limit)
        {
            fprintf(stderr,"Upper limit is less than the lower limit.\n");
            return 1;
        }
        if(__upper_limit-__lower_limit+1==0)return __random_value;
        return __lower_limit+abs(__random_value%(__upper_limit-__lower_limit+1));
    }
    /**
    * These functions(rand_int32,rand_uint32,rand_int64,rand_uint64)
    * are used for spawning an integer in the range of [lower,upper].
    */
    uint64_t rand_uint64(uint64_t __lower_limit=0,uint64_t __upper_limit=ULLONG_MAX)
    {
        uint64_t __random_value;
        srand(time(0)+(uint64_t)ceil(clock()*100000)-__random_value^__lastseed);
        __random_value=(__lastseed^=__rand_uint64());
        if(__upper_limit<__lower_limit)
        {
            fprintf(stderr,"Upper limit is less than the lower limit.\n");
            return 1;
        }
        if(__upper_limit-__lower_limit+1==0)return __random_value;
        return __lower_limit+abs(__random_value%(__upper_limit-__lower_limit+1));
    }

    double rand_double(double __lower_limit,double __upper_limit)
    {
        std::default_random_engine e(time(0)+(uint32_t)ceil(clock()*100000)^__lastseed);
        std::uniform_real_distribution<double> u(__lower_limit,__upper_limit);
        __lastseed^=(int32_t)u(e);
        return u(e);
    }
}
#endif // CppCyaronMath
