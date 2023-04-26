#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
int n,i,co=0;
char c;
cin>>n;
cin>>c;
string s;
cin>>s;
int x=0;
for(i=0;i<n;i++)
{
if(s[i]==c){
x=i+1;
co++;
}
}
if(co==n)
{
cout<<0<<endl;
continue;
}
if(x>n/2)
cout<<"1\n"<<x<<endl;
else
cout<<"2\n"<<n<<" "<<n-1<<endl;
}
}