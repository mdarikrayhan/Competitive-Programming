#include <bits/stdc++.h>
using namespace std;
#define Go  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define ll long long
#define int long long
// =========================================================================================

vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

void Burn_The_Problem_Alive() {
    int n; cin >> n;
    int l, r; cin >> l >> r;
    int k;

    string s; cin >> s;
    vector<int> p = z_function(s);
    int best = 0;
    function<int(int)> ch = [&](int x) {
            int cur = x;
            int num = 1, ys = 0;
            while (cur + x - 1 < n) {
                ys = 0;
                if (p[cur] >= x) {
                    num++;
                    cur += x;
                    ys = 1;
                }

                if (!ys)cur++;
            }
            if (num >= k) {
                best = num;
                return 1;
            }
            return 0;
        };

    int i = 1;
    vector<int>Ans(n + 1, -1);
    while (i <= n) {
        best = 0;
        int L = 1, R = n, ans = 0;
        k = i;
        while (L <= R) {
            int mid = L + R >> 1;
            ch(mid) ? ans = mid, L = mid + 1 : R = mid - 1;
        }
        Ans[i] = ans;
        if (!ans)break;
        i = max(best + 1, i + 1);
    }

    for (int i = 1; i <= n; i++) {
        if (Ans[i] == -1)Ans[i] = Ans[i - 1];
    }
    for (int i = l; i <= r; i++)
        cout << Ans[i] << ' ';
    cout << endl;
}

// =========================================================================================

int32_t main() {
    Go;
    int TES = 1;             cin >> TES;
    while (TES--)Burn_The_Problem_Alive();

    return 0;
}