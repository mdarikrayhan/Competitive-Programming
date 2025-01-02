#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll = long long;

const int N = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 1e18;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 10);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
        // cout << b[i] << " ";
    }
    // cout << endl;

    int q;
    cin >> q;
    while(q--) {
        int l, u;
        cin >> l >> u;

        int left = l, right = n;
        int g = u + b[left - 1];
        while(left + 1 < right) {
            int mid = (left + right) >> 1;
            if (b[mid] <= g) {
                left = mid;
            } else {
                right = mid;
            }
        }

        int r;
        if (b[right] <= g) {
            r = right;
        } else {
            r = left;
        }

        if (r == n || u - (b[r] - b[l - 1]) < (b[r + 1] - b[l - 1]) - u) {
            cout << r << " ";
        } else {
            cout << r + 1 << " ";
        }
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}