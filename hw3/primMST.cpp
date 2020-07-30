
#include<bits/stdc++.h> 
# define INF 0x3f3f3f3f
using namespace std;

class Graph
{
	long long int nV;
	long long int mE;
	list<pair<long long int,long long int>> *adj;
	//long long int smallestWeight;
	public:
	Graph(long long int nV,long long int mE);
	void addEdge(long long int u, long long int v,long long int w);
	void primMST(long long int k);
};

Graph::Graph(long long int nV,long long int mE)
{
	this->nV=nV;
	this->mE=mE;
	adj = new list < pair<long long int,long long int> >[mE*mE];
}
void Graph::addEdge(long long int u, long long int v, long long int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

void Graph::primMST(long long int k)
{
	priority_queue < pair<long long int,long long int>, vector< pair<long long int,long long int> > , greater<pair<long long int,long long int> > > priorQueue;
	
	long long int src=0;
	
	vector<long long int> key(nV+1,INF);
	vector<long long int> parent(nV+1, -1);
	vector<bool> inMST(nV+1, false);
	vector<long long int> weights;
	priorQueue.push(make_pair(0,src));
	key[src]=0;
	
	while(!priorQueue.empty())
	{
		long long int u = priorQueue.top().second;
		priorQueue.pop();
		
		inMST[u]=true;
		
		list<pair<long long int,long long int>>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			long long int v=(*i).first;
			long long int weight =(*i).second;
			
			if(inMST[v] == false && key[v] > weight)
			{
				
				//weights.push_back(weight);
				
				//cout << (*i).second  << "  " << weight << endl;
				key[v]=weight;
				priorQueue.push(make_pair(key[v],v));
				parent[v]= u;
			}
		}
	}
	//sort(weights.begin(),weights.end());
	

	/*for (int i = 1; i < nV; ++i) 
	{
		 printf("%d - %d\n w: %d\n", parent[i], i,key[i]);
		 
	}*/
	
	sort(key.begin(),key.end());
	
	cout << key[k] << endl;
	//cout << smallestWeight << endl;
	/*int max=-1;
	
	for(int l=1;l<k;l++)
	{
		if(key[l]>=max)
		 {
		 	max=key[l];
		 }
	}
		cout << max << endl;*/
        
        
    //cout << key[k-1] << endl;
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
	g.primMST(k);
	
	return 0;
}
