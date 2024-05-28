#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int MAXN = 3001;
const int MOD = 1000000007;
ll twoToThePowerOf[MAXN];

void precomputePowersOfTwo() {
    twoToThePowerOf[0] = 1;
    twoToThePowerOf[1] = 2;
    for (int i = 2; i <= MAXN; i++) {
        twoToThePowerOf[i] = (twoToThePowerOf[i-1]*2)%MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> arrays[MAXN];

    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        arrays[n].emplace_back(a);
    }

    sort(arrays[n].begin(), arrays[n].end());
    precomputePowersOfTwo();

    // keep track of total effective subtracted
    // for lengths n to 2 (process these arrays and construct the n-1 version)
    // current subtraction from the entire array is equal to the smallest element at this level
    // add that number * two to the power of (len-1) to the running effectively subtracted total
    // construct an array nx of size len-1 where all point to i+2
    // in the mean time, add plls to a priority queue sorted in non-decreasing order (arrays[len][i]+arrays[len][i+1]-2s, i)
    // then, for exactly len-1 times, take the top from the queue:
    // place the first to arrays[len-1]
    // add to queue (arrays[len][second] + arrays[len][nx[second]] - 2s, second) and increment nx[second] => ONLY IF nx[second] IS LESS THAN len

    // for (int i = 0; i < 10; i++) {
    //     cout << twoToThePowerOf[i] << "\n";
    // }
    ll totEffectiveSubtracted = 0;
    for (int len = n; len >= 2; len--) {
        ll s = arrays[len][0];
        totEffectiveSubtracted += (s * twoToThePowerOf[len-1])%MOD;
        // cout << totEffectiveSubtracted << "\n";
        totEffectiveSubtracted %= MOD;

        vector<int> nx; priority_queue<pll, vector<pll>, greater<pll>> q;
        for (int i = 0; i < len-1; i++) {
            nx.emplace_back(i+2);
            q.push(make_pair(arrays[len][i]+arrays[len][i+1]-(2*s), i));
        }

        for (int i = 0; i < len-1; i++) {
            pll curr = q.top(); q.pop();
            arrays[len-1].emplace_back(curr.first);
            if (nx[curr.second] < len) {
                q.push(make_pair(arrays[len][curr.second]+arrays[len][nx[curr.second]]-(2*s), curr.second));
                nx[curr.second]++;
            }
        }
    }

    // cout << arrays[1][0] << " " << totEffectiveSubtracted << "\n";
    cout << ((arrays[1][0] + totEffectiveSubtracted)%MOD) << "\n";
}