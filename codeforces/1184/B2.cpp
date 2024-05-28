// LUOGU_RID: 159959539
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
const int MAN=2000010,MAXN=3010,N=310,base=131,Mod=1011451423,Mod2=999911659,ie6=50000000,inf=1000'000'000,B=1000;
struct Edge{int v,w,nx;}edge[MAN<<1];int h[MAN],cur[MAN],CNT;void init(){memset(cur,0,sizeof(cur));CNT=1;}
void add_side(int u,int v,int w){
    // cout<<u<<" "<<v<<" "<<w<<endl;
edge[++CNT]={v,w,cur[u]};cur[u]=CNT;edge[++CNT]={u,0,cur[v]};cur[v]=CNT;}
int n,m,s,t,cnt,d[MAN];
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
    // cout<<s<<" "<<t<<endl;
    int res=0;
    while(bfs()){
        res+=dfs(s,inf);
    }
    return res;
}
int a[MAXN],p,q,f,g,dis[MAXN][MAXN];
vector<int>G[MAXN];
queue<int>st;
void Bfs(int frm,int sum){
    st.push(frm);
    dis[frm][frm]=0;
    while(!st.empty()){
        int u=st.front();st.pop();
        for(auto v:G[u])if(!dis[frm][v]&&v!=u){
            dis[frm][v]=dis[frm][u]+1;
            st.push(v);
        }
    }
}
int atk[MAXN],rl[MAXN],pri[MAXN];
void slv(){init();
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        G[u].pb(v);G[v].pb(u);
    }
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    for(int i=1;i<=n;i++)Bfs(i,0);
    p=read(),q=read(),f=read(),g=read();
    for(int i=1;i<=p;i++){
        a[i]=read(),atk[i]=read(),rl[i]=read();
    }
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    // cout<<p<<" "<<q<<" "<<f<<" "<<g<<endl;
    cnt=p+q;s=++cnt,t=++cnt;
    // cout<<cnt<<endl;    
    for(int i=1;i<=q;i++){
        int x=read(),d=read();
        add_side(s,i,1);
        for(int j=1;j<=p;j++){
            if(dis[x][a[j]]<=rl[j]&&d<=atk[j]){
                // cout<<dis[x][a[j]]<<" "<<rl[j]<<"  "<<i<<" "<<j<<"-"<<endl;
                add_side(i,j+q,1);
            }
        }
    }
    for(int i=1;i<=p;i++)add_side(i+q,t,1);
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    int sum=picnic();
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    if(g>f){
        printf("%lld",sum*f);
    }
    else{
        printf("%lld",min(sum*f,p*g));
    }
}
signed main(){
// 	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    // int _=read();while(_--)
	slv();
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    return 0;
} 	