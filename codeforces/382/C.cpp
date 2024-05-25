#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// const ll mod = 1000000007;
// const ll mod = 998244353;
int n, m, k, q, l, r, x, y, z;
const int template_array_size = 1e5 + 101;
int a[template_array_size];
string s, t;
ll ans = 0;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    vector<int> ans;
    if (n == 1) {
        cout << "-1\n";
        return;
    } else if (n == 2) {
        k = a[1] - a[0];
        ans.push_back(a[0] - k);
        if (k == 0) {
            cout << 1 << '\n';
            cout << ans[0] << '\n';
            return;
        }
        ans.push_back(a[1] + k);
        q = a[1] - a[0];
        if (q % 2 == 0) {
            ans.push_back(a[0] + q / 2);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
        return;
    }

    multiset<int> ms;
    for (int i = 1; i < n; i++) {
        ms.insert(a[i] - a[i-1]);
    }
    bool is_ap = (*ms.begin() == *ms.rbegin());
    // cout << is_ap << '\n';

    if (is_ap) {
        k = a[1] - a[0];
        ans.push_back(a[0] - k);
        if (k > 0) {
            ans.push_back(a[n-1] + k);
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
        return;
    }

    // search if you can make an AP inserting an element
    for (int i = 1; i < n; i++) {
        q = a[i] - a[i-1];
        if (q & 1) {
            continue;
        }
        auto diff = ms.find(q);
        ms.erase(diff);

        if ((*ms.begin() == q / 2) && (*ms.rbegin() == q / 2)) {
            ans.push_back(a[i-1] + q / 2);
            break;
        }

        ms.insert(q);
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size()-1];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
