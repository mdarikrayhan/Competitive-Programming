#include <bits/stdc++.h>
 
#pragma GCC optimize("O3,unroll-loops")
#define pb push_back
#define F first
#define S second 
#define all(a) a.begin(),a.end()
#define pii pair <int,int>
#define PII pair<pii , pii>
#define ld long double
#define sz(v) (int)v.size()
#define ll long long
#define rep(i , a , b) for(int i=a;i <= b;i++)
#define per(i , a , b) for(int i=a;i >= b;i--)
using namespace std ;
const int maxn =2e6 + 10  ,  N = 1e5 +1 , lg = 20 , maxq = 202   , inf = 1e9  , maxk = 2022  , mod =1e9+7;
int dis[maxn] , mark[maxn] , ans[maxn]  , c= 1  , mn[maxn] ; 
vector <pii> G[maxn] ;

void add(int v, int u ,int i){
    string f ;
    int x= i ;
    while(x){
        f += (char)('0'+(x%10));
        x/=10;
    }
    vector <int> vec ;
    reverse(all(f));
    if(sz(f)==1){
        G[v].pb({u,f[0]-'0'});
        return ;
    }
    G[v].pb({c,f[0]-'0'});
    rep(i , 1 ,sz(f)-1){
        if(i == sz(f)-1){
            G[c].pb({u , f[i]-'0'});
        }else{
            G[c].pb({c+1, f[i]-'0'});
        }
        c++;
    }
}

void sl(vector <int> vec , ll f){
    f%=mod ;
    vector <int> x[11];
    for(int v : vec){
        ans[v] = f ;
        for(auto [u,w] : G[v]){
            if(mark[u] == 1 || dis[u] != dis[v]+1)continue ;
            if(mn[u] <= w)continue ;
            x[w].pb(u);mn[u]=min(mn[u] , w); 
        }
    }
    rep(i , 0 ,9)for(int a : x[i])mark[a] =1 ;
    rep(i , 0 ,9){
        vector <int>a ;
        for(int v : x[i]){
            if(mn[v]!=i)continue ;
            a.pb(v);
        }
        if(sz(a))
        sl(a , f*10 + i);
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n , m ;
    cin >> n  >> m;
    c = n+1 ;
    rep(i , 1, m){
        int v, u;
        cin >> v >> u ;
        add(v,u,i);
        add(u,v,i);
    }
    rep(i , 1,c)mn[i] = 10 ;
    queue <int> q ;
    q.push(1);
    rep(i , 1, c)dis[i] = inf ;
    dis[1] = 0 ;
    while(sz(q)){
        int v =q.front() ;
        q.pop() ;
        for(auto [u,w] : G[v]){
            if(dis[u] > dis[v]+1){
                dis[u] = dis[v]+1;
                q.push(u) ;
            }
        }
    }
    vector<int> vec;
    vec.pb(1); 
    sl(vec , 0);
    rep(i ,2 ,n){
        cout << ans[i] << "\n"; 
    }
}
/*

*/