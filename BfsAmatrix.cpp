#include<bits/stdc++.h>
using namespace std;
void bfs(int graph[][10],int v,int s)
{
	list<int> queue;
	vector<bool> visited(v,false);
	queue.push_back(s);
	visited[s]=true;
	while(!queue.empty())
	{
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(int i=1;i<v;i++)
		{
			 if(!visited[i] && graph[s][i]!=0)
			{
				queue.push_back(i);
				visited[i] = true;
			}
		}
	}
}
int main()
{
    int i,j,v;
	int graph[10][10];
	cout<<"Enter the No. of vertices in the graph = ";
	cin>>v;
	cout<<"\n";
	for(i=0;i<v;i++)
	{
		for(j=i;j<v;j++)
		{
			if(i!=j)
			{
				cout<<"Enter 1 ( if vertex *"<<i+1<<" is adjacent to *"<<j+1<<" ),otherwise 0 : =";
				cin>>graph[i][j];
				graph[j][i]=graph[i][j];	
			}
			else
			{
				graph[i][j] = 0;
			}
		}
	}
	int b;
	cout<<"Enter the Starting Point for BFS = ";
	cin>>b;
	bfs(graph,v+1,b);
}
