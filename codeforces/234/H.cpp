#include<bits/stdc++.h>
using namespace std;const int INF=1e9,MAX=1e5+9;int n,m,a[MAX],b[MAX],c[MAX*2],d[MAX*2];int main(){ifstream cin("input.txt");ofstream cout("output.txt");ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);cin>>n;for(int i=1;i<=n;i++)cin>>a[i];cin>>m;for(int i=1;i<=m;i++)cin>>b[i];int j=n+m,turn=0,p1=n,p2=m,cnt=0;while(j)if(p1&&a[p1]==turn)c[j--]=p1,p1--;else if(p2&&b[p2]==turn)c[j--]=p2+n,p2--;else turn^=1,d[cnt++]=j;for(int i=1;i<=n+m;i++)cout<<c[i]<<" ";cout<<endl<<cnt<<endl;for(int i=cnt-1;i>=0;i--)cout<<d[i]<<" ";}