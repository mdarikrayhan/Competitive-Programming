// LUOGU_RID: 159938788
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lson (t[pos].ls)
#define rson (t[pos].rs)
#define pii pair<int,int> 
#define fr first
#define sc second 
#define mk make_pair
#define pb push_back
#define yjbakioi true
#define inx int i=h[u],w=edge[i].w,v=edge[i].v;i;i=edge[i].nx,v=edge[i].v,w=edge[i].w
#define x1 lylakioi
#define y1 gczakioi
inline int read(){int x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}x=c-'0';c=getchar();while(c<='9'&&c>='0'){x*=10;x+=c-'0';c=getchar();}return x*f;}
const int MAXN=1000010,N=60,base=131,Mod=1011451423,Mod2=999911659,ie6=50000000,inf=1000'000'000'000'000'000,B=1000;
struct Edge{int v,w,nx;}edge[MAXN<<1];int h[MAXN],cur[MAXN],CNT;void init(){memset(cur,0,sizeof(cur));CNT=1;}
void add_side(int u,int v,int w){
    // cout<<u<<" "<<v<<" "<<w<<endl;
edge[++CNT]={v,w,cur[u]};cur[u]=CNT;edge[++CNT]={u,0,cur[v]};cur[v]=CNT;}
int n,m,s,t,cnt,d[MAXN];
int dfs(int u,int sum){
    if(u==t)return sum;
    int num=sum;
    for(inx){
        h[u]=i;
        if(d[v]!=d[u]+1)continue;
        int tmp=dfs(v,min(w,num));
        num-=tmp;edge[i].w-=tmp,edge[i^1].w+=tmp;
        if(!num)break;
    }
    return sum-num;
}
queue<int>Q;
bool bfs(){
    for(int i=1;i<=cnt;i++)h[i]=cur[i],d[i]=0;
    while(!Q.empty())Q.pop();
    Q.push(s);d[s]=1;
    bool fl=0;
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        if(u==t)fl=1;
        for(inx){
            if(w&&!d[v]){
                d[v]=d[u]+1;
                Q.push(v);
            }
        }
    }
    return fl;
}
int picnic(){
    int res=0;
    while(bfs()){
        res+=dfs(s,inf);
    }
    return res;
}
int k,a[MAXN],b[MAXN],p[MAXN],sum;
map<int,int>mp;
struct side{
    int u,v,w;
}S[MAXN];
bool check(int d){
    init();
    // cout<<d<<":"<<endl;
    for(int i=1;i<=m;i++){
        add_side(S[i].u,S[i].v,S[i].w/d);
        // cout<<S[i].u<<" "<<S[i].v<<" "<<S[i].w/d<<endl;
    }
    s=1,t=n;cnt=n;
    int tmp=picnic();
    // cout<<tmp<<endl;
    return tmp>=k;
}
void slv(){
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++){
        S[i].u=read(),S[i].v=read(),S[i].w=read();
        S[i].w*=ie6;
    }
    int l=0,r=inf;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)){
            l=mid;
        }
        else r=mid-1;
    }
    // cout<<l<<endl;
    printf("%.6f",l*k*1.0/ie6);
}
signed main(){
// 	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    // int _=read();while(_--)
	slv();
    // cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    return 0;
} 	