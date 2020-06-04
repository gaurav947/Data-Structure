#include<iostream>
using namespace std;
int  a[100];
void insert(int root,int data)
{
	if(root==0)
	{
		a[0] = data;
	}
	else
	{
		a[root] = data;
	}
}
void display(int root)
{
	if(root==0)
	{
		cout<<"\nTree is Empty\n";
	}
	else
	{
		for(int i=0;i<root;i++)
		{
			cout<<a[i]<<" "; 
		}
	}
}
void search(int root,int search)
{
	if(root==0)
	{
		cout<<"\nTree is Empty\n";
	}
	else
	{
		for(int i=0;i<root;i++)
		{
			if(search==a[i])
			{
				cout<<"\nPosition Found at = "<<i+1;
				break;
			}
			else
			{
				cout<<"\n*Element is not Found*\n";
			}
		}
	}
}
int main()
{
	int root = 0;
	while(1)
	{
		int n;
		cout<<"\n1.Insert\n";
		cout<<"2.Show\n";
		cout<<"3.Search\n";
		cout<<"Choice = ";
		cin>>n;
		switch(n)
		{
			case 1:
				int i;
				cout<<"\nEnter the Element = ";
				cin>>i;
				insert(root,i);
				root = root+1;
				break;
			case 2:
			    cout<<"\nYour Tree:";
				display(root);
				cout<<endl;
				break;
			case 3:
				int s;
			    cout<<"\nSearch the Element = ";
				cin>>s;
				search(root,s);
				break;	
		}
	}
}
