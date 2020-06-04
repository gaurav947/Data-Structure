#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int a[10],n,i,item,mid,beg,end;
 cout<<"How many items do you want to write:";
 cin>>n;
 cout<<"ok Please Write " << n <<" elements in Sequence vice:";
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 cout<<"Which item Do you Want to search sir ? ";
 cin>>item;
 beg=0;
 end=n-1;
while (beg<=end)
 {
   mid=(beg+end)/2 ;
   if (item==a[mid])
    {
     cout<<"Entered element "<< item << " at Position "<< mid+1;
     break;
    }
   if (item>a[mid])
    {
     beg=mid+1;
    }
   else
   {
    end=mid-1;
   }
}
if ( beg>end)
   {
    cout<<"Entered element "<< item <<" Not Found at any Position";
   }
   getch();
}
