// LUOGU_RID: 160106285
#include<bits/stdc++.h>
#define int long long
#define said(...)
#define pb push_back
#define em emplace_back
#define F(i,x,y) for(int i=x;i<=y;++i)
#define G(i,x,y) for(int i=x;i>=y;--i)
#define W(G,i,x) for(auto&i:G[x])
#define W_(G,i,j,x) for(auto&[i,j]:G[x])
#define add(x,y) z[x].em(y)
#define add_(x,y) add(x,y),add(y,x)
#define Add(x,y,d) z[x].em(y,d)
#define Add_(x,y,z) Add(x,y,z),Add(y,x,z);
#ifdef int
#define inf (761125761137835809/2)
#else
#define inf 1011011011
#endif
using namespace std;
const int N = 200100;
const int mod = 998244353;

namespace yhb {

void flower() {
}
int a[N], s[N];
int box[111], bel[111];
void rua() {
    int n, c1 = 0, c2 = 0;
    cin >> n;
    vector<int> v1, v2;
    map<int, vector<int>> scc;
    F(i, 1, n * 2) {
        int x;
        cin >> x;
        scc[x].pb(i);
    }
    for (auto &[i, j] : scc) {
        if (j.size() == 1) {
            if (c1 < c2) {
                bel[j[0]] = 1;
                c1++;
            } else {
                bel[j[0]] = 2;
                c2++;
            }
        } else {
            c1++, c2++;
            bel[j[0]] = 1;
            bel[j[1]] = 2;
        }
    }
    cout << c1 * c2 << '\n';
    F(i, 1, n * 2) {
        if (bel[i]) {
            cout << bel[i] << ' ';
        } else {
            if (c1 < n) {
                cout << "1 ";
                c1++;
            } else {
                cout << "2 ";
            }
        }
    }
}
}
auto main() [[O3]] -> signed {
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int T;
    // cin >> T;
    T = 1;
    yhb::flower();
    while (T--) {
        yhb::rua();
    }
}