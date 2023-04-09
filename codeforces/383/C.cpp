#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,q,cur,a[N],l[N],r[N],d[N];
vector<int>e[N];
struct fenwick_tree{
int tr[N];
void clr(){
memset(tr,0,sizeof tr);
}
void add(int x,int y){
for(;x<N;x+=x&-x)tr[x]+=y;
}
int ask(int x){
return x?ask(x&(x-1))+tr[x]:0;
}
void add(int l,int r,int k){
add(l,k),add(r+1,-k);
}
};
fenwick_tree tr[2];
void dfs(int x,int fa){
l[x]=++cur,d[x]=!d[fa];
reverse(e[x].begin(),e[x].end());
for(int y:e[x])if(y^fa)dfs(y,x);
r[x]=cur;
}
int main(){
ios::sync_with_stdio(0);
cin>>n>>q;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1,x,y;i<n;i++)
cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
dfs(1,0);
for(int op,x,y;q--;){
if(cin>>op>>x,op<2)
cin>>y,tr[d[x]].add(l[x],r[x],y),tr[!d[x]].add(l[x],r[x],-y);
else cout<<a[x]+tr[d[x]].ask(l[x])<<"\n";
}
}