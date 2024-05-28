#include <bits/stdc++.h>
using namespace std;

using ll = int;

void solve () {
    ll n;
    cin >> n;

    vector <ll> a (n);

    ll S = 0;

    for (ll i = 0; i < n; i += 1) {
        cin >> a[i];
        S += a[i];
    }

    auto parition = [&] () -> vector <ll> {
        vector <vector <ll>> dp (n, vector <ll> (S + 1, 0));
        dp[0][0] = 1;
        dp[0][a[0]] = 1;
        for (ll i = 1; i < n; i += 1) {
            for (ll j = 0; j <= S; j += 1) {
                if (dp[i - 1][j]) {
                    dp[i][j] = 1;
                }
                if (j - a[i] >= 0 && dp[i - 1][j - a[i]]) {
                    dp[i][j] = 1;
                }
            }
        }

        vector <ll> res;

        if (dp[n - 1][S / 2] == 0) return res;

        array <ll, 2> st = {n - 1, S / 2};

        while (1) {
            auto &[till, mk] = st;
            if (mk == 0) break;
            if (till) {
                if (dp[till - 1][mk]) {
                    till--;
                }
                else {
                    res.push_back (till);
                    mk -= a[till--];
                }
            }
            else {
                res.push_back (till);
                mk -= a[till--];
            }
        }
        return res;
    };

    auto play_as_first = [&] () {
        cout << "First" << endl;
        for (ll i = 0; i < n; i += 1) {
            ll j = 0;
            while (a[j] == 0) j++;
            cout << j + 1 << endl;
            ll j1;
            cin >> j1;
            if (j1 == 0 || j1 == -1) return;
            ll x = min (a[j], a[j1 - 1]);
            a[j] -= x;
            a[j1 - 1] -= x;
        }
        return;
    };

    auto play_as_second = [&] (vector <ll> grp) {
        cout << "Second" << endl;
        for (ll i = 0; i < n; i += 1) {
            ll j1;
            cin >> j1;
            if (j1 == 0 || j1 == -1) return;
            ll _ = grp[j1 - 1];
            for (ll j = 0; j < n; j += 1) if (grp[j] != _ && a[j] != 0) {
                ll x = min (a[j], a[j1 - 1]);
                a[j] -= x;
                a[j1 - 1] -= x;
                cout << j + 1 << endl;
                break;
            }
        }
    };

    if (S % 2 != 0) {
        play_as_first ();
        return;
    }

    vector <ll> part = parition ();
    if (part.empty()) {
        play_as_first ();
        return;
    }

    vector <ll> grp (n);

    for (ll i = 0; i < part.size(); i += 1) {
        grp[part[i]] = 1;
    }

    play_as_second (grp);
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int no_of_tests = 1;
    // cin >> no_of_tests;

    for (int test_no = 0; test_no < no_of_tests; test_no += 1) {
        solve ();
    }
}