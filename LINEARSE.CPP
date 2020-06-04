#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a[10],i,item,n;
cout<<"How many items:"<<endl;
cin>>n;
cout<<"ok Enter your items:"<<endl;
for(i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"Enter Which element do you want to search ?"<<endl;
cin>>item;
   for(i=0;i<n;i++)
    {
      if (a[i]==item)
	{
	  cout<<"Element "<<item<<" Found at Position "<< i+1;
	  break;
	}
     }
      if(a[i]!=n)
      {
       cout<<"NoT Found";
      }

getch();
}