#include <bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
{ int n;int o=0;bool p=1;
cin>>n;
int a[n];
int a1[n];

for(int i=0;i<n;i++)
{
    cin>>a[i];
}
for(int i=0;i<n;i++)
{
    cin>>a1[i];
    o=max(o,a[i]-a1[i]);
}
for(int i=0;i<n;i++)
{
 if(a[i]-o<a1[i]&& a1[i]!=0)
     p=0;
}
if(p)
    cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
}
