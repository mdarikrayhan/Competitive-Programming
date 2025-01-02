#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rev(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define fr(i, a, b) for (ll i = (a); i < (b); i++)
#define per(i, a, b) for (ll i = (b)-1; i >= (a); i--)
#define trav(a, x) for (auto &a : x)
#define endl '\n'
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll mod = ll(1e9 + 7);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;


void solve() {
    ll n;
    cin>>n;
    ll z = (1LL<<29 ^ 1LL<<30);
    ll ans=0;
    fr(i,1,n-2){
        cout<<i<<" ";
        ans^=i;
    }
    ans^=z;
    cout<<(1LL<<29)<<" ";
    cout<<(1LL<<30)<<" ";
    cout<<ans<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int te,debug=1;
    cin >> te;
    while (te--) {
        solve();
    }
 
    return 0;
}
