#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b))

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
const char nl = '\n';
void solve() {
    long long f;
    string s;
    cin >> f >> s;
    if (s[0]!='9') {
        for (int i=0; i<f; i++) {
            cout << (char)('0'+'9'-s[i]);
        }
        cout << "\n";
    } else {
        vector<int> ans(f, 0);
        bool spec=0, kov=0;
        for (int i=f-1; i>=0; i--) {
            int g=s[i]-'0';
            if (g+spec>1) {
                kov=1;
                ans[i]=11-g-spec;
            } else {
                ans[i]=1-g-spec;
            }
            spec=kov;
            kov=0;
        }
        for (auto x:ans) {
            cout << x;
        }
        cout << "\n";
    }
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T = 1;
cin >> T;
while(T--) {
solve();
}
return 0;
}