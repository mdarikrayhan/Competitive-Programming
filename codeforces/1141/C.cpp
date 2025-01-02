//Sublime with mod inv and exp

#include<bits/stdc++.h>
#pragma GCC target("popcnt")
#include<iostream>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define inf 1e18
#define nline "\n"

#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
#define ff first
#define ss second
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define _d(x) _p(x); cout << endl;
void _p(ll t)     {cout << t;}
void _p(int t)    {cout << t;}
void _p(string t) {cout << t;}
void _p(char t)   {cout << t;}
void _p(lld t)    {cout << t;}
void _p(double t) {cout << t;}
void _p(ull t)    {cout << t;}
template <class T, class V> void _p(pair <T, V> p);
template <class T> void _p(vector <T> v);
template <class T> void _p(set <T> v);
template <class T, class V> void _p(map <T, V> v);
template <class T> void _p(multiset <T> v);
template <class T, class V> void _p(pair <T, V> p) {cout << "{"; _p(p.ff); cout << ","; _p(p.ss); cout << "}";}
template <class T> void _p(vector <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T> void _p(set <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T> void _p(multiset <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T, class V> void _p(map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}
#define _sz(x) ((int)(x).size())
#define al(x) (x).begin(), (x).end()
#define ral(x) (x).rbegin(), (x).rend()

#define pb push_back
#define int long long int
#define vvi vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define mnh priority_queue<int, vector<int>, greater<int>>
#define mxh priority_queue<int>
#define mii map<int, int>
#define um unordered_map<int, int>
#define vs vector<string>
#define vvs vector<vector<string>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>
vector<vector<int>>d4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>>d8 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
/*-------------------------------------------------------------------------------------------------------------------------*/

bool is_val(int x, int y, int n, int m)
{
    if(x < 0 || y < 0 || x >= n || y >= m)return false;
    return true;
}

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}
int modPow(int b, int p) {
    if (p == 0)
        return 1;

    int x = modPow(b, p / 2);

    return p % 2 == 0 ? mul(x, x) : mul(b, mul(x, x));
}

int moduloInverse(int n) {
    //(p / n) % mod  
    return modPow(n, MOD - 2);
}
int mod_exp(int base, int exp, int mod)
{
    int res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)//if the rightmost bit is set 
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
/*-------------------------------------------------------------------------*/
// construct DSU

struct DSU{
    vector<int>parent;
    DSU(int n)
    {
        parent.resize(n + 5);
        for(int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }

    }
    int find_parent(int a)
    {
        if(parent[a] == a)return a;
        return parent[a] = find_parent(parent[a]); 
    }
    bool belong_to_same_parent(int a, int b)
    {
        int pa = find_parent(a), pb = find_parent(b);
        return pa == pb;
    }
    void merge(int a, int b)
    {
        int pa = find_parent(a);
        int pb = find_parent(b);
        parent[pa] = pb;
    }
};


void solve(){
    int n;
    cin>>n;
    vi v(n - 1);
    for(auto &it : v)cin>>it;
    vi ans;
    ans.pb(1);
    set<int>st;
    st.insert(1);
    for(auto &it : v)
    {
        int cur = ans.back() + it; st.insert(cur);
        ans.pb(cur);
    }
    int mn = *min_element(al(ans));
    int diff = 1 - mn;
    for(auto &it : ans)it += diff;
    int mx = *max_element(al(ans));
    if(mx > n || st.size() != n)
    {
        cout<<"-1"<<endl; return;
    }
    for(auto &it : ans)cout<<it<<" "; cout<<endl;



    
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);    
#endif
fastio();

ll t = 1;
// cin>>t;

while(t--)solve();
return 0;
}

