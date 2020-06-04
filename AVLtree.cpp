 // C++ program to insert a node in AVL tree 
#include<bits/stdc++.h> 
using namespace std; 

// An AVL tree node 
class Node 
{ 
	public: 
	int key; 
	Node *left; 
	Node *right; 
	int height; 
}; 

// A utility function to get maximum 
// of two integers 
int max(int a, int b); 

// A utility function to get the 
// height of the tree 
int height(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

// A utility function to get maximum 
// of two integers 
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

/* Helper function that allocates a 
new node with the given key and 
NULL left and right pointers. */
Node* newNode(int key) 
{ 
	Node* node = new Node(); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially 
					// added at leaf 
	return(node); 
} 

// A utility function to right 
// rotate subtree rooted with y 
// See the diagram given above. 
Node *leftrotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 				

	// Return new root 
	return x; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
Node *rightrotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left),	 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1;			

	// Return new root 
	return y; 
} 

// Get Balance factor of node N 
int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0;
	else
	{	 
	int max;
	max = height(N->left) - height(N->right); 
    cout<<"\nBalance ="<<max<<endl;
    return max;
	}
} 

// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree. 
Node* insert(Node* node, int key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (node == NULL) 
	{
		cout<<"\nYES \n";
		return(newNode(key)); 
	}

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else // Equal keys are not allowed in BST 
		return node; 
    
	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right));
	cout<<endl;					 
	cout<<"Node height = "<<node->height<<endl;					
	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 
	
	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
	{
		cout<<"\n-->Operation LL<<--\n";
		return leftrotate(node); 

	}

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
	{
		cout<<"\n-->Operation RR<<--\n";
		return rightrotate(node);
	}

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = rightrotate(node->left);
		cout<<"\n-->Operation LR<<--\n"; 
		return leftrotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = leftrotate(node->right); 
		cout<<"\n-->Operation RL<<--\n";
		return rightrotate(node); 

	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

// A utility function to print preorder 
// traversal of the tree. 
// The function also prints height 
// of every node 
void preOrder(Node *root) 
{ 
	if(root != NULL) 
	{ 
		cout << root->key << " "; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

// Driver Code 
int main() 
{ 
	Node *root = NULL; 
	while(1)
	{
		int n;
		cout<<"\n1.Insert\n";
		cout<<"2.Show\n";
		cout<<"Choice =";
		cin>>n;
		switch(n)
		{
			case 1:
				int i;
				cout<<"\nEnter the Element = ";
				cin>>i;
				root = insert(root,i);
				cout<<"\n--->Operation Completed<---\n";
				break;
			case 2:
			{
				cout<<"\nAVL Tree:";
				preOrder(root);
				break;
			}	
		}
    }
} 

