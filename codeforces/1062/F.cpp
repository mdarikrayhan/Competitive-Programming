// LUOGU_RID: 160400418
#include<bits/stdc++.h>
#define txinf 761125761137835809ll
#define int long long
using namespace std;
const int N=1145141;
int n,m,st[N],ed[N],f[N],deg[N];
vector<int>z[N];
bool check(int x){
    bool ok=true;
    for(auto&y:z[x])if(deg[y]==1)ok=false;
    return ok;
}
void Fisica(){
    for(int i=1;i<=n;i++)z[i].clear(),deg[i]=0;
    for(int i=0;i<m;i++)z[st[i]].push_back(ed[i]),deg[ed[i]]++;
    queue<int>q;for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
    for(int i=1;i<=n;i++){
        int t=q.front();q.pop();
        if(q.size()==0)f[t]+=n-i;
        else if(q.size()==1){
            if(check(q.front()))f[t]+=n-i-1;
            else f[t]-=txinf/233333;
        }else f[t]-=txinf/233333;
        for(auto&x:z[t])if(!--deg[x])q.push(x);
    }for(int i=0;i<m;i++)swap(st[i],ed[i]);
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>st[i]>>ed[i];
    Fisica(),Fisica();
    int s=0;for(int i=1;i<=n;i++)if(f[i]>=n-2)s++;
    cout<<s<<'\n';
}