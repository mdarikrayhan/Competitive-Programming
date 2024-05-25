// LUOGU_RID: 160263122
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
#define lch(x) (z[x][0])
#define rch(x) (z[x][1])
using namespace std;
const int N = 1000100;
const int mod = 998244353;

namespace yhb {

void rua() {
    int s, n;
    cin >> s >> n;
    while (n--) {
        if (n == 0) {
            cout << s << '\n';
        } else {
            int t = pow(10, (int)log10(s - n));
            s -= t;
            cout << t << ' ';
        }
    }
}
void flower() {
}
}
auto main() [[O3]] -> signed {
    int T;
    cin >> T;
    // T = 1;
    yhb::flower();
    while (T--) {
        yhb::rua();
    }
}