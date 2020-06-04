#include <iostream>
#include<stdlib.h>
using namespace std;

struct nod {
   nod *l, *r;
   int d;
}*r = NULL, *p = NULL, *np = NULL, *q;

void create() {
   int v;
      if (r == NULL) {
         r = (struct nod *)malloc(sizeof(struct nod));
         cout<<endl;
         cout<<"enter value of root node = ";
         cin>>r->d;
         r->r = NULL;
         r->l = NULL;
      } else {
         p = r;
         cout<<endl;
         cout<<"enter value of node = ";
         cin>>v;
         while(true) {
            if (v< p->d) {
               if (p->l == NULL) {
                  p->l =  (struct nod *)malloc(sizeof(struct nod));;
                  p = p->l;
                  p->d = v;
                  p->l = NULL;
                  p->r = NULL;
                  cout<<"value entered in left\n";
                  break;
               } else if (p->l != NULL) {
                  p = p->l;
               }
            } else if (v >p->d) {
               if (p->r == NULL) {
                  p->r =  (struct nod *)malloc(sizeof(struct nod));;
                  p = p->r;
                  p->d = v;
                  p->l = NULL;
                  p->r = NULL;
                  cout<<"value entered in right\n";
                  break;
               } else if (p->r != NULL) {
                  p = p->r;
               }
            }
         }
      }
      
   }
struct nod* search(struct nod* node,int data)
{
	if(node==NULL)
	{
		cout<<"\n Tree is Empty \n";
	}
	else
	{
		struct nod *loc;
		loc = node;
		while(loc!=NULL)
		{
			if(data == loc->d)
			{
				cout<<"\n *Yes it is Present \n";
				break;
			}
			else if(data<loc->d)
			{
				loc = loc->l;	
			}
			else
			{
				loc = loc->r;
			}
			
		}
		if(loc==NULL)
		{
			cout<<"\n * listen No element found \n";
		}
	}
}
struct nod* delet(struct nod* root,int data)
{
	if(root==NULL)
	{
		cout<<"\nNo Element to delete\n";
	}
	struct nod *loc;
	loc = root;
	while(loc!=NULL)
	{
		if(data==loc->d)
		{
			//No child
			cout<<"found";
			if(loc->l==NULL && loc->r==NULL)
			{
				cout<<"enter no child";
				struct nod* temp = loc;
				loc = NULL;
				free(temp);
			}
			//One child
			else if(loc->l==NULL)
			{
				struct nod* temp = loc;
				loc = loc->r;
				delete(temp);
			}
			else if(loc->r==NULL)
			{
				struct nod* temp = loc;
				loc = loc->l;
				delete(temp);
			}
			else
			{
			 cout<<"2 Child;";
				
			}
		}
		else if(data<loc->d)
		{
			loc = loc->l;
		}
		else
		{
			loc = loc->r;
		}
	}

}
void inorder(nod *p) {
   if (p != NULL) {
      inorder(p->l);
      cout<<p->d<<" ";
      inorder(p->r);
   }
}

void preorder(nod *p) {
   if (p != NULL) {
      cout<<p->d<<" ";
      preorder(p->l);
      preorder(p->r);
   }
}

void postorder(nod *p) {
   if (p != NULL) {
      postorder(p->l);
      postorder(p->r);
      cout<<p->d<<" ";
   }
}

int main()
{
   while(1)
   {
   	int n;
   	cout<<endl;
   	cout<<"1.Insert "<<endl;
   	cout<<"2.Search"<<endl;
   	cout<<"3.Delete"<<endl;
   	cout<<"4.Traversal in inorder\n";
   	cout<<"5.Traversal in preorder\n";
   	cout<<"6.Traversal in Postorder\n";
   	cout<<"Choice = ";
   	cin>>n;
   	switch(n)
   	{
   		case 1:
   			create();
   			break;
   		case 2:
   			int s;
   			cout<<"\nEnter the element to delete = ";
   			cin>>s;
		    search(r,s);
			cout<<"\n--->Opeartion successfull<---\n";
			break;	
   		case 3:
   		   	int d;
   			cout<<"\nEnter the element to delete = ";
   			cin>>d;
		    delet(r,d);
			cout<<"\n--->Opeartion successfull<---\n";
			break;	
		   case 4:
   			cout<<endl;
   			cout<<"\n Inorder :";
   			inorder(r);
   			cout<<endl;
   			break;
		case 5:
			cout<<endl;
			cout<<"\n Preorder:";
			preorder(r);
			cout<<endl;
			break;
		case 6:
			cout<<endl;
			cout<<"\n Postorder:";
		    postorder(r);
		    cout<<endl;
			break;
		default:
		  cout<<"\n **Write correct Choice ";	  	
   		
	}
}
}
