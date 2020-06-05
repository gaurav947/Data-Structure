#include<iostream>
#include<list>
#include<stack>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	
	void topologicalsortutil(int v,bool visited[],stack<int> &stack);
	public:
		Graph(int V);
		void addEdge(int v,int w);
		void topologysort();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}
void Graph::topologicalsortutil(int v,bool visited[],stack<int> &stack)
{
	visited[v] = true;
	list<int>::iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it])
		{
			topologicalsortutil(*it,visited,stack);
		}
	}
	stack.push(v);
}
void Graph::topologysort()
{
	stack<int>stack;
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
		{
			topologicalsortutil(i,visited,stack);
		}
	}
	while(stack.empty()==false)
	{
		cout<<stack.top()<<" ";
		stack.pop();
	}
}
int main()
{
	Graph g(6);
	g.addEdge(5,0);
	g.addEdge(5,2);
	g.addEdge(4,0);
	g.addEdge(4,1);
	g.addEdge(2,3);
	g.addEdge(3,1);
	
	cout<<"Topology Sort = ";
	g.topologysort(); 
	
}
