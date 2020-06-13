#include<bits/stdc++.h>
using namespace std;
void dfs(int graph[][10],int v,int s)
{
	list<int> stack;
	vector<bool> visited(v,false);
	stack.push_back(s);
	visited[s]=true;
	while(!stack.empty())
	{
		s = stack.back();
		cout<<s<<" ";
		stack.pop_back();
		for(int i=0;i<v;i++)
		{
			 if(!visited[i] && graph[s][i]!=0)
			{
				stack.push_back(i);
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
				cout<<"Enter 1 ( if vertex *"<<i<<" is adjacent to *"<<j<<" ),otherwise 0 : =";
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
	cout<<"Enter the Starting Point for DFS = ";
	cin>>b;
	dfs(graph,v,b);
}
