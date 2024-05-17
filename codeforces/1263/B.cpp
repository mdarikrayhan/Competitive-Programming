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
    ll n ; cin >> n ;
    vector<pair<string , int>> a(n) ;
    fr(i , 0 , n) cin >> a[i].first , a[i].second = i ;
    sort(all(a)) ;
    map<int , map<int , int>> m ;
    fr(i , 0 , 4){
        fr(j , 0 , n){
            m[i][a[j].first[i] - '0'] ++ ;
        }
    }
    ll ans = 0 ;
    map<string , int> cnt ;
    cnt[a[0].first] ++ ;
    fr(i , 1 , n){
        if(cnt[a[i].first] > 0){
            int ok = 0 ;
            fr(k , 0 , 4){
                fr(j , 0 , 10){
                    if (!m[k].count(j)){
                        ok = 1 ;
                        char c = '0' + j ;
                        m[k][a[i].first[k] - '0'] -- ;
                        a[i].first[k] = c ;
                        m[k][c - '0'] ++ ; ;
                        break ;
                    }
                }
                if (ok) break ;
            }
            ans ++ ;
        } 
        cnt[a[i].first] ++ ;
    }
    kill(ans) ;
    vector<string> res(n) ;
    fr(i , 0 , n) {
        res[a[i].second] = a[i].first ;
    }
    fr(i , 0 , n){
        kill(res[i]) ;
    }
}// CHECK LONG LONG 


int main() {
    fastread()
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll Test ;
    Test = 1 ;
    cin >> Test ;
    for (int _ = 1 ; _ <= Test ; _++){
        cout << fixed << showpoint << setprecision(10) ;
        // cout << "Case #" << _ << ": " ;
        solve() ;
    }
} 
