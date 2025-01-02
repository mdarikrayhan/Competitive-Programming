#include<bits/stdc++.h>
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
#define foredge(i,j) for(register int i=head[j];i;i=e[i].nxt)
#define pb push_back
#define Times printf("Time:%.3lf\n",clock()/CLOCKS_PER_SEC)
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){write(x); puts("");}
inline void writepl(int x){write(x); putchar(' ');}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int randfind(int l,int r){return rnd()%(r-l+1)+l;}
//inline void init(){
//	int t=read();
//	while(t--) work();
//}
const int Maxn=60;
double C[Maxn][Maxn],fac[Maxn],ifac[Maxn],f[Maxn][Maxn],g[Maxn];
double tr[Maxn];
struct node{
    int nxt,to;
}e[Maxn<<1];
int head[Maxn],cnt;
inline void add(int u,int v){++cnt;e[cnt].nxt=head[u];head[u]=cnt;e[cnt].to=v;}
int n;
int siz[Maxn];
inline void init(){
    n=read();
    fr(i,1,n-1){
        int x,y;
        x=read();y=read();
        add(x,y);add(y,x);
    }
    fac[0]=ifac[0]=1;
    fr(i,1,n) fac[i]=1.0*fac[i-1]*i,ifac[i]=ifac[i-1]/(1.0*i);
    C[0][0]=1;
    fr(i,1,n){
        C[i][0]=1;
        fr(j,1,i) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
}
inline void dfs(int x,int fa){
    siz[x]=1;f[x][0]=1;
    for(register int i=head[x];i;i=e[i].nxt){
        int y;y=e[i].to;if(y==fa) continue;
        dfs(y,x);memset(g,0,sizeof(g));
        fr(j1,0,siz[y]) fr(j2,1,siz[y]){
            if(j2<=j1) g[j1]+=0.5*f[y][j2-1];
            else g[j1]+=f[y][j1];
        }memset(tr,0,sizeof(tr));
        fr(i,0,siz[x]-1) fr(j,0,siz[y]) tr[i+j]+=f[x][i]*g[j]*C[i+j][j]*C[siz[x]-i-1+siz[y]-j][siz[y]-j];
        fr(i,0,siz[x]+siz[y]-1) f[x][i]=tr[i];
        siz[x]+=siz[y];
    }
}
inline void work(){
    fr(i,1,n){
        memset(siz,0,sizeof(siz));
        memset(f,0,sizeof(f));
        dfs(i,0);
        printf("%.10lf\n",f[i][n-1]*ifac[n-1]);
    }
}
signed main(){
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
    init();work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}