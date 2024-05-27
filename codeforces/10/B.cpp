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
    int q; cin >> q;
    int n; cin >> n;
    int mid = n/2;
    vvi grid(n, vi(n));
    rep(_, 0, q){
        int m; cin >> m;
        map<int, pii> poss;
        rep(i, 0, n){
            rep(j, 0, n){
                if(j + m > n) break;
                int cent = 0;
                bool bad = false;
                rep(l, 0, m){
                    if(grid[i][j+l]) {
                        bad = true;
                        break;
                    }
                    cent += abs(i - mid) + abs(j+l - mid);
                }
                if(!bad){
                    if(!poss.count(cent) || poss[cent] > pii{i, j}){
                        poss[cent] = {i, j};
                    }
                }
            }
        }
        if(sz(poss) == 0){
            cout << -1 << "\n";
            continue;
        }
        int r = poss.begin()->s.f, c = poss.begin()->s.s;
        cout << poss.begin()->s.f+1 << " " << poss.begin()->s.s+1 << " " << poss.begin()->s.s+m << "\n";
        rep(i, 0, m){
            grid[r][c + i] = 1;
        }
    }
    
    return 0;
}
