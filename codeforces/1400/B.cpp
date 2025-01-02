#include <bits/stdc++.h>

using namespace std;
//#define dbl double
#define int long long

int tryCarry(int cap, int cs, int s, int cw, int w) {
    if (s * cs >= cap)
        return cap / s;
    else
        return cs + min((cap - cs * s) / w, cw);
}

void func() {
    int p, f, cs, cw, s, w, ans(0);
    cin >> p >> f >> cs >> cw >> s >> w;
    if (s > w) swap(s, w), swap(cs, cw); // making sure I always start with the lighter weight
    for (int items = 0; items <= cs; items++) {
        if (items * s <= p) {
            int cntOther = min((p - items * s) / w, cw);
            ans = max(ans, items + cntOther + tryCarry(f, cs - items, s, cw - cntOther, w));
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifdef Clion
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int tc;
    cin >> tc;
    while (tc--)
        func();
    return 0;
}