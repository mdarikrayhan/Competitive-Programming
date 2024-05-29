// LUOGU_RID: 157140056
#include<bits/stdc++.h>
#define N 200010
#define pii pair<int,int>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Down(i,a,b) for(register int i=a;i>=b;i--)
#define Edge(i,x) for(int i=head[x],to=e[i].t;i;i=e[i].nx,to=e[i].t)
using namespace std;
int n,m,cnt[N],seg[N],r[N],rev[N];
int rt[N],lc[N*40],rc[N*40],de[N],v[N];
int totnode,id[N],top[N],sum[N*40];
int nxt[N][26],lnk[N],len[N],num,tot;
int anc[N][20],head[N],sz[N],son[N],fail[N];
char s[N],t[N];
long long ans;
queue<pii> q;
struct E{int nx,t,v;}e[N<<1];
inline void add(int f,int t,int v){e[++num]=(E){head[f],t,v};head[f]=num;}
inline int read()
{
    register int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x;
}

inline int insert(int nd,int v)
{
    int nw=nxt[nd][v];
    len[nw]=len[nd]+1,nd=lnk[nd];
    while(nd && !nxt[nd][v]) nxt[nd][v]=nw,nd=lnk[nd];
    if(!nd) {lnk[nw]=1;return nw;}
    int q=nxt[nd][v];
    if(len[q] == len[nd]+1) {lnk[nw]=q;return nw;}
    int clone=++tot;
    len[clone]=len[nd]+1,lnk[clone]=lnk[q];
    For(i,0,25) if(len[nxt[q][i]]) nxt[clone][i]=nxt[q][i];
    while(nd && nxt[nd][v] == q) nxt[nd][v]=clone,nd=lnk[nd];
    lnk[q]=lnk[nw]=clone;
    return nw;
}

inline void modify(int &k,int l,int r,int pos)
{
    if(!k) k=++totnode;
    if(l == r) {sum[k]++;return;}
    int mid=l+r>>1;
    if(pos <= mid) modify(lc[k],l,mid,pos);
    else modify(rc[k],mid+1,r,pos);
    return void(sum[k]=sum[lc[k]]+sum[rc[k]]);
}

inline int query(int k,int l,int r,int x,int y)
{
    if(!k || l >= x && r <= y) return sum[k];
    int mid=l+r>>1,res=0;
    if(x <= mid) res+=query(lc[k],l,mid,x,y);
    if(mid < y) res+=query(rc[k],mid+1,r,x,y);
    return res;
}

inline int merge(int x,int y,int l,int r)
{
    if(!x || !y) return x+y;
    int k=++totnode,mid=l+r>>1;
    sum[k]=sum[x]+sum[y];
    lc[k]=merge(lc[x],lc[y],l,mid);
    rc[k]=merge(rc[x],rc[y],mid+1,r);
    return k;
}

inline int addin(int x,int v,int nw)
{
    if(!nxt[x][v]) nxt[x][v]=nw;
    modify(rt[nxt[x][v]],1,n,seg[nw]);
    return nxt[x][v];
}

inline void dfs1(int x,int fa)
{
    de[x]=de[fa]+1;
    anc[x][0]=fa,sz[x]=1;
    For(i,1,19) anc[x][i]=anc[anc[x][i-1]][i-1];
    Edge(i,x) if(to^fa)
    {
        v[to]=e[i].v-'a';
        dfs1(to,x),sz[x]+=sz[to];
        if(sz[to] > sz[son[x]]) son[x]=to;
    }
    return;
}

inline void dfs2(int x,int fa)
{
    if(son[x])
    {
        top[son[x]]=top[x];
        seg[son[x]]=++seg[0];
        rev[son[x]]=addin(rev[x],v[son[x]],son[x]);
        dfs2(son[x],x);
    }
    Edge(i,x) if(!top[to])
    {
        top[to]=to;
        seg[to]=++seg[0];
        rev[to]=addin(rev[x],v[to],to);
        dfs2(to,x);
    }
    return;
}

inline int get_lca(int x,int y)
{
    int fx=top[x],fy=top[y];
    for(;fx!=fy;x=anc[fx][0],fx=top[x])
        if(de[fx] < de[fy]) swap(fx,fy),swap(x,y);
    return de[x]<de[y]?x:y;
}

inline int jump(int x,int d)
{
    Down(i,19,0) if(de[anc[x][i]] >= d)
        x=anc[x][i];
    return x;
}

inline void build()
{
    For(i,0,25) if(nxt[1][i]) q.push(pii(1,i));
    while(!q.empty())
    {
        pii k=q.front();q.pop();
        int lst=insert(k.first,k.second);
        For(i,0,25) if(nxt[lst][i]) q.push(pii(lst,i));
    }
    return;
}

inline void get_fail(int n)
{
    for(int i=2,j=0;i<=n;i++)
    {
        while(j && t[i] != t[j+1]) j=fail[j];
        j+=t[i]==t[j+1],fail[i]=j;
    }
    return;
}

inline int ask(int x,int y,int nd)
{
    int res=0,fx=top[x],fy=top[y];
    for(;fx!=fy;x=anc[fx][0],fx=top[x])
    {
        if(de[fx] < de[fy]) swap(fx,fy),swap(x,y);
        res+=query(rt[nd],1,n,seg[fx],seg[x]);
    }if(de[x] > de[y]) swap(x,y);
    return res+query(rt[nd],1,n,seg[x],seg[y]);
}

int main()
{
    tot=n=read();
    For(i,1,n-1)
    {
        int x=read(),y=read(),c=getchar();
        while(!isalpha(c)) c=getchar();
        add(x,y,c),add(y,x,c);
    }seg[1]=top[1]=seg[0]=rev[1]=1;
    dfs1(1,0),dfs2(1,0),build();
    For(i,1,tot) cnt[len[i]]++;
    For(i,1,n) cnt[i]+=cnt[i-1];
    For(i,1,tot) r[cnt[len[i]]--]=i;
    Down(i,tot,2)
    {
        int x=r[i],f=lnk[x];
        rt[f]=merge(rt[f],rt[x],1,n);
    }m=read();
    For(ques,1,m)
    {
        int x=read(),y=read(),nlen;
        scanf("%s",s+1),nlen=strlen(s+1);
        int lca=get_lca(x,y),res=0;
        if(de[x]-de[lca] >= nlen)
        {
            int tx=jump(x,de[lca]+nlen),nd=1;
            Down(j,nlen,1) nd=nxt[nd][s[j]-'a'];
            if(nd) res+=ask(x,tx,nd);
        }
        if(de[y]-de[lca] >= nlen)
        {
            int ty=jump(y,de[lca]+nlen),nd=1;
            For(j,1,nlen) nd=nxt[nd][s[j]-'a'];
            if(nd) res+=ask(y,ty,nd);
        }int tx=jump(x,de[lca]+nlen-1);
        int ty=jump(y,de[lca]+nlen-1);
        int cntx=0,cnty=0;
        for(int nd=tx;nd!=lca;nd=anc[nd][0])
            t[++cntx]=v[nd]+'a';
        for(int nd=ty;nd!=lca;nd=anc[nd][0])
            t[cntx+(++cnty)]=v[nd]+'a';
        reverse(t+cntx+1,t+cntx+cnty+1);
        get_fail(nlen);
        for(int i=1,j=0;i<=cntx+cnty;i++)
        {
            while(j && t[i] != s[j+1]) j=fail[j];
            j+=t[i]==s[j+1];
            if(j == nlen) res++,j=fail[j];
        }printf("%d\n",res);
    }
    return 0;
}
