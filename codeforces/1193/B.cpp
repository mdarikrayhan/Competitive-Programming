// LUOGU_RID: 160003532
#include<bits/stdc++.h>
#define int long long
#define iter map<int,int>::iterator
using namespace std;
const int MAXN=1e5+5;
map<int,int>f[MAXN];
int fa[MAXN],v[MAXN],d[MAXN],w[MAXN];
int n,m,k;
int rt[MAXN];
void merge(int& a,int b){
    if(f[a].size()<f[b].size())swap(a,b);
    for(iter it=f[b].begin();it!=f[b].end();it++)
        f[a][it->first]+=it->second;
}
signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=2;i<=n;i++)cin>>fa[i];
    for(int i=1,id;i<=m;i++){
        cin>>id;cin>>d[id]>>w[id];
    }
    for(int i=1;i<=n;i++)rt[i]=i;
    for(int i=n;i>=1;i--){
        f[rt[i]][d[i]]+=w[i];
        iter it;
        for(it=f[rt[i]].find(d[i]),it++;it!=f[rt[i]].end();){
            if(it->second>=w[i]){
                it->second-=w[i];
                break;
            }
            w[i]-=it->second;
            iter tmp=it;it++;
            f[rt[i]].erase(tmp);
        }
        merge(rt[fa[i]],rt[i]);
    }
    int ans=0;
    for(iter it=f[rt[1]].begin();it!=f[rt[1]].end();it++)
        ans+=it->second;
    cout<<ans<<"\n";
}