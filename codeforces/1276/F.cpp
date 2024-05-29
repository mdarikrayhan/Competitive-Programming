// LUOGU_RID: 156375754
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;
const int N=2e5+5;
const int M=N*20;
int n,ed[N],ed0[N];
string str;
struct sam{
    int last,tot,dfn[N],num,sz[N],rk[N],f[20][N];
    struct node{
        int link,to[26],len;
    }t[N];
    vector<int>G[N];
    sam(){t[0].link=-1;}
    void extend(int c){
        int cur=++tot,p=last;
        t[cur].len=t[p].len+1;
        while(p!=-1&&!t[p].to[c]){
            t[p].to[c]=cur;
            p=t[p].link;
        }
        if(p!=-1){
            int q=t[p].to[c];
            if(t[q].len==t[p].len+1){
                t[cur].link=q;
            }
            else{
                int clone=++tot;
                t[clone].len=t[p].len+1,t[clone].link=t[q].link;
                for(int i=0;i<26;i++)t[clone].to[i]=t[q].to[i];
                while(p!=-1&&t[p].to[c]==q){
                    t[p].to[c]=clone;
                    p=t[p].link;
                }
                t[q].link=t[cur].link=clone;
            }
        }
        last=cur;
    }
    void dfs(int u,int topf){
        f[0][dfn[u]=++num]=topf,rk[num]=u,sz[u]=1;
        for(auto v:G[u]){
            dfs(v,u),sz[u]+=sz[v];
        }
    }
    int Lca(int x,int y){
        if(x==y)return x;
        if((x=dfn[x])>(y=dfn[y]))swap(x,y);
        int k=__lg(y-x++);
        return dfn[f[k][x]]<dfn[f[k][y-(1<<k)+1]]?f[k][x]:f[k][y-(1<<k)+1];
    }
    void build(){
        for(int i=1;i<=tot;i++)G[t[i].link].pb(i);
        dfs(0,0);
        for(int i=1;i<=__lg(num);i++){
            for(int j=1;j<=num-(1<<i)+1;j++){
                f[i][j]=(dfn[f[i-1][j]]<dfn[f[i-1][j+(1<<i-1)]])?f[i-1][j]:f[i-1][j+(1<<i-1)];
            }
        }
    }
    int get(int x){
        return t[x].len-t[t[x].link].len;
    }
    int id(int x){
        return dfn[x];
    }
    int get0(int x){
        return t[rk[x]].len;
    }
    int qry(int x,int y){
        x=rk[x],y=rk[y];
        return t[y].len-t[Lca(x,y)].len;
    }
}sam[2];
int lim,rt[N],tot,ls[M],rs[M],fl[M],fr[M],vs[N],vs0[N];
ll res=2,sm[M];
void dfs(int u){
    for(auto v:sam[0].G[u]){
        dfs(v),vs[u]|=vs[v];
    }
    if(u)res+=sam[0].get(u);
    if(u&&vs[u])res+=sam[0].get(u);
}
void dfs0(int u){
    for(auto v:sam[1].G[u]){
        dfs0(v),vs0[u]|=vs0[v];
    }
    if(u&&vs0[u])res+=sam[1].get(u);
}
void pushup(int p){
    fl[p]=min(fl[ls[p]],fl[rs[p]]);
    fr[p]=max(fr[ls[p]],fr[rs[p]]);
    sm[p]=sm[ls[p]]+sm[rs[p]];
    if(ls[p]&&rs[p])sm[p]+=sam[1].qry(fr[ls[p]],fl[rs[p]]);
}
void ins(int &p,int l,int r,int x){
    p=++tot;
    if(l==r){
        fl[p]=fr[p]=x;
        return;
    }
    int mid=l+r>>1;
    x<=mid?ins(ls[p],l,mid,x):ins(rs[p],mid+1,r,x);
    pushup(p);
}
int merge(int p,int q,int l,int r){
    if(!p||!q)return p+q;
    if(l==r)assert(0);
    int mid=l+r>>1;
    ls[p]=merge(ls[p],ls[q],l,mid);
    rs[p]=merge(rs[p],rs[q],mid+1,r);
    pushup(p);
    return p;
}
void dfs1(int u){
    for(auto v:sam[0].G[u]){
        dfs1(v);
        rt[u]=merge(rt[u],rt[v],1,lim);
    }
    if(u&&rt[u]){
        res+=sam[0].get(u)*(sm[rt[u]]+sam[1].get0(fl[rt[u]]));
    }
}
int main(){
    //freopen("data.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>str,n=str.size();
    for(int i=0;i<n;i++)sam[0].extend(str[i]-'a'),ed[i]=sam[0].last;
    for(int i=n-1;i>=0;i--)sam[1].extend(str[i]-'a'),ed0[i]=sam[1].last;
    sam[0].build(),sam[1].build();
    for(int i=0;i<n-1;i++)vs[ed[i]]=1;
    dfs(0);
    for(int i=1;i<n;i++)vs0[ed0[i]]=1;
    dfs0(0);
    fl[0]=inf,fr[0]=0;
    lim=sam[1].num;
    for(int i=0;i<n-2;i++){
        ins(rt[ed[i]],1,lim,sam[1].id(ed0[i+2]));
    }
    dfs1(0);
    cout<<res;
}