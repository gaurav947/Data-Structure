#include<iostream>
#include<stdlib.h>
using namespace std;
int queue[100],n=100,front = -1,rear = -1,i;
void Inqueue()
{
	int val;
	if(rear==n-1)
	{
		cout<<endl;
		cout<<" Queue Overflow"<<endl;
	}
	else
	{
		if(front == -1)
		{
			front = 0;
		}
		cout<<"ok.. Insert your Element in Queue = ";
		cin>>val;
		rear = rear+1;
		queue[rear] = val;
	}
}
void dequeue()
{
	if(front==-1 || front>rear)
	{
		cout<<endl;
		cout<<"Queue is Underflow"<<endl;
	}
	else
	{
		cout<<endl;
		cout<<"Element delete from Queue is : "<<queue[front];
		front = front+1;
	}
}
void peep()
{
	if(front == -1 || rear ==-1 )
	{
		cout<<endl;
		cout<<"***List is Empty"<<endl;
	}
	else
	{
		cout<<"Peep Operation :";
		cout<<queue[front]<<" ";
	}
	
}
void show()
{
	if(front == -1 )
	{
		cout<<endl;
		cout<<"**List is Empty";
	}
	else
	{
		cout<<endl;
		cout<<"Queue :";
		for(i=front;i<=rear;i++)
		{
			cout<<queue[i]<< " ";
		}
		cout<<endl;
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
				 Inqueue();
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
