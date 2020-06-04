#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int a[10],i,j,n,last;
 cout<<"size:";
 cin>>n;
 cout<<"ok enter:"<<endl;
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 cout<<"insert at last :";
 cin>>last;
 n=n+1
 a[n-1]=last;
 cout<<"done"<<endl;
 for(i=0;i<n+1;i++)
 {
  cout<<a[i]<<" ";
  }
 getch();
 }