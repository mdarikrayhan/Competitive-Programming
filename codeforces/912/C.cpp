#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;

struct Re {
    int t, hp;
    bool operator < (const Re &a) const {
        return t == a.t ? hp > a.hp : t < a.t;
    }
};
struct Enemy {
    int m, s, r;
    vector<Re> re;
} e[N];
vector<Re> cng;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, bty, inc, dmg;
    cin >> n >> m >> bty >> inc >> dmg;
    for (int i = 1; i <= n; i++) {
        cin >> e[i].m >> e[i].s >> e[i].r;
        e[i].re.push_back({0, e[i].s});
        if (inc && e[i].m <= dmg) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        int t, enm, hp;
        cin >> t >> enm >> hp;
        e[enm].re.push_back({t, hp});
    }
    for (int i = 1; i <= n; i++) {
        sort(e[i].re.begin(), e[i].re.end());
        bool flag = true;
        for (int j = 0; j < e[i].re.size(); j++) {
            if (flag && e[i].re[j].hp > dmg) cng.push_back({e[i].re[j].t - 1, -1}), flag = false;
            else if (!flag && e[i].re[j].hp <= dmg) cng.push_back({e[i].re[j].t, 1}), flag = true;
            if (flag && e[i].r) {
                int lev = (dmg - e[i].re[j].hp) / e[i].r;
                if (j == e[i].re.size() - 1 || e[i].re[j].t + lev < e[i].re[j+1].t)
                    cng.push_back({e[i].re[j].t + lev, -1}), flag = false;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if ((*e[i].re.rbegin()).hp <= dmg && e[i].r == 0 && inc) {
            cout << -1;
            return 0;
        }
    sort(cng.begin(), cng.end());
    cng.push_back({0, 0});
    ll ans = 0;
    int cur = n;
    for (auto re : cng)
        if (re.t == -1) cur--;
        else if (re.hp == 1) cur++;
        else ans = max(ans, cur * (bty + (ll)re.t * inc)), cur--;
    cout << ans;
    return 0;
}