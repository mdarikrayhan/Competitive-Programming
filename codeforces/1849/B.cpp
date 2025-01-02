#include<bits/stdc++.h>
#include<vector>
#define ll long long int
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<pair<ll, ll> > vp;
        for(int i = 0; i < n; i++) {
            ll res = arr[i] % k;
            if(res == 0) {
                res += k;
            }
            pair<ll, ll> p = make_pair(-res, i);
            vp.push_back(p); 
        }
        sort(vp.begin(), vp.end());
        for(int i = 0; i < vp.size(); i++) {
            cout << vp[i].second + 1 << " ";
        }
        cout << endl;
    }
}