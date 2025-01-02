#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vii = vector<pii>;
using vll = vector<pll>;;
using vvi = vector<vi>;

#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    string str; int k; cin >> str >> k;
    int n = sz(str);
    rep(p, 0, n){
        pii best = {str[p], -p};
        rep(p1, p+1, n){
            if(p1 - p > k) break;
            best = max(best, {str[p1], -p1});
        }
        if(best.f != str[p]){
            int p1 = -best.s;
            str.erase(str.begin() + p1);
            str.insert(str.begin() + p, best.f);
            k -= p1 - p;
        }
    }
    cout << str << "\n";
    
    return 0;
}
