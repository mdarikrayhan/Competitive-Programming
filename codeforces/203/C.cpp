#include<bits/stdc++.h>
using namespace std;
int n,a,b,i,x,y,d,m;
main(){
pair<int,int> c[100001];

cin>>n>>d>>a>>b;
for(i=1; i<=n; i++)
{
cin>>x>>y;
c[i].first=a*x+b*y; c[i].second=i;
}
sort(c+1,c+n+1);
for(i=1; i<=n; i++)
{
d-=c[i].first;
if(d>=0) m++;
else break;
}
cout<<m<<endl;
for(i=1; i<=m; i++)
cout<<c[i].second<<" ";
}