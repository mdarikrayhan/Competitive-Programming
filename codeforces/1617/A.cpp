#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const double PI = acos(-1.0);
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define ld long double
#define ve vector<ll>
#define vep vector<pair<ll,ll>>
#define graph vector<ve>
#define visit vector<bool>
#define db(...) 7
#define fix(res, n) fixed <<  setprecision(n) << (long double)res
#define all(num)      (num).begin(), (num).end()
#define el            cout<<(testcase?"\n":"")


//           "وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
//                                      My way to My dream


//#ifdef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
//bool ok(int x, int y, int n, int m) {
//    return x >= 0 && y >= 0 && x < n && y < m;
//}
//ve dx = {1, 0, -1, 0, 1, -1, 1, -1};
//ve dy = {0, 1, 0, -1, -1, 1, 1, -1};
//ve dx = {1, 0, -1, 0};
//ve dy = {0, 1, 0, -1};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const ll N = 3e5 + 1, mod = 1e9 + 7, OO = 2e18, LOG = 15;

void solution() {
    string s, t;
    cin >> s >> t;
    map<char, int> mp;
    for (int i = 0; i < s.size(); ++i) {
        mp[s[i]]++;
    }
    if (mp.find('a') == mp.end() || mp.find('b') == mp.end() || mp.find('c') == mp.end()) {
        sort(all(s));
        cout << s;
    } else {
        string ss;
        for (auto x: mp)
            ss.push_back(x.first);
        if (ss[0] != t[0] || ss[1] != t[1] || ss[2] != t[2]) {
            for (auto x: mp)
                for (int i = 0; i < x.second; ++i) {
                    cout << x.first;
                }
        } else {

            swap(ss[1], ss[2]);
            for (int i = 0; i < ss.size(); ++i) {
                for (int j = 0; j < mp[ss[i]]; ++j) {
                    cout << ss[i];
                }
            }
        }
    }
}

int main() {
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solution();
        cout << (tc ? "\n" : "");
    }
}

