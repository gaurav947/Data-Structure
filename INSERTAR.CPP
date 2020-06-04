#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int a[10],i,n,insert,pos,size,r,u,flag=0;
 char k;
 cout<<"Enter the size of array:";
 cin>>size;
 cout<<"Enter the elements in the array:"<<endl;
 for (i=0;i<size;i++)
 {
  cin>>a[i];
 }
 u:
 if (flag==1)
 {
  size=size+1;
  goto q;
 }
 if (flag==0)
 {
  goto q;
 }
 q:
 cout<<"Enter the element to be inserted:";
 cin>>insert;
 cout<<"ENter position:";
 cin>>r;
 pos=r-1;
 for(i=size;i>pos;i--)
 {
  a[i]=a[i-1];
 }
 a[pos]=insert;
 cout<<"Element inserted sucessfully......."<<endl;
 cout<<"Updated Array is..."<<endl;
 for(i=0;i<size+1;i++)
 {
  cout<<a[i]<<" ";
 }
 cout<<"\n"<<"Do you want to insert more (y : n)";
 cin>>k;
 if(k=='y')
 {
  flag=1;
  goto u;
 }
 else
 {
  cout<<"OK Press Any Key To Leave...";
 }
getch();
}