#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int info;
	struct node *next;
};
struct node *start=NULL;
struct node *crossnode()
{
	struct node *n;
	n = (struct node *)malloc(sizeof(struct node));
	return(n);
}
void inqueue()
{
	struct node *temp,*n;
	temp = crossnode();
	cout<<endl;
	cout<<"Ok...ENter the Element =";
	cin>>temp->info;
	temp->next = NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		n=start;
		while(n->next!=NULL)
		{
			n = n->next;
		}
		n->next = temp;
		
	}
}
void dequeue()
{
	struct node *temp;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is Empty"<<endl;
	}
	else
	{
		temp = start;
		start = start->next;
		free(temp);
	
	}
}
void peep()
{
	if(start==NULL)
	{
		cout<<endl;
		cout<<"**List is Empty"<<endl;
	}
	else
	{
		cout<<endl;
		cout<<"Peep = ";
		cout<<start->info<<endl;
	}
}
void show()
{
	struct node *n;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"**List is Empty"<<endl;
	}
	else
	{
		n = start;
		cout<<endl;
		cout<<"Queue:"<<endl;
		while(n!=NULL)
		{
			cout<<n->info<<" ";
			n = n->next;
			
		}
	}
}
int main()
{
		while(1)
	{
		int ch;
		cout<<endl;
		cout<<"....Choose From Below...."<<endl;
		cout<<"1.Inqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Peep"<<endl;
		cout<<"4.Show"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Choice = ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				 inqueue();
				 show();
				 break;
			case 2:
			    dequeue();
				show();
				break;
			case 3:
			  peep();
			  break;		 
			case 4:
			 show();
			 break;
			case 5:
			 exit(0); 
			 	 
		}
	}
}
