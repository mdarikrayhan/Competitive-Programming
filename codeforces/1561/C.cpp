#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
#define ll long long
#define nline "\n"
#define pb push_back
const ll mod = 998244353;

void solve() {
	int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++) {
        int k; cin >> k;
        vector<int> v(k);
        for(int j=0; j<k; j++) {
            cin >> v[j];
            v[j] += 1-j;
        }
        int maxPow = -1e9-2;
        for(int j=0; j<k; j++) maxPow = max(maxPow, v[j]);
        arr[i] = {maxPow, k};
    }

    sort(arr.begin(), arr.end());
    vector<ll> prefix(n); prefix[0] = arr[0].second;
    for(int i=1; i<n; i++) {
        prefix[i] = arr[i].second+prefix[i-1];
    }
    
    int s=1, e=1e9+1;
    while(s<=e) {
        int mid = (s+e)/2;
        int pow = mid;
        bool flag = true;
        for(int i=0; i<n; i++) {
            if(pow < arr[i].first) {
                flag = false;
                break;
            }
            pow += arr[i].second;
        }

        if(flag) e = mid-1;
        else s = mid+1;
    }

    cout << s << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    // cout << "test cases: " << t << "\n";
    while(t--) solve();
}
