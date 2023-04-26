#include<bits/stdc++.h>
using namespace std;
int t, n, p[200001], v[200001];
int a[200005];
void dfs(int x, int father)
{
v[x]=1;
if(x!=p[x]&&!v[p[x]]) dfs(p[x],father+1);
else cout<<father<<endl;
cout<<x<<' ';
}
int main()
{
cin>>t;
while(t--)
{
cin>>n;
int cnt=n;
for(int i=1;i<=n;i++)
{
cin>>p[i];
if(i!=p[i]) cnt-=!a[p[i]]++;
}
cout<<cnt<<endl;
for(int i=1;i<=n;i++)
if(a[i]==0)
dfs(i,1),cout<<endl;
memset(a,0,sizeof a);
memset(v,0,sizeof v);
cout<<endl;
}
}