#include <bits/stdc++.h>

using namespace std;

#define int long long
//#define endl "\n"
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itn int
#define inf 2000000000000000000LL
#define ll long long
//#define gcdi gcd

typedef string str;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pii;
typedef tuple<int,int,int> t3i;
typedef tuple<int,int,int,int> t4i;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef set<pii> sii;
typedef vector<str> vs;
const int mod1 = 1000000007;
const int mod2 = 998244353;

// fft settings
const int mod = mod1;
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;
const int half = (mod + 1) / 2;

using u64 = uint64_t;
mt19937 rng((uint64_t) new char);

void out(const vi& v, string bkr = " ") {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << bkr;
	}
}
void out(int* v, int n, string bkr = " ") {
	for (int i = 0; i < n; ++i) {
		cout << *(v + i) << bkr;
	}
}

void out(vector<pii> t) {
    for (auto e:t) {
        cout<<"("<<get<0>(e)<<","<<get<1>(e)<<")"<<" ";
    }
}



void solve() {
    int n,m;cin>>n>>m;
    vvi adj(n);
    sii edges;
    for (int i=0;i<m;i++) {
        int x,y;cin>>x>>y;x--;y--;
        adj[x].pb(y);adj[y].pb(x);
        if (x>y) swap(x,y);
        edges.insert({x,y});
    }
    //cout<<"OK"<<endl;
    // run bfs
    queue<int> q;
    vi dist(n,inf),vis(n,0),con1(n,0);
    for (auto i:adj[0]) con1[i]=1;
    vis[0]=1;q.push(0);dist[0]=0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto i:adj[cur]) {
            if (!vis[i]) {
                vis[i]=1;
                q.push(i);
                dist[i]=dist[cur]+1;
            }
        }
    }
    vi alt_output;
    int altlen = inf;
    for (auto i:edges) {
        int x = i.first, y = i.second;
        if (x!=0) {
            if (con1[x]&&(!con1[y])) {
                alt_output = {0,x,y,0};altlen = 4;break;
            }
            if (con1[y]&&(!con1[x])) {
                alt_output = {0,y,x,0};altlen = 4;break;
            }
        }
    }
    // search for 1-->x-->y-->z-->x-->n
    // requires y-->z to be null
    if (altlen != 4) {
        sii ned;
        vvi nadj(n);
        vi nvis(n);
        for (auto i:edges) {
            int x = i.first, y = i.second;
            if ((x!=0) && (con1[x])) {
                ned.insert({x,y});
                nadj[x].pb(y);nadj[y].pb(x);
            }
        }
        for (int p=0;p<n;p++) {
            if (!nvis[p]) {
                queue<int> nq;
                // bfs on p
                vi verts;
                verts.pb(p);nvis[p]=1;nq.push(p);
                while (!nq.empty()) {
                    int cur = nq.front();
                    nq.pop();
                    for (auto z:nadj[cur]) {
                        if (!nvis[z]) {
                            nvis[z]=1;verts.pb(z);
                            nq.push(z);
                        }
                    }
                }
                //out(verts);cout<<endl;
                for (auto i:verts) {
                    if (altlen != inf) break;
                    for (auto j:verts) {
                        if (altlen != inf) break;
                        if ((i<j)&&(ned.find({i,j})==ned.end())) {
                            //cout<<"found!! "<<i<<" "<<j<<endl;
                            vi cwi(n,0);
                            for (auto vk:nadj[i]) cwi[vk]=1; 
                            //out(cwi);cout<<endl;
                            // pathfind i-->j
                            for (auto ted:ned) {
                                int tx = ted.first, ty = ted.second;
                                if (tx==i) continue;
                                if (ty==i) continue;
                                //cout<<tx<<" "<<ty<<"e"<<endl;
                                int k = cwi[tx]+cwi[ty]*2;
                                if (k==1) {
                                    altlen = 5;
                                    alt_output = {0,i,tx,ty,i};
                                    break;
                                }
                                if (k==2) {
                                    altlen = 5;
                                    alt_output = {0,i,ty,tx,i};
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (min(altlen,dist[n-1])==inf) {
        cout<<-1;
    }
    else if (altlen<dist[n-1]) {
        cout<<altlen<<endl;
        for (auto i:alt_output) cout<<i+1<<" ";
        cout<<n;
    }
    else {
        cout<<dist[n-1]<<endl;
        stack<int> stk;
        int cdist = dist[n-1], vert = n-1;
        stk.push(n-1);
        while (cdist) {
            cdist--;
            for (auto i:adj[vert]) {
                if (dist[i]==cdist) {
                    stk.push(i);
                    vert = i;
                    break;
                }
            }
        }
        while (!stk.empty()) {
            int x = stk.top();
            cout<<x+1<<" ";
            stk.pop();
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
	//cout << fixed << setprecision(6);
    //int t;cin >> t;while (t--)
    {
        solve();
    }
    return 0;
}