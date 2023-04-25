#include <bits/stdc++.h>
using namespace std;

int main()
{
int T;cin>>T;while(T--){
int n;cin>>n;
map<int,int> c;
bool ans=false;
vector< vector<int> > a(n);
for(int i=0;i<n;i++){
int k;cin>>k;
a[i].resize(k);
for(int j=0;j<k;j++)
cin>>a[i][j],c[a[i][j]]++;
}
for(int i=0;i<n;i++){
bool tf=true;
for(int j:a[i])
if(c[j]==1)tf=false;
ans|=tf;
}
puts(ans?"YES":"NO");
}
}