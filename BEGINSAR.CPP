#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int a[5],i,j,beg,n;
 cout<<"size:";
 cin>>n;
 cout<<"ok enter:"<<endl;
 for(i=0;i<n;i++)
 {
 cin>>a[i];

 }
 cout<<"Insert at beg:";
 cin>>beg;
 for (i=n;i>0;i--)
 {
  a[i]=a[i-1];
 }
 a[0]=beg;
 cout<<"sucess"<<endl;
 for(i=0;i<n+1;i++)
 {
  cout<<a[i]<<" " ;
  }
  getch();
  }