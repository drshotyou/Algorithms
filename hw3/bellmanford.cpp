#include<bits/stdc++.h>

using namespace std;
bool ans;
bool negFound=false;
long long int mostVal = INT_MAX*(-1);
vector<bool> findings;
vector<long long int> values;

struct Edge
{
	long long int u,v,w;
};

class Graph
{	
	public:
		
	long long int V,E;
	struct Edge* edges;
	Graph(long long int v, long long int e);
	void addEdge(long long int i,long long int u, long long int v,long long int w);
	bool BellmanFord(long long int sP);
	//int size=0;
};

Graph::Graph (long long int v, long long int e)
{
	this->V=v;
	this->E=e;
	this->edges = new Edge[e];
}
void Graph::addEdge(long long int i,long long int u, long long int v, long long int w)
{
	this->edges[i].u=u;
	this->edges[i].v=v;	
	this->edges[i].w=w;
	
}

bool Graph::BellmanFord(long long int sP)
{
	long long int V = this->V;
	long long int E = this->E;
	long long dist[V];
	
	for(long long int i=0;i<V;i++)
	{
		dist[i] = INT_MAX;
	}
	dist[sP]=0;
	for(long long int i= 1; i<=V-1; i++)
	{
		for(long long int j=0; j<E;j++)
		{
			long long int u = this->edges[j].u;
			long long int v = this->edges[j].v;
			long long int w = this->edges[j].w*(-1);
			//cout << u << " "  << v << " dist:" << dist[u]+w << " " << dist[v] << endl;
			if(dist[u] != INT_MAX && (dist[u] + w) < dist[v])
			{
				
				//cout << dist[u]+w << " " << dist[v] << endl;
				dist[v] = dist[u] + w;
			}
			
		}
		//print(dist,sP);
		//cout << endl;
	}
	//cout << endl << endl;
	negFound=false;
	
	for(long long int i=0;i<E;i++)
	
	{
		long long int u = this->edges[i].u;
		long long int v = this->edges[i].v;
		long long int w = this->edges[i].w*(-1);
		//cout << u << " "  << v << " dist u u+w v:" << dist[u] << " " << dist[u]+w << " " << dist[v] << endl;
		if(dist[u]!=INT_MAX && (dist[u]+w) < dist[v])
		{
			//cout << "Negative path exists" << endl;
			negFound=true;
		}
		
		
	}
	if (negFound==false)
	{
		long long int total = 0;
		for(long long int i= 0;i<V;i++)
		{
			if(dist[i]<total)
			{
				total=dist[i];
			}
		}
		cout << total*(-1) << endl;
	}
	return negFound;
	
}
int main()
{
	long long int n, m;
	cin >> n >> m;
	long long int u,v,w;
	//take in account extras from additional core vertex
	Graph g(n+1,n+m);
	
	for(long long int i=0;i<m;i++)
	{
		cin >> u >> v >> w;
		g.addEdge(i,u-1,v-1,w);	
	}
	for(long long int i=0;i<n;i++)
	{
		g.addEdge(i+m,n,i,0);
	}
	ans = g.BellmanFord(n);
	if(ans)
	{
		cout << "INF" << endl;
	}
	
	
	return 0;
}
