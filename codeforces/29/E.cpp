//1L1YA
//Brightest lights rises from the darkest nights

#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize ("O3,unrool-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long       ll;
typedef pair<ll,ll>     pll;
typedef pair<int,int>   pii;

#define Pb              push_back
#define dokme(x)        cout << x << endl, exit(0)
#define F               first
#define S               second
#define endl            '\n'
#define sep             ' '
#define all(x)          x.begin(),x.end()
#define lc              (id<<1)
#define rc              (lc|1)
#define mid             (l+r>>1)
#define FastIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FileIO          freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll oo=1e18;
const int mod=1e9+7;
const int inf=1e9+111;
const int N=505;
const int lg=23;

int n,m,d[N][N][2];
vector<int> adj[N];
pair<pii,int> par[N][N][2];

void bfs(){
    queue<pair<pii,int>> Q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<2;k++)
                d[i][j][k]=inf;
    d[1][n][0]=0;
    Q.push({{1,n},0});
    while(!Q.empty()){
        int u=Q.front().F.F,v=Q.front().F.S,t=Q.front().S;Q.pop();
        if(!t){
            for(int w: adj[u])
                if(d[u][v][0]+1<d[w][v][1]){
                    d[w][v][1]=d[u][v][0]+1;
                    Q.push({{w,v},1});
                    par[w][v][1]={{u,v},0};
                }
        }
        else{
            for(int w: adj[v])
                if(w!=u && d[u][v][1]<d[u][w][0]){
                    d[u][w][0]=d[u][v][1];
                    Q.push({{u,w},0});
                    par[u][w][0]={{u,v},1};
                }
        }
    }
}

int main(){
    FastIO

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].Pb(v);
        adj[v].Pb(u);
    }
    bfs();
    if(d[n][1][0]==inf)    dokme(-1);
    cout << d[n][1][0] << endl;
    int u=n,v=1,t=0;
    vector<int> p1,p2;
    while(u!=1 || v!=n || t){
        if(t)    p1.Pb(u);
        else    p2.Pb(v);
        auto p=par[u][v][t];
        u=p.F.F;v=p.F.S;t=p.S;
    }
    p1.Pb(1);p2.Pb(n);
    reverse(all(p1));
    reverse(all(p2));
    for(auto v: p1)    cout << v << sep;cout << endl;
    for(auto v: p2)    cout << v << sep;cout << endl;

    return 0;
}