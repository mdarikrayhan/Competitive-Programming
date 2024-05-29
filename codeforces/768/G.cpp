// LUOGU_RID: 159911514
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;
int n,m,root;
int h[N],num,ne[M],to[M];
int fa[N],si[N],son[N];
multiset<int>st,last,p[N];
int maxn[N],sum[N],minn[N];
int ans[N];
void add(int a,int b){
    ne[num]=h[a],to[num]=b,h[a]=num++;
}
void dfs(int u,int father){
    fa[u]=father,si[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=to[i];
        if(j==father) continue;
        dfs(j,u);
        si[u]+=si[j];
        if(si[son[u]]<si[j]) son[u]=j;
    }
    if(u!=root) st.insert(si[u]);
    return;
}
bool check(int v,int u){
    if(maxn[u]==si[son[u]]){
        auto it=p[u].lower_bound(maxn[u]-v);
        if(it!=p[u].end() && *it<=v-minn[u]) return true;
        return false;
    }
    auto it=st.lower_bound(maxn[u]-v);
    if(it!=st.end() && *it<=v-minn[u]) return true;
    it=last.lower_bound(maxn[u]-v+si[u]);
    if(it!=last.end() && *it<=v-minn[u]+si[u]) return true;
    return false;
}
void calc(int u,int father){
    if(u!=root){
        st.erase(st.find(si[u]));
        if(fa[u]!=root) last.insert(si[fa[u]]);
    }
    maxn[u]=max(n-si[u],si[son[u]]);
    sum[u]=min(n-si[u],si[son[u]]);
    minn[u]=n-si[u];
    for(int i=h[u];~i;i=ne[i]){
        int j=to[i];
        if(j==father || j==son[u]) continue;
        calc(j,u);
        for(int x:p[j]) st.insert(x);
    }
    if(son[u]){
        calc(son[u],u);
        swap(p[u],p[son[u]]);
        minn[u]=min(minn[u],si[son[u]]);
        if(!minn[u]) minn[u]=si[son[u]];
    }
    for(int i=h[u];~i;i=ne[i]){
        int j=to[i];
        if(j==father || j==son[u]) continue;
        minn[u]=min(minn[u],si[j]);
        sum[u]=max(sum[u],si[j]);
        for(int x:p[j]) st.erase(st.find(x));
    }
    if(maxn[u]!=sum[u]){
        int l=sum[u],r=maxn[u];
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid,u)) r=mid;
            else l=mid+1;
        }
        if(check(r,u)) ans[u]=r;
    }
    if(!ans[u]) ans[u]=maxn[u];
    for(int i=h[u];~i;i=ne[i]){
        int j=to[i];
        if(j==father || j==son[u]) continue;
        for(int x:p[j]) p[u].insert(x);
    }
    if(u!=root && fa[u]!=root) last.erase(last.find(si[fa[u]]));
    p[u].insert(si[u]);
    return;
}
int main(){
    scanf("%d",&n);
    memset(h,-1,sizeof(h));
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(!u || !v) root=u+v;
        else add(u,v),add(v,u);
    }
    // cout<<"!"<<root<<endl;
    dfs(root,0);
    calc(root,0);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}