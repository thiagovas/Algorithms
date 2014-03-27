#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <stack>
#include <locale>
#include <cstdio>
#include <cctype>
using namespace std;

#define EPS 1e-7
#define INF 2147483000
#define MAX 1024 //5000

class Dinic{
	private:
		vector<vector<int> > adj, graph;

	public:
		Dinic(){}
		Dinic(int n);
		void init(int n);
		void clear();
		void addEdge(int from, int to, int capacity);
		int flow(int source, int sink);
};

Dinic::Dinic(int n)
{ this->init(n); }

void Dinic::init(int n)
{
	this->graph.clear();
	this->adj.clear();
	this->adj.resize(n);
	this->graph.resize(n, vector<int>(n, 0));
}

void Dinic::clear()
{
	this->graph.clear();
	this->adj.clear();
}

void Dinic::addEdge(int from, int to, int capacity)
{
	if(this->graph[from][to]==0) this->adj[from].push_back(to);
	this->graph[from][to]+=capacity;
}

int Dinic::flow(int source, int sink)
{
	int pathCap=0, atual=0, bottleneck=0;
	queue<int> q;
	vector<int> previous(graph.size(), -1);
	
	while(true)
	{
		q.push(source);
		previous.clear();
		previous.resize(graph.size(), -1);
		previous[source] = -2;
		
		while(!q.empty() && previous[sink] == -1)
		{
			atual = q.front();
			q.pop();
			for(unsigned int i = 0; i < this->adj[atual].size(); i++)
				if(previous[adj[atual][i]] == -1 && this->graph[atual][adj[atual][i]])
				{ q.push(this->adj[atual][i]); previous[adj[atual][i]] = atual; }
		}
		
		if(previous[sink] == -1) break;
		while(!q.empty()) q.pop();
		
		for(int i = 0; i < this->graph.size(); i++) if(this->graph[i][sink] && previous[i] != -1)
		{
			bottleneck = this->graph[i][sink];
			for(int v = i, u = previous[v]; u >= 0; v = u, u = previous[v])
				bottleneck = min(bottleneck, this->graph[u][v]);
			
			if(!bottleneck) continue;
			
			this->graph[i][sink] -= bottleneck;
			this->graph[sink][i] += bottleneck;
			
			for(int v = i, u = previous[v]; u >= 0; v = u, u = previous[v])
			{
				this->graph[u][v] -= bottleneck;
				this->graph[v][u] += bottleneck;
			}
			pathCap+=bottleneck;
		}
	}
	return pathCap;
}
