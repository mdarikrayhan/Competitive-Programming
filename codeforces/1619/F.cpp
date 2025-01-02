#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,tune=native")
using namespace std;
typedef long long ll;

const int N = 1e5 * (2ll * 2ll) + 100ll;

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

ll t;
cin >> t;
while(t--){

ll n, m, k;
cin >> n >> m >> k;

ll big = n % m;
ll small = m - (n % m);

ll idx = 1ll;

for(ll i = 1; i <= k; ++i){

    set<ll>st;

    for(ll l = 1; l <= n; ++l){
        st.insert(l);
    }



        ll rem1 = big;
        ll rem2 = small;

        while(rem1--){

            cout << (n / m) + 1 << " " ;

            for(ll l = 1; l <= (n / m) + 1; ++l){

            cout << idx << " ";

            st.erase(st.find(idx));

            idx++;

            if(idx == n + 1) idx = 1ll;

            }

            cout << endl;

        }
        ll last = -1ll;
        vector<ll>v;
        for(auto x : st){
            v.push_back(x);
        }

        while(rem2--){

            ll cnt = 0;

            cout << n / m << " ";
            last++;
            ll rem = 0ll;
            for(ll I = last; I < last + (n / m); ++I){

                cout << v[I] << " ";

                rem = max(rem, I);

            }
            last = max(last, rem);
            cout << endl;



    }



}
cout << endl;
}

return 0;

}
