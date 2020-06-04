#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int a[20],i,j,del,size,count;
 cout<<"Size:";
 cin>>size;
 cout<<"Enter the elements:"<<endl;
 for(i=0;i<size;i++)
 {
  cin>>a[i];
 }
 cout<<"which one delete ? =";
 cin>>del;
 for(i=0;i<size;i++)
 {
  if(a[i]==del)
  {
   for(j=i;j<size-1;j++)
   {
    a[j]=a[j+1];
    }
    count++;
    break;
   }
 }
 if(count==0)
 {
  cout<<"Element Not Found.....";
  }
 else
 {
  cout<<"Element deleted ";
  cout<<"\n"<<"Updated array is:"<<endl;
  for(i=0;i<size-1;i++)
  {
   cout<<a[i]<<" ";
  }
  getch();
 }
 }
