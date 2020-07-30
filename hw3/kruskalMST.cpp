#include <bits/stdc++.h>
using namespace std;
class Graph 
{
	public:
	long long int V,E;
	vector < pair <long long int , pair <long long int,long long int> > > edges;
	
	Graph(long long int V, long long int E);
	void addEdge(long long int u, long long int v, long long int w);
	void kruskalMST(long long int k);
};

Graph::Graph(long long int V, long long int E)
{
	this->V=V;
	this->E=E;
}
void Graph::addEdge(long long int u, long long int v, long long int w)
{
	edges.push_back( { w,{u,v} } );
}
struct sets
{
	long long int *parent, *rank;
	long long int n;
	
	sets(long long int n)
	{
		this->n=n;
		parent  = new long long int[n+1];
		rank 	= new long long int[n+1];
		for(long long int i=0;i<=n;i++) 
		{
			rank[i]=0;
			parent[i]=i;
		}
	}
	
	long long int search(long long int u)
	{
		if(u!=parent[u])
		{
			parent[u] = search(parent[u]);
		}
		return parent[u];
	}
	
	void Union(long long int x, long long int y)
	{
		x = search(x);
		y = search(y);
		
		if(rank[x]>rank[y])
		{
			parent[y]=x;
		}
		else
		{
			parent[x]=y;
		}
		
		if(rank[x]==rank[y])
			rank[y]++;
	}
};

void Graph::kruskalMST(long long int k)
{
	sort(edges.begin(),edges.end());
	 sets s(V);
	 vector<long long int> weights;
	 vector<pair<long long int,pair<long long int, long long int>>>::iterator i;
	 long long int e=0;
	 for(i=edges.begin();i!=edges.end();i++)
	 {
	 	long long int u = i->second.first;
	 	long long int v = i->second.second;
	 	
	 	long long int setU = s.search(u);
	 	long long int setV = s.search(v);
	 	
	 	if(setU != setV)
	 	{
	 		weights.push_back(i->first);
	 		s.Union(setU,setV);
	 		e++;
		 }
		 if(e==V-1)
		 {
		 	break;
		 }
	 }
	 sort(weights.begin(),weights.end());
	 cout << weights[k-1] <<  endl;	 
}

int main()
{
	long long int n,m,k;
	long long int u,v,w;
	cin >> n >> m >> k; 
	Graph g(n,m);
	for(long long int i=0;i<m;i++)
	{
		cin >> u>> v >> w;
		g.addEdge(u-1,v-1,w);
		//cout << "Added" << endl;
	}
	g.kruskalMST(k);
	
	return 0;

}
