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
using std::pair;
using std::cout;
using std::endl;
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
        void __UnguardedSpawn(int32_t __v,int32_t __e,bool __se)
        {

        }
        void SpawnGraph(int32_t __vertex_count,int32_t __edge_count,bool __self_edges,bool __repeat_edges,bool __directed)//Directed
        {
            __edgelist.clear();
            if(__repeat_edges){__UnguardedSpawn(__vertex_count,__edge_count,__self_edges);return;}
            if(pow(__vertex_count,1.5)<=__edge_count)
            {
                if(__directed)
                {
                    pair<int32_t,int32_t>__lis[__vertex_count*__vertex_count+10];
                    int __offset=0;
                    for(int i=1;i<=__vertex_count;++i)
                        for(int j=1;j<=__vertex_count;++j)
                            if(__self_edges)__lis[(i-1)*__vertex_count+j]=std::make_pair(i,j);
                            else if(i^j)__lis[(i-1)*__vertex_count+j-__offset]=std::make_pair(i,j);
                            else ++__offset;
                    random_shuffle(__lis+1,__lis+__vertex_count*__vertex_count-__offset+1);
                    for(int i=1;i<=__edge_count;++i)
                    {
                        __Edge __ed;
                        __ed.__from=__lis[i].first;
                        __ed.__to=__lis[i].second;
                        add(__ed);
                    }
                    __vertex_amount=__vertex_count;
                    return;
                }
                else
                {

                }
            }
            int __rem=__edge_count;
            int32_t __a=rand_int32(1,__vertex_count),__b=rand_int32(1,__vertex_count);
            vector<int32_t>lis[__vertex_count+3];
            while(__rem>0)
            {
                __a=rand_int32(1,__vertex_count),__b=rand_int32(1,__vertex_count);
                while(find(lis[__a].begin(),lis[__a].end(),__b)!=lis[__a].end()||((__self_edges)?0:__a==__b)||((__directed)?0:(find(lis[__b].begin(),lis[__b].end(),__a)!=lis[__b].end())))
                    __a=rand_int32(1,__vertex_count),__b=rand_int32(1,__vertex_count);
                lis[__a].push_back(__b);
                if(!__directed)lis[__b].push_back(__a);
                --__rem;
            }
            __vertex_amount=__vertex_count;
            if(!__directed)
                for(int32_t i=1;i<=__vertex_count;++i)
                    for(int32_t j=0;j<lis[i].size();++j)
                        add((__Edge){i,lis[i][j]});
            else
            {
                //needed to be edited later
            }
        }
        void print()
        {
            cout<<__vertex_amount<<" "<<__edgelist.size()<<endl;
            for(int i=0;i<__edgelist.size();++i)cout<<__edgelist[i].__from<<" "<<__edgelist[i].__to<<endl;
            return;
        }
    };


#endif // CppCyaronGraph
