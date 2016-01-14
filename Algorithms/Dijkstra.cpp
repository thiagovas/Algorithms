/*
     Feito por Thiago Vieira <thiagovieiraas@gmail.com>
     Algoritmo de Dijkstra, ele calcula a menor distância entre dois pontos.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> PII;


/*
    O parâmetro grafo é uma lista de adjacência. Para cada nó, tenho um vector de pairs, cada pair representa uma aresta,
    onde o primeiro elemento do pair é o peso da aresta e o segundo elemento é o nó conectado.
    O retorno da função é o custo mínimo para sair do nó start para chegar em end.
*/
int Dijkstra(vector<vector<PII > > *grafo, int start, int end)
{
    priority_queue<PII, vector<PII >, greater<PII > > nodes;
    PII atual;
    vector<int> pesos(grafo->size(), INF);
    
    pesos[start] = 0;
    nodes.push(make_pair(0, start));
    
    while(!nodes.empty())
    {
        atual = nodes.top();
        nodes.pop();
        
        if(atual.second == end) break;
        
        for(vector<PII>::iterator it = (*grafo)[atual.second].begin(); it != (*grafo)[atual.second].end(); it++)
            if(pesos[it->second] == -1 || pesos[it->second] > it->first+pesos[atual.second])
            {
                pesos[it->second] = it->first+pesos[atual.second];
                nodes.push(make_pair(pesos[it->second], it->second));
            }
    }
    
    if(pesos[end] != INF)
        return pesos[end];
    
    return -1;
}
