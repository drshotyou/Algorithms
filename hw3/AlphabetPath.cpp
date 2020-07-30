#include <iostream>
#include <string>
#include <list>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
string bound;
string vertices;
vector<long long int> anss;
bool ans;
int charToInt[26]={0};
int dup[26]={0};

class Graph
{
	public:
	long long numVer;
	list<long long int> *adj;
	Graph(long long nV);
	void addEdge(long long u,long long v);
	void addEdge2(long long u,long long v);
	vector<long long> findVertex(char a);
	void fill(long long int v, bool visited[], stack<int> &stack);
	void DFS(long long int v, bool visited[]);
	void print();
	Graph transpose();
};
Graph::Graph(long long nV)
{
	this->numVer=nV;
	adj=new list<long long int>[nV];

}
void Graph::addEdge(long long a , long long b)
{
	adj[a].push_back(b);
}

void Graph::DFS(long long int v, bool visited[])
{
	visited[v]=true;
	//cout << vertices[v]-97 << endl;
	dup[vertices[v]-97]=0;
	//cout << v << " " ;
	for(int j=0;j<26;j++)
	{
		if(dup[j]==1)
		{
			ans=false;
			break;
		}
		else
		{
			ans=true;
		}
	}
	
	list<long long int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFS(*i, visited); 
}
Graph Graph::transpose()
{
	Graph g(numVer);
	for(int v=0;v<numVer;v++)
	{
		list<long long int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            g.adj[*i].push_back(v); 
        } 
	}
	return g;
}
void Graph::fill(long long int v, bool visited[] , stack<int> &stack)
{
	visited[v] = true; 
  
    list<long long int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            fill(*i, visited, stack); 
  
    stack.push(v); 
}
void Graph::print()
{
	stack<int> stack;
	bool *visited = new bool[numVer];
	for(int i=0;i<numVer;i++)
	{
		visited[i]=false;
	}
	
	for(int i=0;i<numVer;i++)
	{
		if(visited[i] == false) 
            fill(i, visited, stack); 
	}
	
	Graph trans = transpose();
	
	for(int i=0;i<numVer;i++)
	{
		visited[i]=false;
	}
	
	while(!stack.empty())
	{
		long long int v = stack.top();
		stack.pop();
		
		if(visited[v]==false)
		{
			for(int i=0;i<26;i++)
			{
				dup[i]=charToInt[i];
			}
			trans.DFS(v,visited);
			if(ans)break;
		}
	}
}
vector<long long> Graph::findVertex(char a)
{
	vector<long long int> found;
	for(long long i=0;i<numVer;++i)
	{
		if(a==vertices[i])
		{
			found.push_back(i);
		}
	}
	return found;
}

int main ()
{
	long long v1,v2,n,m;
	
	
	cin >> n >> m;
	Graph g(n);
	cin>> vertices;
	for(long long i=0;i<m;i++)
	{
		cin >> v1 >> v2;
		g.addEdge(v1-1,v2-1);
	}	
	cin >> bound;
	for(int i=0;i<bound.size();i++)
	{
		//cout << bound[i]-97 << endl;
		charToInt[bound[i]-97]=1;
	}
	g.print();

	if(ans==true)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	
	return 0;
}
