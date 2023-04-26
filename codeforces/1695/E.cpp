#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=600013;
vector<pair<int,int>>mp[N];
vector<int> tmp;
int ans[2][N],vis[N],vise[N],id;
void dfs(int x){
tmp.push_back(x);
if(!vis[x]){vis[x]=1;
for(auto [i,id]:mp[x])if(!vise[id]){
vise[id]=1;dfs(i);
tmp.push_back(x);
}
}
}
int main() {
int n;cin>>n;
string p1(n,'U'),p2(n,'D'),m1(n,'U'),m2(n,'D');
for(int i=1,x,y;i<=n;i++)cin>>x>>y,mp[x].push_back({y,i}),mp[y].push_back({x,i});
for(int i=1;i<=n+n;i++)if(!vis[i]){
dfs(i);tmp.pop_back();
int k=tmp.size()/2;
if(k==1)return cout<<-1<<'\n',0;
for(int j=0;j<k;j++)ans[0][j+id]=tmp[j],ans[1][j+id]=tmp[2*k-1-j];
for(int j=0;j<k-1;j+=2)p1[j+id]=p2[j+id]='L',p1[j+1+id]=p2[j+1+id]='R';
for(int j=1;j<k-1;j+=2)m1[j+id]=m2[j+id]='L',m1[j+1+id]=m2[j+1+id]='R';
tmp.clear(),id+=k;
}
cout<<"2 "<<n<<'\n';
for(int i=0;i<2;i++,cout<<"\n")for(int j=0;j<n;j++)cout<<ans[i][j]<<' ';
cout<<p1<<'\n'<<p2<<'\n'<<m1<<'\n'<<m2<<'\n';
}