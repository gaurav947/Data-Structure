#include<iostream>
#include<iomanip>
using namespace std;
void Printmat(int mat[][10],int v)
{
	int i,j;
	cout<<"\n";
	cout<<"\n**Your Adjancy Matrix of graph**\n";
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void direct()
{
	int i,j,v;
	int mat[10][10];
	cout<<"Enter the No. of vertices in the graph = ";
	cin>>v;
	cout<<"\n";
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(i!=j)
			{
				cout<<"Enter 1 ( if vertex *"<<i+1<<" is adjacent to *"<<j+1<<" ),otherwise 0 : =";
				cin>>mat[i][j];	
			}
			else
			{
				mat[i][j] = 0;
			}
		}
	}
	Printmat(mat,v);
}
void undirect()
{
	int i,j,v;
	int mat[10][10];
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
				cin>>mat[i][j];
				mat[j][i]=mat[i][j];	
			}
			else
			{
				mat[i][j] = 0;
			}
		}
	}
	Printmat(mat,v);
}
int main()
{
	while(1)
	{
	int n;
	cout<<"\n--->Press Your Graph Type\n";
	cout<<"1.Directed Graph\n";
	cout<<"2.Undirected graph + Weighted Graph(Instead of 1 Write the Edges value)\n";
	cout<<"Choice = ";
	cin>>n;
	switch(n)
	{
		case 1:
			direct();
			break;
		case 2:
		{
			undirect();
			}	
	}
   }
	return 0;
}
