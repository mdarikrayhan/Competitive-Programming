#include<iostream>
using namespace std;
int main()
{
long long int t,b,r,n,i;
int a[4];
cin>>t;
for(i=0;i<t;i++)
{ int m=0;
    for(int j=0;j<3;j++)
{

    cin>>a[j];
    m=max(m,a[j]);

}
r=(3*m-(a[0]+a[1]+a[2]));
cin>>n;
b=(n-r);
  if(n<r)
    cout<<"NO"<<endl;
  else if(b%3==0)
 cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
}
 return 0;
}
