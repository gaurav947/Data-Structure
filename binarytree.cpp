#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
}*root=NULL,*p=NULL;
struct node* insert(struct node *root,int data)
{
	if(root==NULL)
	{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->left=NULL;
		temp->right = NULL;
		root=temp;
		cout<<"\nValue Entered in the Root\n";
	}
	else 
	{
		while(true)
		{
			if(data<root->data)
			{
				if(root->left==NULL)
				{
					cout<<"Enter left";
					root->left=(struct node*)malloc(sizeof(struct node));
					root->left->data = data;
					root->left->left=NULL;
					root->right->right=NULL;
					cout<<"\nValue Entered in the Left subtree\n";
					break;
				}
				else if(root->left!=NULL)
				{
					root = root->left;
				}
				
			}
			else if(data>root->data)
			{
				if(root->right==NULL)
				{
					cout<<"enter right";
					root->right=(struct node*)malloc(sizeof(struct node));
					root->right->data = data;
					root->right->left=NULL;
					root->right->right=NULL;
					cout<<"\nValue Entered in the Right subtree\n";
					break;
				}
				else if(root->right!=NULL)
				{
					root = root->right;
				}
			}
		}
   }
   return root;
}
void preorder(struct node *p)
{
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}
int main()
{
	while(1)
	{
		int i,n;
		cout<<"\n1.Insert\n";
		cout<<"2.Show\n";
		cout<<"Choice = ";
		cin>>n;
		switch(n)
		{
			case 1:
				{
				
				cout<<"\nEnter the Element = ";
				cin>>i;
				root = insert(root,i);
				cout<<"yes";
				cout<<"\n--->Operation Completed<---\n";
				break;
				}
			case 2:
			{
				cout<<"\nBinary search tree:";
				preorder(root);
				break;
			}
	    }
	}
}
