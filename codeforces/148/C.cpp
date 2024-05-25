#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ld long double
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define rev(x) reverse(x.begin(), x.end())
#define fi first
#define se second
#define pb push_back
#define PI 3.14159265359
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
#define sortpairbysec(x) sort(all(x), sortbysec)
bool sortcond(const pair<int,int> &a,const pair<int,int> &b){
    if (a.fi != b.fi){
        return a.fi < b.fi;
    } else {
        return a.se > b.se;
    }
}
struct myComp {
    constexpr bool operator()( pii const& a, pii const& b) const noexcept
    {
        if (a.first != b.first){
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    }
};
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
ll rng(ll lim) {
    uniform_int_distribution<ll> uid(0,lim-1);
    return uid(rang);
}

const int mod = 998244353;
const int N = 3e5, M = N;
const ll inf = 1e18;
//=======================

//=======================
// & - bitwise AND; | - bitwise OR; ^ - bitwise XOR
// cout.precision(7);
// next_permutation(arr.begin(), arr.end());
// long long long long long long long long long long long long long long long long long long long long long long long long long long long
// priority_queue<int, vector<int>, greater<int>> a; (min heap)
// ll hash1 = hash<string>{}(to_string(1));
// always lower_bound
// __builtin_clz(n) count leading zeros

vl a;
ll n, m, k, q;
void solve(int tc) {
    int i, j;
    cin >> n >> m >> k;
    if (k == 0) {
        if (m == 0){
            fo(i, n) cout << 1 << " ";
            return;
        }
        if (m >= n-1) {
            cout << -1;
            return;
        }
        cout << 1 << " ";
        n--;
    }
    int num = 1;
    cout << num << " ";
    n--;
    while (k--) {
        num *= 2;
        cout << num << " ";
        n--;
    }
    while (m--) {
        num++;
        cout << num << " ";
        n--;
    }
    while (n--) cout << 1 << " ";
    
    
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    int i;
    fo(i, t) {
        solve(i+1);
    }
    return 0;
}