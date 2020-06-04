#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> graph[],int n)
{
	vector<int>::iterator it;
	for(int i=1;i<n;i++)
	{
		cout<<"Adjcency List of Vertex ("<< i<< ")";
		for(it=graph[i].begin();it<graph[i].end();it++)
		{
			cout<<" -> "<< *it;
		}
		cout<<" -> X";
		cout<<"\n";
	}
}
void directed()
{
int v,e,s,d;
	cout<<"Enter the no. of Vertices =";
	cin>>v;
	cout<<"Enter the no. of Edges = ";
	cin>>e;
	vector<int> graph[v+1];
	for(int i=0;i<e;i++)
	{
		cout<<"Enter the Source & destination = ";
		cin>>s;
		cin>>d;
		graph[s].push_back(d);
	}
	print(graph,v+1);
}

void undirected()
{
int v,e,s,d;
	cout<<"Enter the no. of Vertices =";
	cin>>v;
	cout<<"Enter the no. of Edges = ";
	cin>>e;
	vector<int> graph[v+1];
	for(int i=0;i<e;i++)
	{
		cout<<"Enter the Source & destination = ";
		cin>>s;
		cin>>d;
		graph[s].push_back(d);
		graph[d].push_back(s);
	}
	print(graph,v+1);
	
}

int main()
{
  while(1)
  {
  	int n;
  	cout<<"\n1.Directed Graph\n";
  	cout<<"2.Undirected Graph\n";
  	cout<<"3.Exit\n";
  	cout<<"Choice = ";
  	cin>>n;
  	switch(n)
  	{
  		case 1:
  			directed();
  			break;
  		case 2:
		  undirected();
		  break;
		case 3:
		   exit(0); 
		   break;  	
	 }
  	
}
	
}
