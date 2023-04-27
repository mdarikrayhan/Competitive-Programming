#include <bits/stdc++.h>
using namespace std;
main()
{
int t; cin>>t; while (t--)
{
int n,m; cin>>n>>m;
int y=1;
string ans[2]={"NO\n","YES\n"};
for (int i=0; i<n; ++i,ans[1]+="\n")
for (int j=0; j<m; ++j)
{
int a; cin>>a;
int b=(i>0)+(i<n-1)+(j>0)+(j<m-1);
if (a<=b) ans[1]+=to_string(b)+" "; else y=0;
}
cout<<ans[y];
}
}