#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define PB push_back
#define FS first
#define SD second
#define ary(k) array<int,k>
template<class A,class B> void cmx(A& x, B y) {x=max<A>(x,y);}
template<class A,class B> void cmn(A& x, B y) {x=min<A>(x,y);}
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    int t; cin >> t; while(t--){
        int n; cin >> n;
        set<int> s;
        rep(i,0,n){
            int x; cin >> x;
            s.insert(x);
        }
        if(sz(s) > 2){
            cout << n << "\n";
            continue;
        }
        if(n == 1) cout << "1\n";
        else{
            int ans = 2+(n-2)/2;
            cout << ans << "\n";
        }
    }
}
