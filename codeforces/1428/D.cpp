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


void solve(){
	int n; cin >> n ;
	int currow = n ;
	int ar[n+5];
	set<PII> ans;
	int freq2=0;
	int vis[n+5];
	memset(vis,0,sizeof vis);
	queue<int> q[4];
	VI p[4];
	for(int i=1;i<=n;i++) {
		cin >> ar[i];
	}

	for(int i=n;i>=1;i--) {
		if(ar[i]==1) {
			q[1].push(i);
			
		}else if(ar[i]==2){
			if(q[1].empty()) {
				cout << -1 << endl;
				return;
			}

			ans.insert({i,currow});
			ans.insert({q[1].front(), currow--});
			q[1].pop();
			q[2].push(i);
		}else if(ar[i]==3) {
			if(!q[3].empty()) {
				ans.insert({i, currow});
				ans.insert({q[3].front(), currow--});
				q[3].pop();
				q[3].push(i);
				continue;
			}
			if(!q[2].empty()) {
				ans.insert({i,currow});
				ans.insert({q[2].front(), currow--});
				q[2].pop();
				q[3].push(i);
				continue;
			}
			if(q[1].empty()) {
				cout << -1 << endl;
				return;
			}

			ans.insert({i,--currow});
			ans.insert({q[1].front(), currow});
			ans.insert({q[1].front(),currow+1});
			q[1].pop();
			q[3].push(i);
			currow--;
		}
	}
	while(!q[1].empty()) {
		ans.insert({q[1].front(), currow--});
		q[1].pop();
	}
	if(currow<0) {
		cout << -1 << endl;
		return;
	}

	
	

	cout << ans.size() << endl;
	for(PII a : ans) cout << a.S << " " << a.F << endl;

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