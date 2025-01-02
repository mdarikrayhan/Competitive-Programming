#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define pll pair<ll,ll>
#define mp make_pair
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll floor_div(ll x, ll y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x >= 0) return x / y;
    return (x + 1) / y - 1;
}
ll ceil_div(ll x, ll y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x <= 0) return x / y;
    return (x - 1) / y + 1;
}

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> cnt(m+1),a(n);
    for(auto &x : a){
        cin >> x;cnt[x]++;
    }
    for(ll i=m-1; i>=1; i--){
        cnt[i] += cnt[i+1];
    }
    // this win denotes if B can win or not
    ll win = -1;
    for(ll len=1; len<=m; len++){
        if(cnt[len] > (m/len)){
            win = len;
            break;
        }
    }
    auto get_presence = [&](set<ll>& a, ll l, ll r){
        if(a.lower_bound(l) != a.end() && *(a.lower_bound(l)) <= r){
            return 1;
        }
        return 0;
    };
    sort(a.rbegin(),a.rend());
    if(win == -1){
        cout << "Alessia" << endl;
        set<ll> taken;
        for(ll i=0; i<n; i++){
            ll idx = -1;
            for(ll st=1; st+(a[i]-1)<=m; st+=a[i]){
                if(!get_presence(taken,st,st+a[i]-1)){
                    idx = st;
                }
            }
            assert(idx != -1);
            cout << a[i] << " " << idx << endl;
            ll at;
            cin >> at;
            taken.insert(at);
        }
    }
    else{
        cout << "Bernardo" << endl;
        set<ll> taken;
        for(ll i=0; i<n; i++){
            ll len,idx;
            cin >> len >> idx;
            if(len >= win){
                bool ok = 0;
                ll first_contained = -1;
                for(ll here=win; here<=m; here+=win){
                    if(here >= idx && here <= idx+len-1){
                        first_contained = here;
                    }
                    if(here >= idx && here <= idx+len-1 && taken.find(here) != taken.end()){
                        ok = 1;
                        cout << here << endl;
                        taken.insert(here);
                        break;
                    }
                }
                assert(first_contained != -1);
                if(!ok){
                    cout << first_contained << endl;
                    taken.insert(first_contained);
                }
            }
            else{
                cout << idx << endl;
                taken.insert(idx);
            }
        }
    }   
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    solve();
}