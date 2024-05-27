#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
#define fr(i,l,r) for (i=(l); i<=(r); i++)
#define rfr(i,l,r) for (i=(l); i>=(r); i--)
template<typename T>inline void read(T &n){
    T w=1; n=0; char ch=getchar();
    while (!isdigit(ch) && ch!=EOF){ if (ch=='-') w=-1; ch=getchar(); }
    while (isdigit(ch) && ch!=EOF){ n=(n<<3)+(n<<1)+(ch&15); ch=getchar(); }
    n*=w;
}
template<typename T>inline void write(T x){
    if (x==0){ putchar('0'); return ; }
    T tmp;
    if (x>0) tmp=x;
    else tmp=-x;
    if (x<0) putchar('-');
    char F[105];
    long long cnt=0;
    while (tmp){
        F[++cnt]=tmp%10+48;
        tmp/=10;
    }
    while (cnt) putchar(F[cnt--]);
}
#define Min(x,y) x = min(x,y)
#define Max(x,y) x = max(x,y)
//基础配置=================================================================================
const ll N = 100005;
ll n,m,ans=0,x,y,l,r,s,z,S,T;
struct edge{
    ll x,y,w,dir;
};
ll cnt=0,head[N]; edge e[2*N];
void addedge(ll x,ll y,ll w,ll dir){
    cnt++;
    e[cnt].x = head[x];
    e[cnt].y = y;
    e[cnt].w = w;
    e[cnt].dir = dir;
    head[x] = cnt;
}
ll X[N],Y[N],Z[N];
ll f[2][N];
struct node{
    ll x,v;
    node(ll _x=0,ll _v=0){
        x = _x; v = _v;
    }
    bool operator < (const node o)const{
        return v>o.v;
    }
};
void dij(ll x,ll o){
    // printf("\n\n\n dij %lld %lld\n",x,o);
    ll i;
    memset(f[o],0x3f,sizeof(f[o]));
    f[o][x] = 0;
    priority_queue<node> q;
    q.push(node(x,0));
    while (!q.empty()){
        node p = q.top(); q.pop();
        ll x = p.x;
        if (p.v>f[o][x]) continue;
        // printf("f[%lld][%lld] = %lld\n",o,x,f[o][x]);
        for (i=head[x]; i; i=e[i].x){
            ll go = e[i].y;
            // if (e[i].dir==o && f[o][x]+e[i].w==f[o][go]){
            //     f[o][go] = f[o][x]+e[i].w;
            //     g[o][go] = f[o][go];
            //     q.push(node(go,f[o][go]));
            // }
            if (e[i].dir==o && f[o][x]+e[i].w<f[o][go]){
                f[o][go] = f[o][x]+e[i].w;
                // g[o][go] = f[o][go];
                q.push(node(go,f[o][go]));
            }
        }
    }
}
struct Edge{
    ll y,w,id;
    Edge(ll _y=0,ll _w=0,ll _id=0){
        y = _y; w = _w; id = _id;
    }
};
vector<Edge> c[N];
ll opt[N];
ll tms,dfn[N],low[N];
void dfs(ll x,ll tid){
    ll i; ll go;
    dfn[x] = low[x] = ++tms;
    for (i=0; i<c[x].size(); i++){
        if (c[x][i].id==tid) continue;
        go = c[x][i].y;
        if (!dfn[go]){
            dfs(go,c[x][i].id);
            Min(low[x],low[go]);
        }
        else Min(low[x],dfn[go]);
    }
    if (dfn[x]==low[x] && tid>0) opt[tid] = true;
    // printf("%lld : dfn = %lld , low = %lld\n",x,dfn[x],low[x]);
}
int main(){
	// freopen("a.in","r",stdin);
//	freopen(".out","w",stdout);
    ll i,j;
    read(n); read(m); read(S); read(T);
    fr(i,1,m){
        ll x,y,z;
        read(x); read(y); read(z);
        addedge(x,y,z,1);
        addedge(y,x,z,0);
        X[i] = x; Y[i] = y; Z[i] = z;
    }
    dij(S,1);
    dij(T,0);
    ll val = f[1][T];
    fr(i,1,m){
        ll x = X[i], y = Y[i], z = Z[i];
        if (f[1][x]+z+f[0][y]==val){
            c[x].push_back(Edge(y,z,i));
            c[y].push_back(Edge(x,z,i));
            // printf("%lld --> %lld , id = %lld\n",x,y,i);
        }
    }
    dfs(S,-1);
    fr(i,1,m){
        if (opt[i]) printf("YES\n");
        else {
            ll x = X[i], y = Y[i], z = Z[i];
            ll dlt = f[1][x] + z + f[0][y] - val + 1;
            if (dlt<z) printf("CAN %lld\n",dlt);
            else printf("NO\n");
        }
    }
    return 0;
}
//g++ a.cpp -o a -Wall -Wl,--stack=512000000 -std=c++11 -O2