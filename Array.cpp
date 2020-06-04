#include<iostream>
using namespace std;
int main()
{
    int a[10],n,i;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"OK enter yOur element:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Entered elements are:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
