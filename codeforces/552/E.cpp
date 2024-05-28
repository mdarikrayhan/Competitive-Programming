#include <bits/stdc++.h>
using namespace std;
#define Go  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define ll long long
// =========================================================================================

void Burn_The_Problem_Alive() {
    string s; cin >> s; 
    s = "1*" + s + "*1";
    int n = s.size(); 
    s = '#' + s; 

    vector<vector<ll>> val(n + 1, vector<ll>(n + 1));
    for (int i = 3; i <= n; i += 2) {
        int l = i;
        ll mul = 0, cur = 1, ys = 0;
        for (int r = i; r <= n - 2; r ++) {
            if (s[r] == '+') {
                mul += cur;
                cur = 1;
                ys = 0;
            }
            else if (s[r] != '*') cur *= s[r] - '0', ys = 1;
            val[l][r] = mul;
            if (ys) val[l][r] += cur;    
        }
    }

    vector<int> pre(n + 1); 
    for (int i = 1; i <= n; i++) {
        if (s[i] == '+') pre[i] = 1;  
        pre[i] += pre[i - 1];
    }

    ll ans = 0;
    for (int l = 3; l <= n; l += 2) {
        for (int r = l; r <= n; r += 2) {
            int L = 3, R = l, id1 = 0, id2 = n - 2;
            while (L <= R) {
                int mid = L + R >> 1; 
                (pre[l] - pre[mid - 1] == 0) ? id1 = mid, R = mid - 1 : L = mid + 1;
            }

            L = r, R = n - 2;
            while (L <= R) {
                int mid = L + R >> 1; 
                (pre[mid] - pre[r] == 0) ? id2 = mid, L = mid + 1 : R = mid - 1;
            }

            ll curans = val[l][r];
            if (id1 < l - 1) curans *= val[id1][l - 2]; 
            if (id2 > r + 1) curans *= val[r + 2][id2];

            curans += val[3][id1 - 2];
            curans += val[id2 + 2][n - 2];

            ans = max(ans, curans);
        }
    }

    cout << ans << endl;
}

// =========================================================================================

int32_t main() {
    Go;

    int TES = 1;            //  cin >> TES;
    while (TES--)Burn_The_Problem_Alive();

    return 0;
}