#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

int N, ans[100001];

void solve1() { // i&j == 0
    if (N&1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int n = 262143;
    int N1 = N;
    while (n) {
        int lo = n-N1;
        if (lo >= 1 && lo <= N1) {
            FOR(i,lo,N1+1) ans[i] = N1+lo-i;
            N1 = lo-1;
        }
        n /= 2;
    }
    FOR(i,1,N+1) cout << ans[i] << " ";
    cout << "\n";
}

void solve2() { // i&j != 0
    int n = 1; while (2*n <= N) n *= 2;
    if (N <= 5 || n == N) {
        cout << "NO\n";
        return;
    }
    if (N == 6) {
        ans[1] = 3, ans[3] = 1;
        ans[2] = 6, ans[6] = 2;
        ans[4] = 5, ans[5] = 4;
    } else {
        if (n != 7) {
            vi t; FOR(i,n,N+1) t.pb(i);
            F0R(i,sz(t)) ans[t[i]] = t[(i+1)%sz(t)];
        }
        while (n >= 16) {
            vi t; FOR(i,n/2,n) t.pb(i);
            F0R(i,sz(t)) ans[t[i]] = t[(i+1)%sz(t)];
            n /= 2;
        }
        ans[1] = 3, ans[3] = 7, ans[7] = 1, ans[4] = 5, ans[5] = 4;
        ans[2] = 6, ans[6] = 2;
    }
    cout << "YES\n";
    FOR(i,1,N+1) cout << ans[i] << " ";
    cout << "\n";
    // is 6 possible
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	solve1();
	solve2();
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!