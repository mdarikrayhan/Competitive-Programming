#include <bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define ll long long
//#define int long long
const ll oo = 1e18, nx = 2003, mod = 1e9 + 7, N = 2e5 + 2;
int frq[N];
void solve() {
   int n; cin >> n;
    while (n--){
        int a; cin >> a;
        ++frq[a];
    }
    int st{-1}, mx{}, b{}, cur{};
    for(int i{1}; i < N; ++i){
        if(frq[i] == 0){
            if(~st){
                if(mx < cur)
                    mx = cur, b = st;
            }
            cur = 0;
            st = i + 1;
            continue;
        }
        cur += frq[i];
        if(frq[i] == 1){
            if(~st){
                if(mx < cur)
                    mx = cur, b = st;
            }
            cur = 1;
            st = i;
            continue;
        }
        if(!~st)
            st = i;
    }
    cout << mx << '\n';
    vector<int>p;
    deque<int>s;
    int x = b;
    while (true){
        for(int j{}; j < frq[x]; j++){
            p.emplace_back(x);
        }
        if(x != b){
            p.pop_back();
            s.emplace_front(x);
        }
        ++x;
        if(p.size() + s.size() == mx)
            break;
    }
    for(auto& i: p) cout << i << ' ';
    for(auto& i: s) cout << i << ' ';
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//    SPF();
//    preprocess();
//    sieve();
    int t{1};
//    cin >> t;
    while (t--)
        solve();
}

			   		   	  			 			 	 		 		