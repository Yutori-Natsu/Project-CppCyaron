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
#ifndef CppCyaronGraph
#define CppCyaronGraph

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
#include<vector>
#include<algorithm>
#include"CppCyaronMath.h"
#pragma GCC optimize("O2")
using std::vector;
namespace CppCyaronGraphFunctions
{
    struct __Edge
    {
        int32_t __from,__to;
        __Edge(){__from=__to=0;}
        __Edge(int32_t __GivenFrom_Point,int32_t __GivenTo_Point){__from=__GivenFrom_Point;__to=__GivenTo_Point;}
        ~__Edge(){delete &__from;delete &__to;}
    };
    struct __WeightedEdge
    {
        int32_t __from,__to;
        uint64_t __weight;
        __WeightedEdge(){__from=__to=__weight=0;}
        __WeightedEdge(int32_t __GivenFrom_Point,int32_t __GivenTo_Point,uint64_t __GivenWeight){__from=__GivenFrom_Point;__to=__GivenTo_Point;__weight=__GivenWeight;}
        ~__WeightedEdge(){delete &__from;delete &__to;delete &__weight;}
    };
    struct __Graph
    {
        int32_t __vertex_amount;
        vector<__Edge>__edgelist;
        __Graph(){__vertex_amount=0;__edgelist.clear();}
        ~__Graph(){delete &__vertex_amount;__edgelist.clear();delete &__edgelist;}
        void add(__Edge __added_edge){__edgelist.push_back(__added_edge);}
        void SpawnGraph(int32_t __vertex_count,int32_t __edge_count,bool __self_edges,bool __repeat_edges,bool __directed)
        {
            using namespace CppCyaronMathFunctions;
            __vertex_amount=__vertex_count;
            vector<int>__vec[__vertex_count+1];
            for(int i=1;i<=__vertex_count;++i)__vec[i].push_back(i);
            for(int32_t i=1;i<=__edge_count;++i)
            {
                int32_t __from_vertex,__to_vertex;
                while(1)
                {
                    __from_vertex=rand_int32(1,__vertex_count);
                    __to_vertex=rand_int32(1,__vertex_count);
                    if(!__self_edges&&__from_vertex==__to_vertex)continue;
                    if(__self_edges&&__from_vertex==__to_vertex)
                    {
                        __edgelist.push_back(__Edge(__from_vertex,__to_vertex));
                        std::sort(__vec[__from_vertex].begin(),__vec[__from_vertex].end());
                        if(!__directed)
                        {
                            __edgelist.push_back(__Edge(__to_vertex,__from_vertex));
                            std::sort(__vec[__to_vertex].begin(),__vec[__to_vertex].end());
                        }
                        continue;
                    }
                    if(!__repeat_edges&&binary_search(__vec[__from_vertex].begin(),__vec[__from_vertex].end(),__to_vertex))
                    {
                        /*need to fix the problem of self edges*/
                        bool __added=0;
                        for(int j=0;j<__vec[__from_vertex].size();++j)
                        {
                            if(__vec[__from_vertex][j]!=j+1)
                            {
                                __added=1;
                                __to_vertex=j+1;
                                break;
                            }
                        }
                        if(!__added)continue;
                    }

                    __edgelist.push_back(__Edge(__from_vertex,__to_vertex));
                    __vec[__from_vertex].push_back(__to_vertex);
                    std::sort(__vec[__from_vertex].begin(),__vec[__from_vertex].end());
                    if(!__directed)
                    {
                        __edgelist.push_back(__Edge(__to_vertex,__from_vertex));
                        __vec[__to_vertex].push_back(__from_vertex);
                        std::sort(__vec[__to_vertex].begin(),__vec[__to_vertex].end());
                    }
                    break;
                }
            }
        }
    };
}

#endif // CppCyaronGraph
