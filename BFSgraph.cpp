#include<iostream>
#include<vector>
#include<list>
using namespace std;
void print(list<int> graph[],int v)
{
	int i;
	list<int>::iterator it;
	for(i=1;i<v;i++)
	{
		cout<<"Adjcency List of "<<i;
		for(it=graph[i].begin();it!=graph[i].end();it++)
		{
			cout<<"->"<<*it;
		}
		cout<<"\n";
	}
}
void BFS(list<int> graph[],int s,int v)
{
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i] = false;
	}
	
	list<int> queue;
	
	visited[s] = true;
	queue.push_back(s);
	
	list<int>::iterator i;
	
	while(!queue.empty())
	{
		s  = queue.front();
		cout<<s<<" ";
		queue.pop_front();
		
		for(i = graph[s].begin();i!=graph[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
				cout<<"->"<<*i;
			}
		}
	}
}
int main()
{
	int v,e,i,s,d;
	cout<<"Enter the No. of vertices = ";
	cin>>v;
	cout<<"Enter the No. of Edges = ";
	cin>>e;
	list<int> graph[v+1];
	for(i=0;i<e;i++)
	{
		cout<<"Enter the (Source and Destination) = ";
		cin>>s;
		cin>>d;
		graph[s].push_back(d);
		graph[d].push_back(s);
	}
	print(graph,v+1);
	int p;
	cout<<"\n Enter the Starting For BFS  = ";
	cin>>p;
	BFS(graph,p,v+1);

}
