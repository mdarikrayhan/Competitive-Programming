#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ull unsigned long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ld long double
#define pb push_back
#define F first
#define S second
#define pii pair <int, ll>
#define int ll

using namespace std;
//using namespace __gnu_pbds;
//typedef tree < pii, null_type, less < pii >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
//mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 5;
const ll inf = 1e16;

int32_t main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fast;

    string s1, s2;
    cin >> s1 >> s2;
    int in1 = 0;
    while (in1 < s1.size() && s1[in1] == '0') {
        in1++;
    }
    int in2 = 0;
    while (in2 < s2.size() && s2[in2] == '0') {
        in2++;
    }
    if (s1.size() - in1 > s2.size() - in2) {
        cout << '>';
        return 0;
    }
    if (s1.size() - in1 < s2.size() - in2) {
        cout << '<';
        return 0;
    }
    while (in1 < s1.size() && in2 < s2.size() && s1[in1] == s2[in2]) {
        in1++;
        in2++;
    }
    if (in1 >= s1.size()) {
        cout << "=";
        return 0;
    }
    if (s1[in1] > s2[in2]) {
        cout << '>';
    } else {
        cout << '<';
    }
    return 0;
}
