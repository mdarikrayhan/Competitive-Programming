#include <bits/stdc++.h> 

using namespace std;

#define int long long
#define deb(x) cout << #x << " = " << x << endl;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define fo(i, j) for(i=0;i<j;i++)
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i++:i--)

#define imax INT_MAX
#define imin INT_MIN
#define PI 3.1415926535897932384626433832795
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
#define sortall(x) sort(all(x))

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

void WVI(VI ar){
    int i;
    fo(i, ar.size()){
        cout << ar[i] << " ";
    }cout << endl;
}

void setIO(string name){
    ios_base::sync_with_stdio(0);cin.tie(0);
    if(!name.empty()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
#define here cout << "-----PASS-----" << endl;
const int mxN = 1e5+5;
const int MOD = 998244353;
const int INF = 4e18+50;

//*********************************************************************************

// max flow
// find shortest augmented paths
// while reachable :
//      1. create level graph (BFS)
//      2. only care about shortest path
//      3. find its block flow by dfs
//          keep track every node adjacent mana aja yang udah di visit.
//      4. repeat

struct edge{
    int from, to, cap;
};
vector<edge> edges;
vector<vector<int>> adj(10005);
int level[10005];
int cur[10005];
int n;
int s,t;

int sendFlow(int u=s, int minFlow=INF){
    if(u==t) return minFlow;
    int totalFlow = 0;
    //cout << u << " " << minFlow << endl;
    for(;cur[u]<adj[u].size();cur[u]++){
        edge &ff = edges[adj[u][cur[u]]];
        edge &bf = edges[adj[u][cur[u]] ^ 1ll];

        if(ff.cap <= 0) continue;
        if(level[u]+1 != level[ff.to]) continue;

        int currentFlow = sendFlow(ff.to, min(minFlow, ff.cap));

        minFlow -= currentFlow;
        ff.cap -= currentFlow;
        bf.cap += currentFlow;
        totalFlow += currentFlow;

        if(minFlow <= 0 ) break;
    }
    return totalFlow;
}

bool reachable(){
    memset(level,-1,sizeof level);
    queue<int> q;
    q.push(s);
    int cnt = 0;
    bool found =0;
    while(!q.empty()){
        int sz = q.size();
        //cout << q.front() << endl;
        while(sz--){
            int u = q.front(); q.pop();
            
            if(level[u]>=0) continue;
            if(u == t) found = 1;
            
            level[u] = cnt;
            
            for(int p : adj[u]) {
                edge &e = edges[p];
                if(level[e.to]>=0) continue;
                if(e.cap <= 0) continue;
                q.push(e.to); 
            }
        }
        cnt++;
        if(found) break;
    }
    return found;
}

int maxFlow(){
    int mf = 0;
    while(reachable()){
        memset(cur,0,sizeof cur);
        mf += sendFlow();
    }
    return mf;
}

void addEdge(int a, int b, int cap){
    //cout << a << " " << b << endl;
    edge tmp;
    tmp.from = a, tmp.to = b, tmp.cap = cap;
    adj[a].pb(edges.size());
    edges.pb(tmp);
    
    tmp.from = b, tmp.to = a, tmp.cap = 0;
    adj[b].pb(edges.size());
    edges.pb(tmp);
}

void reset() {
    edges.clear();
    adj = VVI(10005, VI{});
}


void solve(){
    int m; cin >>  n>> m ;
    VII tmpedge;
    for(int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        tmpedge.pb({a,b});
    }
    //cout << "YAY" << endl;

    int l=0, r= m;
    int pos=m;
    s=10001, t=10002;
    while(l<=r){
        int mid = (l+r)/2;
        reset();
        //cout << mid << endl;
        
        for(int i=0;i<m;i++) {
            addEdge(i,t,1);
            addEdge(tmpedge[i].F+5000, i, 1);
            addEdge(tmpedge[i].S+5000, i, 1);
        }
        for(int i=1;i<=n;i++) {
            addEdge(s,i+5000,mid);
        }
        if(maxFlow() >= m){
            r=mid-1;pos=mid;
        }else l=mid+1;
        
    }
    reset();
    cout << pos << endl;
    for(int i=0;i<m;i++) {
        addEdge(i,t,1);
        addEdge(tmpedge[i].F+5000, i, 1);
        addEdge(tmpedge[i].S+5000, i, 1);
    }
    for(int i=1;i<=n;i++) {
        addEdge(s,i+5000,pos);
    }
    maxFlow();
    set<PII> ans;

    for(auto a : edges) {
        if(a.from <= 10000 && a.to <= 10000) {
            if(a.from >= a.to) {
                if(!a.cap) {
                    int fi = a.from-5000;
                    int se = tmpedge[a.to].F==fi?tmpedge[a.to].S:tmpedge[a.to].F;
                    ans.insert(mp(fi,se));
                }
            }
        }
    }
    for(PII a : ans) cout << a.F << " " << a.S << endl;

}

int32_t main(){
    string name = "";
    setIO(name);
    int test_cases = 1;
    //cin >> test_cases;
    while(test_cases--) {
        solve(); //cout << endl;
    }

    return 0; 
}