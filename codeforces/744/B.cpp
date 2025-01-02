#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x),end(x)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define forn(i,n) for(int i=0;i<int(n);i++)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dbg(x) cerr<<#x<<": "<<x<<endl

#define fst first
#define snd second
#define pb push_back
#define eb emplace_back

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

//const int MAXN = 2e5+5;
//const ll INF = 1e18;
const int MOD = 1e9+7;

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"[ ";
    for(auto y : v) out<<y<<" ";
    out<<"]";
    return out;
}

template<class a, class b> ostream & operator<<(ostream & out, pair<a, b> p){
    return out<<"("<<p.fst<<", "<<p.snd<<")";
}

const int INF=1e9+7;

int n;
//vector<vi> mat;

vi query(vi &v){
    if(sz(v)==0) return vi(n,INF);
    if(sz(v)==n) return vi(n,0);
    cout<<sz(v)<<endl;
    forn(i,sz(v)) cout<<v[i]<<' ';
    cout<<endl;
    vi r(n,INF);
    //forn(i,n) for(int j:v) r[i]=min(r[i],mat[i][j-1]);
    forn(i,n) cin>>r[i];
    return r;
}

int main(){
    //freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    
    cin>>n;
    //mat.assign(n,vi(n));
    //forn(i,n) forn(j,n) cin>>mat[i][j];
    vi res(n,INF);
    forn(i,10){
        vi v[2];
        forsn(j,1,n+1) v[j>>i&1].pb(j);
        vi ans[2];
        forn(j,2) ans[j]=query(v[j]);
        forsn(j,1,n+1) res[j-1]=min(res[j-1],ans[j>>i&1^1][j-1]);
    }
    cout<<"-1"<<endl;
    forn(i,n) cout<<res[i]<<' ';
    cout<<endl;
    
    return 0;
}
