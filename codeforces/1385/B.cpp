#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define ll long long
#define veci vector<int>
#define pb push_back
#define popb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    fastio();
    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        unordered_set<int> st;
        vector<int> order;
        
        for (int i = 1; i <= n * 2; ++i) {
            cin >> x;
            if (st.find(x) == st.end()) {
                st.insert(x);
                order.push_back(x);
            }
        }
        
        for (const auto& element : order) {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}
