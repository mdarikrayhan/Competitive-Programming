#include <bits/stdc++.h>
using namespace std;
long t,tt,n,m,sv[100005];
int main(){
cin.tie(0); ios::sync_with_stdio(0);
for(cin >> t;t--;cout << n << '\n'){
cin >> n >> m;
for(int i=0;i<m;++i)cin >> sv[i];
sort(sv,sv+m);
sv[m]=sv[tt=0]+n;
for(int i=0;i<m;++i)
if(sv[i+1]-sv[i]>1)
sv[tt++]=sv[i+1]-sv[i]-1;
sort(sv,sv+tt);
for(int i=tt-1,j=1;i>=0&&j<=sv[i];--i,j+=4)
n-=max(sv[i]-j,(long)1);
}
}