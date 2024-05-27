#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define ll long long

ll ms(vector<int>& v) {
    ll ans = 0;
    int n = v.size();
    if (n <= 1)
        return ans;
     vector<int> v1(n / 2);
    vector<int> v2(n / 2 + n % 2);
    for (int i = 0; i < n / 2; i++)
        v1[i] = v[i];
    for (int i = n/2; i < n; i++)
        v2[i - n / 2] = v[i];
    ll hans1 = ms(v1); ll hans2 = ms(v2);
    int n1 = v1.size(), n2 = v2.size();
    int p1 = 0, p2 = 0;
    ans = hans1 + hans2;
    for (int i = 0; i < n; i++) {
        if (p1 == n1)
            v[i] = v2[p2++];
        else if (p2 == n2)
            v[i] = v1[p1++], ans += p2;
        else if (v1[p1] == v2[p2])
            v[i] = v1[p1++], ans+=p2;
        else if (v1[p1] > v2[p2])
             v[i] = v2[p2++];
        else v[i] = v1[p1++], ans+=p2;
    }
    return ans;
}

void slv() {
    int n; cin >> n;
    map<ll, int> freq;
    map<pair<int,int>, int> freqv;
    ll ans = 0;
    ll a, b; cin >> a >> b;
    int c = 0;
    while (n--) {
        ll x; cin >> x;
        ll y = a * x + b;
        ll vx, vy; cin >> vx >> vy;
        ll crs = vx*a - vy;
        freq[crs]++;
        freqv[{vx, vy}]++;
    }
    for (auto p : freq)
        ans += p.second * (p.second - 1ll);
    for (auto p : freqv)
        ans -= p.second * (p.second - 1ll);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t = 1;
    while (t--)
        slv();
}