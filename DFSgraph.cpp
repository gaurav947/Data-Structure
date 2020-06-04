#include<iostream>
#include<list>
using namespace std;
void print(list<int>graph[],int n)
{
	list<int>::iterator it;
	for(int i=1;i<n;i++)
	{
		cout<<"Adjacency List of ( "<<i <<" )";
		for(it = graph[i].begin();it!=graph[i].end();it++)
		{
			cout<<"->"<<*it;
		}
		cout<<"->X";
		cout<<"\n";
	}
}
void dfs(list<int> graph[],int s,int v)
{
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	list<int> stack;
	visited[s] = true;
	stack.push_back(s);
	list<int>::iterator it;
	while(!stack.empty())
	{
		s = stack.back();
		cout<<s<<" ";
		stack.pop_back();
		for(it = graph[s].begin();it!=graph[s].end();it++)
		{
			if(!visited[*it])
			{
				visited[*it]=true;
				stack.push_back(*it);
			}
		}
	}
}
int main()
{
	int v,e,s,d,i,p;
	cout<<"Enter the no. of vertices = ";
	cin>>v;
	cout<<"Enter the no. of Edges = ";
	cin>>e;
	list<int> graph[v+1];
	for(i=0;i<e;i++)
	{
	
			cout<<"Enter the source and destination = ";
			cin>>s;
			cin>>d;
			graph[s].push_back(d);
			graph[d].push_back(s);
	}
	print(graph,v+1);
	cout<<"Enter the starting Element for DFS = ";
	cin>>p;
	dfs(graph,p,v);

}
