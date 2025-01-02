#include<iostream>
using namespace std;
int T;
int l,r,x,a,b;
int main()
{
cin>>T;
while(T--)
{
cin>>l>>r>>x>>a>>b;
if(a>b)swap(a,b);
int res=-1;
if(a==b)res=0;
else if(abs(a-b)>=x)res=1;
else if(b+x<=r||a-x>=l)res=2;
else
{
if(b-x>=l&&a+x<=r)res=3;
}
cout<<res<<endl;
}
}