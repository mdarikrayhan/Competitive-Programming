#include <iostream>
#include <algorithm>
#define ll long long 

using namespace std;

int main() {
    ll n, l, r, x;
    cin>>n>>l>>r>>x;
    ll nums[n];
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    
    ll c = 0;
    for(ll mask = 0; mask < (1ll << n); mask++) {
        ll sum = 0;
        ll mn = 10e9+1, mx = 0;
        ll h = 0;
        for(ll i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                sum += nums[i];
                mn = min(nums[i], mn);
                mx = max(nums[i], mx);
                h++;
            }
        }

        if(l <= sum && sum <= r && mx - mn >= x && h >= 2) {
            c++;
        }
    }
    cout<<c;
}