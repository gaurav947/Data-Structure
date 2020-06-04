#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
struct node
{
	int info;
	struct node* link;
};

struct node* START=NULL;
struct node* createNode()
{
	struct node *n;
	n = (struct node *)malloc(sizeof(struct node));
	return(n);
}

void insertnode()
{
	struct node *temp , *t;
	temp = createNode();
	cout<<"Enter a number  =";
	cin>>temp->info;
	temp->link = NULL;
	if (START == NULL)
	{
		START=temp;
		
	}
	else
	{
		t = START;
		while(t->link!=NULL)
		{
		t = t->link;
	    }
		t->link = temp;
	}
}
void insertbeg()
{
	struct node *y;
	y =  createNode();
	cout<<"Enter Your Element =";
	cin>>y->info;
	y->link = START;
	START = y;
}
void insertafter()
{
	struct node* loc,*ptr;
	int n;
	if(START ==NULL)
	{
		cout<<"List is Empty";
	}
	loc = START;
	cout<<"which Element after you put your Element =  ";
	cin>>n;
	while(loc!=NULL)
	{
		if(n==loc->info)
		{
			ptr = createNode();
			cout<<"ok .. Enter the Element = ";
			cin>>ptr->info;
			ptr->link = loc->link;
			loc->link = ptr;
			break;
		}
		else
		{
			loc = loc->link;
		}
	}
}
void insertbefore()
{
	struct node *loc,*ptr;
	int n;
	struct node *p,*ploc=NULL;
	if(START == NULL )
	{		
		cout<<"No Element for before opertion";
	}
	loc=START;
	cout<<"which element You want to add before = ";
	cin>>n;
	while(loc!=NULL)
	{
		if(n == loc->info)
		{
			ptr = createNode();
			cout<<"ok..Enter the element = ";
			cin>>ptr->info;
			if(ploc == NULL)
			{
				ptr->link = START;
				START = ptr;
			}
			else
			{
				ptr->link = loc;
				ploc->link = ptr;
			}
			break;
			
		}
		else
		{
			ploc = loc;
			loc= loc->link;
		}
	}
}
void deleteNode()
{
	struct node *r;
	if(START==NULL)
	{
		cout<<"list is Empty";
		
	}
	else
	{
		r=START;
		START = START->link;
		free(r);
	}
	cout<<"""\n""*Deleted Element from Beg*"<<endl;
}
void delnodeend()
{
	struct node *loc,*ptr,*ff; 
	if(START == NULL)
	{
		cout<<"List is Empty";
	}
	if(START->link == NULL)
	{
		ff=START;
		START = NULL;
		free(ff);
	}
	else
	{
		loc=START;
		while((loc->link)->link!=NULL)
		{
			loc= loc->link;
		}
		ptr = loc->link;
		loc->link = NULL;
		free(ptr);
	}
}
void delafter()
{
	struct node* loc ,*ptr;
	int n;
	if(START==NULL || START->link == NULL)
	{
		cout<<"list is empty or Only single element Present in the list";
	}
	else
	{
		loc= START;
		cout<<"Enter which element do you want to delete after = ";
		cin>>n;
		while(loc!=NULL)
		{
			if(n == loc->info)
			{
				ptr = loc->link;
				loc->link = ptr->link;
				free(ptr);
				break;
			}
			else
			{
				loc = loc->link;
			}
		}
	}
}
void viewList()
{
	struct node *p;
	if(START == NULL)
	{
		cout<<"list is empty";
	}
	else
	{
		p=START;
		cout<<endl;
		cout<<"Your Linklist  = ";
		while(p!=NULL)
		{
			cout<<p->info<<" ";
			p = p->link;
		}
		cout<<endl;
	}
}
int menu()
{
	int ch;
	cout<<"""\n""""1. Insert in the End of the list "<<endl;
	cout<<"2. Insert in the Beg of the list"<<endl;
	cout<<"3. Insert After the Element of  the list"<<endl;
	cout<<"4. Insert before the Element of the list"<<endl;
	cout<<"5. Delete First value "<<endl;
	cout<<"6. Delete Last value "<<endl;
	cout<<"7. Delete after the value "<<endl;
	cout<<"8. View List"<<endl;	
	cout<<"9. Exit"<<endl;
	cout<<".........Enter Your Choice........ = ";
	cin>>ch;
	return(ch);
	
}

int main()
{
	while(1)
	{
	 switch(menu())
	 {
	 
		case 1:
			insertnode();
			break;
		case 2:
		    insertbeg();
			break;	
		case 3:
		    insertafter();
			break;
		case 4:
		     insertbefore();
			 break;		
		case 5:
			deleteNode();
			viewList();
			break;
		case 6:
			delnodeend();
			viewList();
			break;
		case 7:
		     delafter();
			 viewList();
			 break;	
		case 8:
			viewList();
			break;
		case 9:
			exit(0);
		default: 
		        cout<<"""\n""**Invalid Choice**  .... *Please Enter correct Choice* "<<endl;
	}
	}
}
