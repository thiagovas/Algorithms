/*
     Feito por Thiago Vieira <thiagovieiraas@gmail.com>
     Algoritmo de Dijkstra, ele calcula a menor distância entre dois pontos.
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

/*
    O parâmetro grafo é uma lista de adjacência. Para cada nó, tenho um vector de pairs, cada pair representa uma aresta,
    onde o primeiro elemento do pair é o peso da aresta e o segundo elemento é o nó conectado.
    O retorno da função é o custo mínimo para sair do nó start para chegar em end.
*/
long long int dijkstra(vector<vector<pair<int, int> > > *grafo, int start, int end)
{
    priority_queue<pair<int, long long int>, vector<pair<int, long long int> >, greater<pair<int, long long int> > > q;
    pair<int, int> atual;
    long long int *pesos = (long long int*)calloc(grafo->size(), sizeof(long long int));
    long long int retorno = -1, soma;
    
    for(unsigned int i = 0; i < grafo->size(); i++)
        pesos[i] = -1;
    pesos[start] = 0;
    q.push(make_pair(0, start));
    
    while(!q.empty())
    {
        atual = q.top();
        q.pop();
        
        if(atual.second == end)
        {
            retorno = pesos[atual.second];
            break;
        }
        soma = pesos[atual.second];
        
        for(vector<pair<int, int> >::iterator i = (*grafo)[atual.second].begin(); i != (*grafo)[atual.second].end(); i++)
        {
            if(pesos[i->second] == -1) q.push(make_pair(soma+(i->first), i->second));
            
            if(((pesos[i->second] > soma+(i->first)) && (pesos[i->second] != 0)) || pesos[i->second] == -1)
                pesos[i->second] = soma+(i->first);
        }
    }
    free(pesos);
    return retorno;
}
