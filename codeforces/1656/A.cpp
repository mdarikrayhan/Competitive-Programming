#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<long long, long long>, null_type,less<pair<long long, long long>>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

#define T ll tt; cin >> tt; while(tt--)

mt19937_64 gen(chrono::system_clock::now().time_since_epoch().count());

uniform_real_distribution <long double> unif(0.0,1.0);

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef STRIKAZA
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // STRIKAZA
    T{
        int n;
        cin >> n;
        int a[n + 1];
        int mn = 0, mx = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(mn == 0 || a[i] < a[mn])
                mn = i;
            if(mx == 0 || a[i] > a[mx])
                mx = i;
        }
        cout << mn << " " << mx << "\n";
    }
    return 0;
}
