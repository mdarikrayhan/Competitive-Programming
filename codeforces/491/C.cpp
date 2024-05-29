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

#define vi vector<int> 
#define rep(i,j,k) for(int i=j;i<k;i++)
#define sz(i) (int)i.size()
pair<int, vi> hungarian(const vector<vi> &a) {
	if (a.empty()) return {0, {}};
	int n = sz(a) + 1, m = sz(a[0]) + 1;
	vi u(n), v(m), p(m), ans(n - 1);
	rep(i,1,n) {
		p[0] = i;
		int j0 = 0; // add "dummy" worker 0
		vi dist(m, INT_MAX), pre(m, -1);
		vector<bool> done(m + 1);
		do { // dijkstra
			done[j0] = true;
			int i0 = p[j0], j1, delta = INT_MAX;
			rep(j,1,m) if (!done[j]) {
				auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			rep(j,0,m) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) { // update alternating path
			int j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans}; // min cost
}

int char_to_num(char ch){
	if(ch>='a'&&ch<='z') return ch-'a';
	return ch-'A'+26;
}

int num_to_char(int a) {
	if(a<26) return a+'a';
	return a-26+'A';
}

void solve(){
	int n, m; cin >> n >> m ;
	vector<vi> g(m,vi(m,0));
	string s; cin >> s;
	string t; cin >> t;
	for(int i=0;i<n;i++) {
		int a = char_to_num(s[i]);
		int b = char_to_num(t[i]);

		g[a][b]--;
	}

	pair<int,vi> ret = hungarian(g);
	cout << -ret.F << endl;
	for(int a : ret.S) cout << (char)(num_to_char(a)); cout << endl;
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