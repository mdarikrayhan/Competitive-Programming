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

using node = array<ll,2>;

const ll inf = 1e18;

struct Lazy_add{
    ll n;
    vector<node> t;
    vector<ll> lazy;
    Lazy_add(ll n){
        this->n = n;
        t.assign(4*n,node{0,-inf});
        lazy.assign(4*n,0);
    }
    node t_comb(node l, node r){
        return node{l[0]+r[0],max(l[1],r[1])};
    }
    void upd_comb(ll& oldupd, ll upd){
        oldupd += upd;
    }
    void build_tree(vector<ll>& a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            t[v] = node{a[tl],a[tl]};
        } else {
            ll tm = (tl + tr) / 2;
            build_tree(a, v*2, tl, tm);
            build_tree(a, v*2+1, tm+1, tr);
            t[v] = t_comb(t[v*2],t[v*2+1]);
        }
    }
    void build(vector<ll>& a){
        assert(sz(a) == n);
        build_tree(a,1,0,n-1);
    }
    void apply(ll v, ll l, ll r, ll upd){
        t[v][0] += (r-l+1)*upd;
        t[v][1] += upd;
    }
    void push(ll v, ll tl, ll tr){
        ll tm = (tl+tr)/2;
        upd_comb(lazy[2*v],lazy[v]);
        apply(2*v,tl,tm,lazy[v]);
        upd_comb(lazy[2*v + 1],lazy[v]);
        apply(2*v + 1,tm+1,tr,lazy[v]);
        lazy[v] = 0;
    }
    node query_tree(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) {
            return node{0,-inf};
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        ll tm = (tl + tr) / 2;
        push(v,tl,tr);
        return t_comb(query_tree(v*2, tl, tm, l, min(r, tm)),query_tree(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    node query(ll l, ll r){
        return query_tree(1,0,n-1,l,r);
    }
    void update_tree(ll v, ll tl, ll tr, ll l, ll r, ll upd) {
        if(l > r){
            return;
        }
        if(l == tl && r == tr){
            apply(v,tl,tr,upd);
            upd_comb(lazy[v],upd);
            return;
        }
        ll tm = (tl+tr)/2;
        push(v,tl,tr);
        update_tree(2*v, tl, tm, l, min(r,tm), upd);
        update_tree(2*v + 1, tm+1, tr, max(l, tm+1), r, upd);
        t[v] = t_comb(t[2*v],t[2*v + 1]);
    }
    void update(ll l, ll r, ll upd){
        update_tree(1,0,n-1,l,r,upd);
    }
    ll find_first_greater_tree(ll v, ll tl, ll tr, ll l, ll r, ll x){
        if(l > r){
            return -1;
        }
        if(t[v][1] <= x){
            return -1;
        }
        if(tl == tr){
            return tl;
        }
        else{
            push(v,tl,tr);
            ll tm = (tl+tr)/2;
            ll left = find_first_greater_tree(2*v,tl,tm,l,min(tm,r),x);
            if(left != -1){
                return left;
            }
            return find_first_greater_tree(2*v+1,tm+1,tr,max(l,tm+1),r,x);
        }
    }
    ll find_first_greater(ll l, ll r, ll x){
        ll index = find_first_greater_tree(1,0,n-1,l,r,x);
        return index != -1 ? index : r+1;
    }
    ll find_first_tree(ll v, ll tl, ll tr, ll l, ll r, ll x){
        if(l > r){
            return -1;
        }
        if(t[v][1] < x){
            return -1;
        }
        if(tl == tr){
            return tl;
        }
        else{
            push(v,tl,tr);
            ll tm = (tl+tr)/2;
            ll left = find_first_tree(2*v,tl,tm,l,min(tm,r),x);
            if(left != -1){
                return left;
            }
            return find_first_tree(2*v+1,tm+1,tr,max(l,tm+1),r,x);
        }
    }
    ll find_first(ll l, ll r, ll x){
        ll index = find_first_tree(1,0,n-1,l,r,x); 
        return index != -1 ? index : r+1;
    }
};

void solve(){
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n),ra(n),pref_max(n),suf_max(n),func(n);
    for(ll i=0; i<n; i++){
        ll x;cin >> x;
        a[i] = ra[n-1-i] = x;
    }
    for(ll i=0; i<n; i++){
        pref_max[i] = a[i];
        suf_max[i] = ra[i];
        if(i){
            pref_max[i] = max(pref_max[i],pref_max[i-1]);
            suf_max[i] = max(suf_max[i],suf_max[i-1]);
        }
    }
    for(ll i=0; i<n; i++){
        func[i] = pref_max[i]-suf_max[n-1-i];
    }
    Lazy_add a_st(n),ra_st(n),pref_max_st(n),suf_max_st(n),func_st(n);
    a_st.build(a);
    ra_st.build(ra);
    pref_max_st.build(pref_max);
    suf_max_st.build(suf_max);
    func_st.build(func);
    auto getpoint = [&](){
        ll get = func_st.find_first_greater(0,n-1,0);
        return get-1;
    };
    auto getans = [&](){
        ll m = getpoint();ll ans = 0;
        if(m >= 0){
            ans += pref_max_st.query(0,m)[0];
        }
        if(n-1-m-1 >= 0){
            ans += suf_max_st.query(0,n-1-(m+1))[0]; 
        }
        assert(a_st.query(0,n-1)[0] == ra_st.query(0,n-1)[0]);
        ans -= a_st.query(0,n-1)[0];
        return ans;
    };
    auto process = [&](Lazy_add &a_st, Lazy_add &pref_max_st, ll l, ll r, ll upd){
        ll prev_ma = l ? a_st.query(0,l-1)[1] : -inf;
        ll get = a_st.find_first(l,r,prev_ma);
        if(get <= r){
            pref_max_st.update(get,r,1);
            if(upd == -1){
                func_st.update(n-1-r,n-1-get,-1);
            }
            else{
                func_st.update(get,r,1);
            }
            if(r+1 < n){
                ll get2 = a_st.find_first_greater(r+1,n-1,a_st.query(l,r)[1]);
                get2--;
                if(get2 >= r+1){
                    pref_max_st.update(r+1,get2,1);
                    if(upd == -1){
                        func_st.update(n-1-get2,n-1-(r+1),-1);
                    }
                    else{
                        func_st.update(r+1,get2,1);
                    }
                }
            }
        }
        a_st.update(l,r,1);
    };
    cout << getans() << nline;
    while(q--){
        ll l,r;
        cin >> l >> r;
        l--;r--;
        process(a_st,pref_max_st,l,r,1);
        process(ra_st,suf_max_st,n-1-r,n-1-l,-1);
        cout << getans() << nline;
    }
    return;
}


/*-------------------------------------------------------------------------------------------------------------------*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    solve();
}