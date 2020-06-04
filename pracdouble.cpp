#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next,*prev;
};
struct node *start = NULL;
struct node *tail = NULL;
struct node *crossnode()
{
  struct node *n;
  n = (struct node *)malloc(sizeof(struct node));
  return(n);
}
void insertbeg()
{
	struct node *loc,*ptr;
	ptr=crossnode();
	cout<<"Enter the element = ";
	cin>>ptr->data;
	ptr->prev = NULL;
	ptr->next = NULL;
	if(start==NULL)
	{
		start = ptr;
		tail = ptr;
	}
	else
	{
		ptr->next = start;
		start->prev = ptr;
		start = ptr;
	}
	
}
void insertend()
{
	struct node *ptr,*loc;
	ptr = crossnode();
	cout<<"Enter the Element = ";
	cin>>ptr->data;
	ptr->next = NULL;
	if(start==NULL)
	{
		ptr->prev =NULL;
		start = ptr;
		tail =ptr;
		  
	}
	else
	{
		ptr->prev = tail;
		tail->next = ptr;
		tail = ptr;
	}
}
void insertafter()
{
	struct node *loc,*ptr;
	int n;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is Empty"<<endl;
	}
	else
	{
		loc = start;
		cout<<endl;
		cout<<"Enter the Element after which U add your Element = ";
		cin>>n;
		while(loc!=NULL)
		{
			if(n==loc->data)
			{
				if(loc->next == NULL)
				{
					ptr = crossnode();
					cout<<"ok..Please Enter your Element = ";
					cin>>ptr->data;
					ptr->next = NULL;
					ptr->prev = tail;
					tail->next = ptr;
					tail = ptr;
					break;
				}
				else
				{
				ptr = crossnode();
				cout<<"ok..Please Enter your Element =  ";
				cin>>ptr->data;
				ptr->prev = loc;
				ptr->next = loc->next;
				(loc->next)->prev = ptr;
				loc->next = ptr;
				break;
			    }
			}
			else
			{
				loc = loc->next;
			}
		}
		if(loc == NULL)
		{
			cout<<endl;
			cout<<"*Element Not found"<<endl;;
		}
    }
}
void insertbefore()
{
	struct node *loc,*ptr;
	int n;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is Empty"<<endl;
	}
	else
	{
		loc=start;
		cout<<"Enter the Element before u enter your Element = ";
		cin>>n;
		while(loc!=NULL)
		{
			if(n==loc->data)
			{
				ptr=crossnode();
				cout<<"Ok..Enter the Element =";
				cin>>ptr->data;
				(loc->prev)->next=ptr;
				ptr->prev =loc->prev;
				ptr->next=loc;
				loc->prev=ptr;
				break;
			}
			else
			{
				loc=loc->next;
			}
		}
	}
}
void delfirst()
{
	struct node *ptr;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"*List is Empty"<<endl;
	}
	else
	{
		ptr = start;
		start = start->next;
		free(ptr);
	}
}
void delend()
{
	struct node *ptr;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"list is Empty"<<endl;
	}
	else
	{
		if(start->next==NULL)
		{
			ptr=start;
			start = NULL;
			tail=NULL;
			free(ptr);
		}
		else
		{
		ptr=tail;
		(tail->prev)->next = NULL;
		tail = tail->prev;
		free(ptr);
     	}
	}
}
void delafter()
{
	struct node *loc, *ptr;
	int n;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is Empty"<<endl;
	}
	else
	{
		loc=start;
		cout<<"Enter the Element after which you delete the Element = ";
		cin>>n;
		while(loc!=NULL)
		{
			if(loc->next==NULL)
			{
				cout<<endl;
				cout<<"*No Element After"<<endl;
				break;
			}
			if((loc->next)->next==NULL)
			{
				ptr = loc->next;
				loc->next=NULL;
				free(ptr);
			}
			if(n==loc->data)
			{
				ptr = loc->next;
				loc->next = ptr->next;
				(ptr->next)->prev=loc;
				free(ptr);
				break;
			}
			else
			{
				loc = loc->next;
			}
		}
	}
}
void delbefore()
{
	struct node *loc,*ptr;
	int n;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is Empty"<<endl;
	}
	else
	{
		loc=start;
		cout<<endl;
		cout<<"Enter the Element before you delete the Element = "; 
		cin>>n;
		while(loc!=NULL)
		{
			if(n==loc->data)
			{
				  if(loc->prev==NULL)
				{
					cout<<endl;
					cout<<"*No Element before this"<<endl;
					break;
				}
				if((loc->prev)->prev==NULL)
				{
					cout<<"Enter in badi";
					ptr=loc->prev;
					start = start->next;
					loc->prev = start;
					free(ptr);
					break;
				}
				else
				{
					ptr=loc->prev;
					loc->prev=ptr->prev;
					(ptr->prev)->next=loc;
					free(ptr);
					break;
			    }
			}
			else
			{
				loc=loc->next;
			}
		}
		
	}
}
void show()
{
	struct node *pr;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is Empty";
		cout<<endl;
	}
	else
	{
		pr=start;
		cout<<endl;
		cout<<"Your Doubly linked list is = ";
		while(pr!=NULL)
		{
			cout<<pr->data<<" ";
			pr=pr->next;
		}
		cout<<endl;
	}
}
int main()
{
	while(1)
	{
	 int n;
	cout<<endl;
	cout<<"1.Insert in the end"<<endl;
	cout<<"2.Insert in the beg"<<endl;
	cout<<"3.Insert after the given Element"<<endl;
	cout<<"4.Insert before the given Element"<<endl;
	cout<<"5.Delete first node"<<endl;
	cout<<"6.Delete last node"<<endl;
	cout<<"7.Delete After a given node"<<endl;
	cout<<"8.delete before a given node"<<endl;
	cout<<"9.Show"<<endl;
	cout<<endl;
	cout<<"Your Choice = ";
	cin>>n;
	switch(n)
	{
		case 1:
			insertend();
			show();
			break;
		case 2:
		    insertbeg();
			show();
			break;
		case 3:
		    insertafter();
			show();
			break;
		case 4:
		     insertbefore();
			 show();
			 break;	
		case 5:
		    delfirst();
			show();
			break;
		case 6:
		    delend();
			show();
			break;
		case 7:
		   delafter();
		   show();
		   break;
		case 8:
		   delbefore();
		   show();
		   break;   				
		case 9:
		     show();
			 break;	
	}
  }
}
