#pragma GCC optimize ("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int > vi;
typedef vector<ll > vl;
#define pb push_back
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fr(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(v) (v).begin(), (v).end()
#define sz() size()
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7, inf = (1 << 30) - 1 + (1 << 30);
ll add(ll a, ll b){
    if(a + b >= mod){
        return a + b - mod;
    }
    return a + b;
}
ll rem(ll a, ll b){
    if( a <= b){
        return a - b + mod;
    }
    return a - b;
}
ll mul(ll a, ll b){
    return (ll) (a * b) % mod;
}
const ll N = 2e5 + 5;
ll A[N], pr[N];
int main(){
    fastio;
    int n; cin >> n;
    f(i, 1, n + 1) cin >> A[i];
    sort(A, A + n + 1);
    f(i, 1, n + 1) pr[i] = pr[i - 1] + A[i];
    ll ans = 0, div = n;
    f(i, 1, n + 1)
        ans += i*A[i] - pr[i - 1] + pr[n] - pr[i] - (n - i)*A[i];
    ll g = __gcd(ans, div);
    cout << ans/g <<' ' << div/g <<'\n';
    return 0;
}

/*
#################################################################################################
#                                        You told me                                            #
#           At your absolute best, you still won't be good enough for the wrong person          #
#                   At your worst, you'll still be worth it to the right person                 #
#                           It was good while it lasted, good bye                               #
#    I believe I really loved you... to that point that I always wanted to hear your voice      #
#    But before my hand could reach you... you seem to be slowly disappearing from my sight     #
#################################################################################################
*/


					     	   	  			 	 	     		