#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define templ template<typename T>
    typedef long long ll;
    typedef double db;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
    templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
    templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
    templ inline void read(T& t) {
        t=0;char f=0,ch=getchar();double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
        t=(f?-t:t);
    }
    template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
    void file() {
        #ifdef zqj
        freopen("a.in","r",stdin);
        #endif
    }
    inline void chktime() {
        #ifdef zqj
        cerr<<clock()/1000.0<<'\n';
        #endif
    }
    #ifdef mod
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
    ll inv(ll x){return ksm(x,mod-2);}
    #else
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
    #endif
}
using namespace my_std;

#define sz 1010

int n,m;
char s[25][25];

int id(int x,int y){return (x-1)*m+y;}
pii pos(int id){return {(id-1)/m+1,(id-1)%m+1};}

// max size, minimum weight
namespace MatroidIntersection {
    int K;
    ll W[sz];
    int in[sz]; // ans
    namespace Check { // implementation needed
        int fa[sz];
        int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}

        vector<pii>V[sz];
        int dfs(int x,int fa,int goal,vector<int>&path) {
            if (x==goal) return 1;
            for (auto [v,id]:V[x]) if (v!=fa&&dfs(v,x,goal,path)) return path.push_back(id),1;
            return 0;
        }

        // recommend implementing checker here
        void init() {
            rep(i,1,n*m) fa[i]=i,V[i].clear();
            auto link=[](int x,int y,int id) {
                assert(getfa(x)!=getfa(y));
                fa[getfa(x)]=getfa(y);
                V[x].push_back({y,id}),V[y].push_back({x,id});
                if ((pos(x).fir+pos(x).sec)%2==0) assert(V[x].size()<=2u);
                else assert(V[y].size()<=2u);
            };
            rep(i,1,K) if (in[i]) {
                int x,y;
                if (i<=n*m) tie(x,y)=pos(i),link(id(x,y),id(x,y+1),i);
                else tie(x,y)=pos(i-n*m),link(id(x,y),id(x+1,y),i);
            }
        }
        // return {-1} if no cycle; return cycle otherwise.
        vector<int> cycleA(int x) {
            int i=x,a,b;
            if (i<=n*m) {
                auto [x,y]=pos(i);
                if (y==m||s[x][y]=='X'||s[x][y+1]=='X') return {};
                a=id(x,y),b=id(x,y+1);
            }
            else {
                auto [x,y]=pos(i-n*m);
                if (x==n||s[x][y]=='X'||s[x+1][y]=='X') return {};
                a=id(x,y),b=id(x+1,y);
            }
            if (getfa(a)!=getfa(b)) return {-1};
            vector<int>path; dfs(a,0,b,path);
            return path;
        }
        vector<int> cycleB(int x) {
            int i=x,a;
            if (i<=n*m) {
                auto [x,y]=pos(i);
                if (y==m||s[x][y]=='X'||s[x][y+1]=='X') return {};
                if ((x+y)&1) a=id(x,y+1); else a=id(x,y);
            }
            else {
                auto [x,y]=pos(i-n*m);
                if (x==n||s[x][y]=='X'||s[x+1][y]=='X') return {};
                if ((x+y)&1) a=id(x+1,y); else a=id(x,y);
            }
            if (V[a].size()<2u) return {-1};
            return {V[a][0].sec,V[a][1].sec};
        }
        // not necessary
        void check() {
            init();
        }
    }
    bool work() { // try augment
        using pli=pair<ll,int>;
        static vector<int> V[sz];
        static pli dis[sz];
        static int fr[sz];
        Check::init();
        rep(i,1,K) V[i].clear();
        vector<int>A,B;
        rep(i,1,K) if (!in[i]) {
            auto cyca=Check::cycleA(i);
            if (cyca.size()==1u&&cyca[0]==-1) A.push_back(i);
            else for (auto y:cyca) V[y].push_back(i);
            auto cycb=Check::cycleB(i);
            if (cycb.size()==1u&&cycb[0]==-1) B.push_back(i);
            else for (auto y:cycb) V[i].push_back(y);
        }
        rep(i,1,K) dis[i]={ll(1e18),K+1},fr[i]=0;
        priority_queue<pair<pli,int>,vector<pair<pli,int>>,greater<pair<pli,int>>>q;
        for (auto x:A) dis[x]={W[x],0},q.push({dis[x],x});
        while (!q.empty()) {
            auto [ww,x]=q.top(); q.pop();
            if (dis[x]!=ww) continue;
            for (auto v:V[x]) 
                if (chkmin(dis[v],{dis[x].fir+W[v],dis[x].sec+1})) 
                    q.push({dis[v],v}),fr[v]=x;
        }
        pli mn={ll(1e18),K+1}; int mnp=-1;
        for (auto x:B) if (chkmin(mn,dis[x])) mnp=x;
        if (mnp==-1) return 0;
        for (int x=mnp;x;x=fr[x]) in[x]^=1;
        Check::check();
        return 1;
    }
    void clr() {
        rep(i,1,K) in[i]=0;
    }
}

int fa[sz];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void link(int x,int y){fa[getfa(x)]=getfa(y);}

int R[25][25],D[25][25];
void output() {
    cout<<"YES\n";
    rep(i,1,n) {
        rep(j,1,m) {
            cout<<s[i][j];
            if (j!=m) cout<<" O"[R[i][j]];
        }
        cout<<'\n';
        if (i!=n) {
            rep(j,1,m) {
                cout<<" O"[D[i][j]];
                if (j!=m) cout<<' ';
            }
            cout<<'\n';
        }
    }
}

void work() {
    cin>>n>>m;
    rep(i,1,n) cin>>s[i];
    rep(i,1,n) drep(j,m,1) swap(s[i][j],s[i][j-1]);
    s[1][1]='X';
    int cc=0;
    MatroidIntersection::K=2*n*m;
    while (MatroidIntersection::work()) ++cc;

    // rep(i,1,n) rep(j,1,m) R[i][j]=D[i][j]=0,fa[id(i,j)]=id(i,j);
    // rep(i,1,2*n*m) if (MatroidIntersection::in[i]) {
    //     int x,y;
    //     if (i<=n*m) tie(x,y)=pos(i),link(id(x,y),id(x,y+1)),R[x][y]=1;
    //     else tie(x,y)=pos(i-n*m),link(id(x,y),id(x+1,y)),D[x][y]=1;
    // }
    // output();
    // return;

    rep(i,1,n) rep(j,1,m) if ((i+j)%2==0&&s[i][j]!='X') cc-=2;
    if (cc) return cout<<"NO\n",MatroidIntersection::clr(),void();
    s[1][1]='O';
    rep(i,1,n) rep(j,1,m) R[i][j]=D[i][j]=0,fa[id(i,j)]=id(i,j);
    rep(i,1,2*n*m) if (MatroidIntersection::in[i]) {
        int x,y;
        if (i<=n*m) tie(x,y)=pos(i),link(id(x,y),id(x,y+1)),R[x][y]=1;
        else tie(x,y)=pos(i-n*m),link(id(x,y),id(x+1,y)),D[x][y]=1;
    }
    rep(i,1,n) rep(j,1,m-1) 
        if (getfa(id(i,j))!=getfa(id(i,j+1))&&s[i][j]!='X'&&s[i][j+1]!='X') 
            link(id(i,j),id(i,j+1)),R[i][j]=1;
    rep(i,1,n-1) rep(j,1,m) 
        if (getfa(id(i,j))!=getfa(id(i+1,j))&&s[i][j]!='X'&&s[i+1][j]!='X') 
            link(id(i,j),id(i+1,j)),D[i][j]=1;
    output();
    MatroidIntersection::clr();
}

int main() {
    file();
    int T; cin>>T;
    while (T--) work();
    return 0;
}