#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
struct node* insert(struct node* node,int data)
{
	if(node==NULL)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		node = temp;
	}
	else if(data<node->data)
	{
		node->left = insert(node->left,data);
		cout<<"left";
	}
	else if(data>node->data)
	{
		node->right = insert(node->right,data);
		cout<<"right";
	}
	return node;
	
}
struct node* search(struct node* root,int data)
{
	if(root==NULL)
	{
		return root;
	}
	else if(data<root->data)
	{
		root->left = search(root->left,data);
	}
	else if(data>root->data)
	{
		root->right = search(root->right,data);
	}
	else if(data==root->data)
	{
		cout<<"\nYes it is present\n";
	}
	else
	{
		cout<<"\nNo Element found\n"; 
	}
}
struct node *findmax(struct node *root)
{
	if(root->right==NULL)
	{
		return root;
	}
	else
	{
	while(root->right!=NULL)
	{
		root = root->right;
		return root;
	}
    }
}
struct node* delet(struct node* root,int data)
{
	if(root==NULL)
	{
		return root;
	}
	else if(data<root->data)
	{
		root->left = delet(root->left,data);
	}
	else if(data>root->data)
	{
		root->right = delet(root->right,data);
	}
	else
	{
		//No child
		if(root->left==NULL && root->right==NULL)
		{
			cout<<"No child";
			free(root);
			root=NULL;
		}
		//one child
		else if(root->left==NULL)
		{
			struct node *temp = root;
			root=root->right;
			delete(temp);
		}
		else if(root->right==NULL)
		{
			struct node* temp = root;
			root = root->left;
			delete(temp);
		}
		//2 child
		else
		{
			struct node* temp = findmax(root->left);
			root->data = temp->data;
			root->left = delet(root->left,root->data);
		}
	}
  return root;
}
int main()
{
	struct node *root=NULL;
	while(1)
	{
		int i,n;
		cout<<"\n1.Insert\n";
		cout<<"2.Search\n";
		cout<<"3.Delete\n";
		cout<<"4.Show\n";
		cout<<"Choice = ";
		cin>>n;
		switch(n)
		{
			case 1:
				cout<<"\nEnter the Element = ";
				cin>>i;
				root = insert(root,i);
				cout<<"\n--->Operation Completed<---\n";
				break;
			case 2:
				int s;
			   	cout<<"\nEnter the Element to Search = ";
				cin>>s;
				search(root,s);
				cout<<"\n--->Operation Completed<---\n";
				break;
			case 3:
			    int d;
				cout<<"\nEnter the Element to Delete = ";
				cin>>d;
				root = delet(root,d);
				cout<<"\n--->Operation Completed<---\n";
				break;	
			case 4:
			    cout<<"\nBinary tree search:";
			    preorder(root);
			    cout<<endl;
				break;	
		}
	}
}
