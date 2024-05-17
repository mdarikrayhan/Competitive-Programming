/*
    Author Youssef_Sobhy
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long int
#define endl "\n"
#define fastread() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sz(x) (int)x.size()
#define fr(i , begin , end) for (ll i = begin ; i < end ; i++)
#define frr(i , begin , end) for (ll i = begin ; i >= end ; i--)
#define all(ch) ch.begin() , ch.end() 
#define allr(ch) ch.rbegin() , ch.rend()
#define ON(n , k) ( (n) | (1 << (k)) )
#define mem(arr, val) memset(arr , val , sizeof arr)
#define kill(x) cout << x << endl ;
#define OFF(n , k) ((n) & ~(1 << (k)))
#define isON(n , k) (((n) >> k) & 1)

const ll inf = 2e18 ;
const ll MOD = 1e9 + 7 ;

int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
char di[] = {'D', 'L', 'U', 'R'};

ll add(const ll &a, const ll &b) {
    return (a + b + 2 * MOD) % MOD;
}   

ll mul(const ll &a, const ll &b) {
    return (a % MOD + MOD) * (b % MOD + MOD) % MOD;
}

ll sub(const ll a, const ll b){
    return (a % MOD - b % MOD + 2 * MOD) % MOD;
}

const ll N = 1e6 + 10 ;



void solve (){
    ll n ;
    cin >> n ;
    vector<ll> a(n) , ans ;
    fr(i , 0 , n) cin >> a[i] ;
    map<ll , ll> m , entered ;
    ll last = 0 ;
    fr(i , 0 , n){
        if (a[i] > 0 && entered[a[i]]) {
            if (sz(m) > 0) return void (cout << -1 << endl) ;
            else {
                ans.push_back(i - last) ;
                last = i ;
                entered.clear() ;
                entered[a[i]] ++ ;
                m[a[i]] ++ ;
            }
        }
        if (a[i] > 0){
            m[a[i]] ++ ;
            entered[a[i]] ++ ;
        }
        else {
            if (m[abs(a[i])] > 0) {
                m.erase(abs(a[i])) ;
                if (sz(m) == 0) {
                    ans.push_back(i - last + 1) ;
                    last = i + 1;
                    entered.clear() ;
                    entered[a[i]] ++ ;
                }
            }
            else return void (cout << -1 << endl) ;
        }
    }
    if (sz(m) > 0) return void (cout << -1 << endl) ;
    kill(sz(ans)) ;
    fr(i , 0 , sz(ans)) cout << ans[i] << " " ;
    cout << endl ;
}// CHECK LONG LONG 


int main() {
    fastread()
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll Test ;
    Test = 1 ;
    // cin >> Test ;
    for (int _ = 1 ; _ <= Test ; _++){
        cout << fixed << showpoint << setprecision(10) ;
        // cout << "Case #" << _ << ": " ;
        solve() ;
    }
} 
