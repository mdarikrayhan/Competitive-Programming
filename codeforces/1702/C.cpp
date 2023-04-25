#include <bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
map<int,int> a,b;
int n,k,x,y;
cin>>n>>k;
for(int i=1,p;i<=n&&cin>>p;++i)a[p]==0?a[p]=i:b[p]=i;
while(k--&&cin>>x>>y)cout<<((a[x]==0||a[y]==0)?"No":(b[y]==0?(a[x]<a[y]?"Yes":"No"):(a[x]<b[y]?"Yes":"No")))<<endl;
}
return 0;
}