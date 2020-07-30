#include<bits/stdc++.h>
using namespace std;


struct Edge
{
    long long int src;
	long long int dest;
	long long int weight;
};
 

struct Graph
{
    long long int V, E;
    struct Edge* edge;
};
 
struct Graph* createGraph(long long int V, long long int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
 
struct subset
{
    long long int parent;
    long long int rank;
};
 
long long int find(struct subset subsets[], long long int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
void Union(struct subset subsets[], long long int x, long long int y)
{
    long long int xroot = find(subsets, x);
    long long int yroot = find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 
void KruskalMST(struct Graph* graph,long long int k)
{
    long long int V = graph->V;
    long long int E = graph->E;
    struct Edge result[E];  
    long long int e = 0;  
    long long int i = 0;  
 	//cout << "start" << endl;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 	//cout << "sorted" << endl;
    struct subset *subsets =(struct subset*) malloc( 2*V*sizeof(struct subset) );
 	vector<long long int> weights;
    for (long long int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V)
    {
    	//cout << "1" << endl; 
        struct Edge next_edge = graph->edge[i];
        i++;
 		//cout << next_edge.src << " " << next_edge.dest << " " << next_edge.weight << endl; 
        long long int x = find(subsets, next_edge.src);
        long long int y = find(subsets, next_edge.dest);
 		//cout << "x: " << x << " y: " << y << endl; 
        if (x != y)
        {
        	//cout << next_edge.weight << endl;
        	weights.push_back(next_edge.weight);
            result[e] = next_edge;
            e++;
            Union(subsets, x, y);
        }
        if(e==(V-1))break;
    }
    //cout << "here" << endl;
 	sort(weights.begin(),weights.end());
 	cout << weights[k-1] << endl;
	
    return;
}
 
 int main()
{
    long long int n,m,u,v,p,k;
    cin>>n>>m>>k;
    Graph *g = createGraph(n,m);
    for(long long int i=0;i<m;++i)
    {
    	cin >> u >> v>> p;
    	g->edge[i].src = u-1;
    	g->edge[i].dest = v-1;
    	g->edge[i].weight = p;
    	
	}
	
	KruskalMST(g,k);
    
 
    return 0;
}

