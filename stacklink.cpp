#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int info;
	struct node *next;
};
int n,i,choose;
struct node* start=NULL;
struct node* createnode()
{
	struct node *n;
	n=(struct node* )malloc(sizeof(struct node));
	return n;
}
void del_stack()
{
	struct node *temp;
	temp = start;
	start=NULL;
	delete(temp);
}
void push()
{
	struct node *temp;
	temp = createnode();
	cout<<"OK enter the element = ";
	cin>>temp->info;
	if(start==NULL)
	{
		temp->next = NULL;
		start=temp;
	}
	else
	{
		temp->next=start;
		start=temp;
	}
	
}
void pop()
{
	struct node *temp;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"***Stack Underflow"<<endl;
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
		cout<<"Stack is Empty"<<endl;
	}
	else
	{
		cout<<start->info<<endl;
	}
}
void show()
{
	struct node *n;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is Empty"<<endl;
	}
	else
	{
		n=start;
		cout<<endl;
		cout<<"Stack:"<<endl;
		while(n!=NULL)
		{
			cout<<n->info<<endl;
			n=n->next;
		}
		cout<<endl;
		
	}
}
int main()
{
	cout<<"Enter the size of stack = ";
	cin>>n;
	while(1)
	{ 
	cout<<".........Now Choose the OPTION below........"<<endl;
	cout<<"1.Push"<<endl;
	cout<<"2.Pop"<<endl;
	cout<<"3.Peep"<<endl;
	cout<<"4.Show"<<endl;
	cout<<"5.Delete the stack"<<endl;
	cout<<"6.Exit"<<endl;
	cout<<"Choose = ";
	cin>>choose;
	switch(choose)
	{
		case 1:
			push();
			show();
			break;
		case 2:
		  pop();
		  show();
		  break;
		case 4:
		   show();
		   break;
		case 3:
		    peep();
			break;
		case 5:
		   del_stack();
		   show();  
		   break;
		case 6:
		  exit(0);
		  break;
		default:
		   cout<<endl;
		   cout<<"**Please write Correct choice**"<<endl;       	
			
	}
	}
}


