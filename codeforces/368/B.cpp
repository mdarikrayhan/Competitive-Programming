#include <bits/stdc++.h>

typedef long long ll;
#define F first
#define S second
using namespace std;

void IO() {
#ifndef ONLINE_JUDGE
    freopen("inp74.txt", "r", stdin);
    freopen("out74.txt", "w", stdout);
#endif
}

void solve() {
    int n;
    int q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> pref(n + 2);
    set<int> st;
    int j = 1;
    for (int i = n - 1; i >= 0; --i) {
        st.insert(a[i]);
        pref[j] = st.size();
        j++;
    }
    while (q--) {
        int k;
        cin >> k;
        cout << pref[n + 1 - k] << endl;
    }
}

int main() {
    IO();

    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
