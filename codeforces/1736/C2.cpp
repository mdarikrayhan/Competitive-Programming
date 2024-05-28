#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>

using namespace std;



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

/*
Figure out every implementation detail and then only start coding
*/

/*--------------------------- GO DOWN ------------------------------------------------------------------------------*/

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

const ll inf = 1e18;

struct point_update{
    ll n;
    vector<array<ll,2>> t;
    point_update(ll n){
        this->n = n;
        t.assign(4*n,{inf,inf});
    }
    array<ll,2> t_comb(array<ll,2> l, array<ll,2> r){
        array<ll,4> t_ret = {l[0],l[1],r[0],r[1]};
        sort(all(t_ret));
        return array<ll,2> {t_ret[0],t_ret[1]};
    }
    array<ll,2> query_tree(ll v, ll tl, ll tr, ll l, ll r){
        if(l > r){
            return {inf,inf};
        }
        if(l == tl && r == tr){
            return t[v];
        }
        ll tm = (tl+tr)>>1;
        return t_comb(query_tree(2*v,tl,tm,l,min(r,tm)),query_tree(2*v+1,tm+1,tr,max(l,tm+1),r));
    }
    array<ll,2> query(ll l, ll r){
        return query_tree(1,0,n-1,l,r);
    }
    void update_tree(ll v, ll tl, ll tr, ll pos, ll add_val){
        if(tl == tr){
            array<ll,3> t_temp = {t[v][0],t[v][1],add_val};
            sort(all(t_temp));
            t[v][0] = t_temp[0];t[v][1] = t_temp[1];
        }
        else{
            ll tm = (tl+tr)>>1;
            if(pos <= tm){
                update_tree(2*v,tl,tm,pos,add_val);
            }
            else{
                update_tree(2*v+1,tm+1,tr,pos,add_val);
            }
            t[v] = t_comb(t[2*v],t[2*v+1]);
        }
    }
    void update(ll pos, ll new_val){
        update_tree(1,0,n-1,pos,new_val);
    }
};

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n),pref(n),pref_2(n),r(n),r_2(n);
    for(auto &x : a){
        cin >> x;x--;
    }
    point_update st(2*n+1);
    for(ll i=0; i<=2*n; i++){
        st.update(i,n);st.update(i,n);
    }
    for(ll i=n-1; i>=0; i--){
        st.update(i-a[i]+n,i);
        auto get = st.query(i+1+n,2*n);
        r[i] = get[0]-1,r_2[i] = get[1]-1;
    }
    const ll K = (n-2)*(n-1)/2 - 1;
    for(ll i=0; i<n; i++){
        pref[i] = r[i],pref_2[i] = r_2[i];
        if(i){
            pref[i] += pref[i-1];
            pref_2[i] += pref_2[i-1];   
        }
    }
    auto sum = [&](ll l, ll r){
        if(l > r){
            return array<ll,2> {0LL,0LL};
        }
        return array<ll,2> {pref[r] - (l ? pref[l-1] : 0),pref_2[r] - (l ? pref_2[l-1] : 0)};
    };
    vector<vector<ll>> who(n);
    for(ll i=0; i<n; i++){
        who[r[i]].emplace_back(i);
    }
    auto process_dec = [&](ll idx, ll val){
        auto it = lower_bound(all(r),idx)-r.begin();
        assert(it<=idx);
        ll left_most = max(ll(it),idx-val);
        ll ans = sum(left_most,n-1)[0] + sum(0,it-1)[0];
        if(it <= left_most-1){
            ans += (idx-1)*(left_most-it);
        }
        cout << ans-K << nline;
        return;
    };
    auto process_inc = [&](ll idx, ll val){
        if(!idx || who[idx-1].empty()){
            cout << sum(0,n-1)[0]-K << nline;
            return;
        }
        ll left_most = idx-val;
        if(left_most > who[idx-1].back()){
            cout << sum(0,n-1)[0]-K << nline;
            return;
        }
        left_most = max(left_most,who[idx-1].front());
        ll ans = sum(who[idx-1].back()+1,n-1)[0]+sum(left_most,who[idx-1].back())[1]+sum(0,left_most-1)[0];
        cout << ans-K << nline;
        return;
    };
    ll q;
    cin >> q;
    while(q--){
        ll p,x;
        cin >> p >> x;
        p--;x--;
        if(x >= a[p]){
            process_inc(p,x);
        }
        else{
            process_dec(p,x);
        }
    }
}


/*-------------------------------------------------------------------------------------------------------------------*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    solve();
}
