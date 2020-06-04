#include<iostream>
#include<stdlib.h>
using namespace std;
int n=100,stack[100],choose,top=-1,i;
void peep()
{
	if(top==-1)
	{
		cout<<endl;
		cout<<"Stack is Empty"<<endl;
	}
	else
	{
		cout<<stack[top]<<endl;
	}
}
void push()
{
	int val;
	if(top==n-1)
	{
		cout<<endl;
		cout<<"***Overflow"<<endl;
	}
	else
	{
		cout<<"Enter the Element = ";
		cin>>val;
		top = top+1;
		stack[top]=val;
	}
}
void pop()
{
	if(top==-1)
	{
		cout<<endl;
		cout<<"Underflow"<<endl;
	}
	else
	{
		top = top-1;
	}
	
}

void show()
{
	if(top==-1)
	{
		cout<<endl;
		cout<<"Stack is Empty"<<endl;
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			cout<<stack[i]<<endl;
		}
	}
}
int main()
{
	cout<<endl;
	cout<<"Enter the Size of stack = ";
	cin>>n;
	while(1)
	{ 
	cout<<".........Now Choose the OPTION below........"<<endl;
	cout<<"1.Push"<<endl;
	cout<<"2.Pop"<<endl;
	cout<<"3.Peep"<<endl;
	cout<<"4.Show"<<endl;
	cout<<"5.Exit"<<endl;
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
		case 3:
		  peep();
		  break;  
		case 4:
		   show();
		   break;
		case 5:
		  exit(0);
		  break;
		default:
		   cout<<endl;
		   cout<<"**Please write Correct choice**"<<endl;       	
			
	}
	}
}
