#include <iostream>
#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
 
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
#ifndef ONLINE_JUDGE
#include "./db/debugging.hpp" // pathname
#else
#define debug(...)
#endif
#include <numeric>


typedef unsigned long long ll;
#define int ll
//typedef unsig0ned long long int ull;
#define out1(x) std::cout<<x<<"\n";
#define out(x) std::cout<<x<<" ";
#define vi  vector<int>
#define vll  vector<ll>
#define vs vector<string>
#define sortA(a) sort(a.begin(),a.end())
#define sortD(a) sort(a.begin(),a.end(), greater<ll>())
#define yes() std::cout << "YES\n";
#define no() std::cout << "NO\n";
#define pb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define f(i, k, n) for (int i = k; i < n; i++)
#define fn(i, k, n) for(int i = k; i >=n; i--)
const ll mod = 998244353;
using pll=pair<ll,ll>;
const int N = 1e6+1;
#define trav(a,x) for (auto& a : x)
#define read(a) for(auto &i: a) cin>>i;
#define LOG(x) 63-__builtin_clzll(x)
template <typename T>
T my_abs(T x) {
    return (x < 0) ? -x : x;
}

// int gcd (int a, int b) {
//     return b ? gcd (b, a % b) : a;
// }
template<class T> inline bool cmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool cmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll isSet(ll x,ll i){
    if((x & (1LL<<i))){
        return true;
    }
    return false;
}
#define inf 1e18

void solve(ll tc) {
    ll n,m; cin>>n>>m;
    vll v(m); read(v);
    vll bits(62);
    ll ans=0ll;
    ll sum=accumulate(all(v),0ll);

    if(sum<n){
        out1(-1); return;
    }
    f(i,0,m){
        bits[LOG(v[i])]++;
    }
    f(i,0,61){
        if(isSet(n,i)){
            if(bits[i]){
                bits[i]--;
            }
            else{
                ll j=i;
                ll found=1;
                while(bits[j]==0){
                    j++; ans++;
                }
                bits[j]--;
                i=j; i--; continue; 
            }
        }
        bits[i+1]+=(bits[i]/2);
    }
    out1(ans);
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);// cout.precision(30);
    ll T=1;
  //  cout << fixed << setprecision(20);cout << defaultfloat << setprecision(10);
    // freopen("ride.in", "r", stdin);
	// // // // // // // // // the following line creates/overwrites the output file
	//  freopen("ride.out", "w", stdout);
    //preSolve();
  /// factorial(mod);  InverseofFactorial(mod);
 //  debug(fact[10000]);
   // debug(primes);
     cin>>T;
    //debug(T);
   // clock_t z = clock();
    for (int tc = 1; tc <=T; tc++) {
       solve(tc);
  //   debug((double)(clock() - z) / CLOCKS_PER_SEC);
       
    }
    return 0;
}
/*
    0. Enough array size? Enough array size? Enough array size? Integer overflow?
    
    1. Think TWICE, Code ONCE!
    Are there any counterexamples to your algo?
        
    2. Be careful about the BOUNDARIES!
    N=1P=1? Something about 0?
        
    3. Do not make STUPID MISTAKES!
    Time complexity? Memory usage? Precision error?

    4. Don't overthink, follow your intuition i.e. you dont have to prove everything always 

    5. do smth instead of nothing and stay organized
    // ans = a ? b : c; // to simplify: if (a) ans = b; else ans = c;

*/