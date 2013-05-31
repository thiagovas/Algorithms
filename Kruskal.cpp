#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 101

int p[MAX];

void initUnionFind()
{
    for(int i = 0; i < MAX; i++)
        p[i] = i;
}

int Find(int a)
{
    return p[a] == a ? a : p[a] = Find(p[a]);
}

void Union(int a, int b)
{
    p[a] = Find(b);
}

/*
    Kruskal.
    O set do parâmetro é composto pelo peso da aresta mais um pair que tem os valores dos nós. <peso, <nó1, nó2>>
    O set do retorno contém pairs, cada pair representa uma aresta. <nó1, nó2>
*/
set<pair<int, int> > Kruskal(set<pair<int, pair<int, int> > > *grafo)
{
    set<pair<int, int> > result;
    
    for(set<pair< int, pair<int, int> > >::iterator it = grafo->begin(); it != grafo->end(); it++)
    {
        if(Find((it->second).first) != Find((it->second).second))
        {
            Union(Find(it->second.first), Find(it->second.second));
            result.insert(make_pair((it->second).first, (it->second).second));
        }
    }
    return result;
}
