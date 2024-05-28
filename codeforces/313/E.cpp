#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int M = 5e5+5, MOD = 1e9+7;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m), fr(m);
    for (int &i:a) {
        cin >> i;
        fr[m-i-1]++;
    }

    for (int i:a) {
        int x;
        cin >> x;

        b[x]++;
    }

    vector<int> v;
    multiset<int> Q;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = m-1; i >= 0; i--) {
        while (fr[i]--) q.push(i);
        if (!b[i]) continue;
        while (!q.empty() && b[i]--) v.push_back(((i-q.top()-1)%m+m)%m), q.pop();
    }

    for (int i = m-1; i >= 0; i--) {
        while (q.size() && b[i]-- > 0) v.push_back(((i-q.top()-1)%m+m)%m), q.pop();
    }

    sort(v.rbegin(), v.rend());
    for (int i:v) cout << i << ' '; cout << endl;

    return 0;
}
/*
*/
