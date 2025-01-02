#include<bits/stdc++.h>
using namespace std;
#define alyalnmr ios::sync_with_stdio(false),cin.tie(0), cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define ld long double
#define ll long long
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i << " "
#define setp(n) cout << fixed << setprecision(n)
bool can(ll mid,vector<ll>box,ll n,ll s){
    ll j=0;
    for (int i = 0; i < s; ++i) {
        ll time=mid-j-1;
        while(j<n && time){
            ll mn=min(time,box[j]);
            box[j]-=mn;
            time-=mn;
            if(!box[j]){
                j++;
                time--;
            }
        }
    }
    for (int i = 0; i< n; ++i) {
        if(box[i])return 0;
    }
    return 1;
}
void Solve() {
    ll n,s;
    cin >> n >> s;
    vector<ll>box(n),box2;
    ll sum=0;
    for (int i = 0; i < n; ++i) {
        cin >> box[i];
    }
    while(box.back()==0)box.pop_back();

    n=box.size();

    ll l=0,r=1e18,ans=0;
    while (l<=r){
        ll mid=(l+r)/2;
        if(can(mid,box,n,s)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout << ans;
}

    signed main() {
        alyalnmr;
        int t = 1;
        // cin >> t;
        while (t--) {
            Solve();
        }
    }