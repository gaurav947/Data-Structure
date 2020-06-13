#include<bits/stdc++.h>
using namespace std;
void printlist(list<pair<int,int> > graph[],int v)
{
	int x,y;
	list<pair<int,int> >::iterator it;
	for(int i=1;i<v;i++)
	{
		cout<<"Adjancency List of vertex ->"<<i;
		for(it=graph[i].begin();it!=graph[i].end();it++)
		{
			x = it->first;
			y = it->second;
			cout<<" *-> "<<x<<"|"<<y;
		}
		cout<<"->X";
		cout<<endl;
	}
}
int main()
{
	int v,e;
	cout<<"Enter the Vertices of graph = ";
	cin>>v;
	cout<<"Enter the Edges of the graph = ";
	cin>>e;
	list<pair<int,int> > graph[v+1];
	for(int i=0;i<e;i++)
	{
		int s,d,w;
		cout<<"Enter the Source , destination and its Weight =  ";
		cin>>s;
		cin>>d;
		cin>>w; 
		graph[s].push_back(make_pair(d,w));
		graph[d].push_back(make_pair(s,w));
	}
	printlist(graph,v);
}
