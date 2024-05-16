//в жопу бога
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>


//#define double long double
#define int int_fast64_t
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());


const double PI = 3.1415926535897932384626;
const int INF = 1e9;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;
const int MOD1 = 1e9 + 3;

vector<vector<int>> lt, rt;
vector<int> ll, rr;
vector<int> k;

int getL(int l, int r) {
    int n = k[r - l + 1];
    return max(lt[n][l], lt[n][r - (1 << n) + 1]);
}

int getR(int l, int r) {
    int n = k[r - l + 1];
    return min(rt[n][l], rt[n][r - (1 << n) + 1]);
}

long long get(vector<long long> &pref, int l, int r) {
    return pref[r + 1] - pref[l];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 1; i++) {
            sum += a[i];
        }
        if ((sum + a[n - 1]) % 2 == 0 && sum >= a[n - 1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

}