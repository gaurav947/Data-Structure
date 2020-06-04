#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node* link;
};
struct node* start=NULL;
struct node* crossnode()
{
	struct node *n;
	n = (struct node* )malloc(sizeof(struct node));
	return(n);
}
void insertatend()
{
	struct node *temp,*t;
	temp = crossnode();
	cout<<endl; 
	cout<<"Please Enter Your Element = ";
	cin>>temp->data;
	temp->link=NULL;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		t = start;
		while(t->link!=NULL)
		{
			t = t->link; 
		}
		t->link = temp;
	}
}
void insertatbeg()
{
	struct node* temp;
	temp = crossnode();
	cout<<endl;
	cout<<"Enter your Element = ";
	cin>>temp->data;
	temp->link = NULL;
	if(start==NULL)
	{
		start = temp;
	}
	else
	{
		temp->link=start;
		start = temp;
	}
}
void insertafter()
{
	struct node* temp,*loc;
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
		cout<<"Enter which Element you Want to insert Your Element = ";
		cin>>n;
		while(loc!=NULL)
		{
			if(n==loc->data)
			{
				if(loc->link==NULL)
				{
					temp=crossnode();
					cout<<"Okk...Please Enter your Element = ";
					cin>>temp->data;
					temp->link=NULL;
					loc->link = temp;
					break;
				}
				else
				{
				temp = crossnode();
				cout<<"Okk...Please Enter your Element = ";
				cin>>temp->data;
				temp->link=loc->link;
				loc->link = temp;
				break;
				}
			}
			else
			{
				loc = loc->link;
			}
		
	    }
	    if(loc==NULL)
	    {
	    	cout<<endl;
	    	cout<<"**No element FOUND"<<endl;
	    	
		}
    }
}
void insertbefore()
{
	struct node *loc,*ploc=NULL,*temp;
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
		cout<<"Enter the Element before you Enter Your element = ";
		cin>>n;
		while(loc!=NULL)
		{
			if(n==loc->data)
			{
				temp=crossnode();
				cout<<"Okk..Please Enter Your element =";
				cin>>temp->data;
				if(ploc==NULL)
				{
					temp->link = start;
					start=temp;
					break;
				}
				else
				{
				temp->link=loc;
				ploc->link=temp;
				break;
			    }
				
			}
			else
			{
				ploc=loc;
				loc=loc->link;
			}
		}
		
	}
}
void delfirst()
{
	struct node* n;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is Empty"<<endl;
	}
	else
	{
	  n = start;
	  start = start->link;
	  free(n);
	}
}
void delend()
{
	struct node* n,*loc,*t;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is Empty"<<endl;
	}
	else
	{
		if(start->link==NULL)
		{
			t=start;
			start=NULL;
			free(t);
		}
		else
		{
		n=start;
		while((n->link)->link!=NULL)
		{
			n = n->link;
		}
		loc=n->link;
		n->link=NULL;
		free(loc);
		}
	}
}
void delafter()
{
	struct node* n,*temp;
	int j;
	if(start==NULL || start->link == NULL )
	{
		cout<<endl;
		cout<<"List is Empty or Only single element left"<<endl;
	}
	else
	{
		n=start; 
		cout<<endl;
		cout<<"Enter the element after you delete the Element = ";
		cin>>j;
		while(n!=NULL)
		{
			if(j==n->data)
			{
				temp = n->link;
				n->link=temp->link; 
				free(temp);
				break;
			}
			else
			{
				n =n->link;
			}
		}
	}
}
void  delone()
{
	struct node *loc,*ploc,*ptr;
	int j;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is Empty"<<endl;
	}
	else
	{
		loc=start;
		cout<<endl;
		cout<<"which element you want to delete=";
		cin>>j;
		while(loc!=NULL)
		{
			if(j==loc->data)
			{
				if(loc->link==NULL)
				{
				   ptr=loc;
				   loc=NULL;
				   free(ptr);
				   break;
				}
				else
				{
				ptr=ploc->link;
				ploc->link=ptr->link;
				free(ptr);
				break;
			    }
			}
			else
			{
				ploc=loc;
				loc=loc->link;
			}

		}
	}
}
void print()
{
	struct node* n;
	if(start==NULL)
	{
		cout<<endl;
		cout<<"List is empty"<<endl;
	}
	else
	{
		n = start;
		cout<<endl;
		cout<<"Your Sin linked list is :";
		while(n!=NULL)
		{
			cout<<n->data<<" ";
			n = n->link;
		}
		cout<<endl;
	}
}
int main()
{
	while(2)
	{
	int j;
	cout<<endl;
	cout<<"1.Insert at The End"<<endl;
	cout<<"2.Insert at the beg"<<endl;
	cout<<"3.Insert After the given Element"<<endl;
	cout<<"4.Insert before a given Element"<<endl;
	cout<<"5.Delete the first one"<<endl;
    cout<<"6.Delete the Last one"<<endl;
    cout<<"7.Delete after the given element"<<endl;
    cout<<"8.Delete the given Element"<<endl;
	cout<<"9.Show The List"<<endl;
    cout<<"Enter the Choice = ";
    cin>>j;
    switch(j)
    {
    	case 1:
    		insertatend();
    		print();
    		break;
    	case 2:
		   insertatbeg();
		   print();
		   break;	
		case 3:
		  insertafter();
		  print();
		  break;
		case 4:
		   insertbefore();
		   print();
		   break;
		case 5:
		   delfirst();
		   print();
		   break;
		case 6:
		  delend();
		  print();
		  break;
		case 7:
		 delafter();
		 print();
		 break;
		case 8:
		  delone();
		  print();
		  break;            
    	case 9:
		   print();
		   break;
		default :
			cout<<endl;
		   cout<<"**Invalid Entry.. Please Check And rewrite";   	
	}
	}
}

