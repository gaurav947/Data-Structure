#include<iostream>
using namespace std;
int main()
{
  int a[10][20];
 int i,j,c,r;
 cout<<"Enter the size of Row:";
 cin>>c;
 cout<<"Enter the size of column:";
 cin>>r;
 cout<<"Enter the elements in row:"<<endl;
 for(i=0;i<c;i++)
 {
  for(j=0;j<r;j++)
  {
   cin>>a[i][j];

  }
   cout<<"\n";
  }
 cout<<"Yours Entered elements are:"<<endl;
 for(i=0;i<c;i++)
 {
  for(j=0;j<r;j++)
  {
   cout<<a[i][j]<<" ";
  }
   cout<<"\n";
 }

 }
