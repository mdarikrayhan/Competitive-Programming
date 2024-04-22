#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl "\n"

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        bool no = false;
        ll n, f, a, b; cin >> n >> f >> a >> b;
        vector<ll> nums(n), res(n);

        for (int i = 0; i < n; i++) cin >> nums[i];

        res[0] = nums[0];

        for (int i = 1; i < n; i++){
            res[i] = nums[i] - nums[i - 1];
        }

        for (ll i: res){
            f -= min(i * a, b);

            if (f <= 0){
                no = true;
                break;
            }
        }

        if (no) cout << "no\n";
        else cout << "yes\n";
    }

    return 0;
}