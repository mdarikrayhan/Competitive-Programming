#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
#define foredge(i,j) for(register int i=head[j];i;i=e[i].nxt)
#define pb push_back
#define Times printf("Time:%.3lf\n",clock()/CLOCKS_PER_SEC)
#define pii pair<int,int>
#define mk make_pair
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
const int Maxn=2e4+10;
vector<pii> que[Maxn];
int dep[Maxn];
int answer[Maxn];
int n,q;
int ed[Maxn<<1];
char C[Maxn<<1];
vector<pair<int,char> > ED[Maxn];
int x[Maxn],y[Maxn];
char chr[Maxn];
int fir[Maxn],ls[Maxn];
inline void init(){
    cin>>n>>q;
    fr(i,1,n-1) cin>>x[i]>>y[i]>>chr[i],ED[x[i]].pb(mk(y[i],chr[i])),ED[y[i]].pb(mk(x[i],chr[i]));
    int nod=0;
    fr(i,1,n){
        fir[i]=nod+1;
        for(auto k:ED[i]) ed[++nod]=k.first,C[nod]=k.second;
        ls[i]=nod;
    }
    fr(i,1,q){
        int x,y;
        cin>>x>>y;
        que[x].pb(mk(y,i));
    }
}
char ch[Maxn];
int vis[Maxn];
char stk[Maxn];
int top;
int Queue[Maxn],father[Maxn];
inline void getans(int x,int y){
    int point=x;
    while(father[point]) stk[dep[point]]=ch[point],point=father[point];
    top=dep[x];stk[top+1]='0';
    // if(q==1) cout<<top<<endl;
    // fr(i,1,top) cout<<stk[i];cout<<endl;
    // fr(i,1,n) vis[i]=0;
    int tmp;
    for(register int i=2;i<=n;++i) {
        tmp=Queue[i];
        if(vis[father[tmp]]!=0) vis[tmp]=vis[father[tmp]];
        else vis[tmp]=(ch[tmp]<stk[dep[tmp]])-(stk[dep[tmp]]<ch[tmp]);
        answer[y]+=(vis[tmp]==1 || (vis[tmp]==0 && dep[tmp]<dep[x]));
    }
}
inline void solve(int id){
    queue<int> Q;Q.push(id);
    int hd,tl;hd=tl=1;Queue[1]=id;father[id]=0;dep[id]=0;
    while(hd<=tl){
        int tmp=Queue[hd++];
        for(register int i=fir[tmp];i<=ls[tmp];++i) if(father[tmp]!=ed[i]){
            dep[ed[i]]=dep[tmp]+1;father[ed[i]]=tmp;
            ch[ed[i]]=C[i];Queue[++tl]=ed[i];
        }
    }
    vis[id]=0;
    for(auto k:que[id]) getans(k.first,k.second);
}
inline void work(){
    fr(i,1,n) if(!que[i].empty()) solve(i);
    fr(i,1,q) cout<<answer[i]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
    init();work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
