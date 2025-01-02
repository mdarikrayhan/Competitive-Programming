#include <bits/stdc++.h>
using namespace std;
/*--General Macros--*/
#define l(i,n)              for(ll i=0;i<n;i++)
#define lp(i,k,n)           for(ll i=(ll)k;i<n;i++)
#define W(k)                while(k--)
#define in(k)               cin>>k
#define o(k)                cout<<k<<"\n"
#define nanda               ll n;in(n);ll a[n];l(i,n) in(a[i]);
#define asort(k,n)          sort(k,k+n);
#define ctu                 continue
#define pb                  push_back
#define eb                  emplace_back
#define F                   first
#define S                   second
#define all(k)              k.begin(),k.end()
#define allr(k)             k.rbegin(), k.rend()
#define srt(k)              sort(all(k))
#define forit(map)          for(auto it:map)
#define mp                  make_pair
#define bs(k,a)             binary_search(all(a),k)
#define PLL                 pair<ll, ll>
#define VL                  vector<ll>
#define umap(k)             unordered_map<ll,ll>k
#define _map(k)             map<ll,ll>k
#define yes                 o("YES");return;
#define no                  o("NO");return;
#define stop                o("-1");return;
/*--Instead--*/
using ll = long long;
using ld = long double;
using ull = unsigned long long;
/*--Constants--*/
constexpr ll INF   = 1e10 + 10;
constexpr ll INF1  = 1e12 + 10;
constexpr ll INF2  = 1e15 + 10;
constexpr ll INF3  = 1e18 + 10;
constexpr ll INF4  = 2e18 + 10;
constexpr ld EPS   = 1e-9 - 10;
/*--General Utilities--*/
/*--Pair--*/
#define P(T1,T2)            pair<T1,T2>
/*--Defining STL Containers--*/
/*--Vector--*/
#define V(T)                vector<T>
/*--Map--*/
#define unmap(T1,T2)        unordered_map<T1,T2>
#define map(T1,T2)          map<T1,T2>
/*--Set--*/
#define unset(T)            unordered_set<T>
#define set(T)              set<T>
/*--Operator Overloading--*/
/*--Input--*/
template <typename T1, typename T2>
istream& operator>>(istream& istream, pair<T1, T2>& p){return (istream >> p.first >> p.second);}
template <typename T>
istream& operator>>(istream& istream, vector<T>& v){for (auto& it : v) cin >> it;return istream;}
/*--Output--*/
template <typename T1, typename T2>
ostream& operator<<(ostream& ostream, const pair<T1, T2>& p){return (ostream << p.first << " " << p.second);}
template <typename T>
ostream& operator<<(ostream& ostream, const vector<T>& c){for (auto& it : c) cout << it << " ";return ostream;}


void solution() {
    ll N, M; cin >> N >> M;
    set<ll> filled;
    multiset<ll> diff;
    map<ll, set<ll>> starting_positions;
    map<ll, ll> pos_present;
    auto ins = [&] (ll l, ll r) -> void {
        filled.insert(l);
        filled.insert(r);
        diff.insert(r - l);
        starting_positions[r - l].insert(l);
    };
    auto del = [&] (ll l, ll r) -> void {
        filled.erase(l);
        filled.erase(r);
        diff.erase(diff.find(r - l));
        starting_positions[r - l].erase(l);
    };
    auto add = [&] (ll i) -> ll {
        if((int)filled.size() == 0) {
            filled.insert(1);
            return pos_present[i] = 1;
        }
        if((int)filled.size() == 1) {
            ins(1, N);
            return pos_present[i] = N;
        }
        ll mx = *diff.rbegin();
        ll l = *starting_positions[mx].begin();
        ll r = l + mx;
        ll mid = (l + r) / 2;
        if(mx & 1 && diff.find(mx - 1) != diff.end()) {
            --mx;
            ll nl = *starting_positions[mx].begin();
            ll nr = nl + mx;
            ll nmid = (nl + nr) / 2;
            if(nmid < mid) {
                mid = nmid;
                l = nl;
                r = nr;
            }
        }
        del(l, r);
        if(l > 0)
            ins(l, mid);
        if(r <= N)
            ins(mid, r);
        return pos_present[i] = mid;
    };
    auto remove = [&] (ll i) -> void {
        ll pos = pos_present[i];
        pos_present[i] = 0;
        if(pos == 1) {
            if((int)filled.size() == 1) {
                filled.erase(pos);
                filled.clear();
                diff.clear();
                starting_positions.clear();
                pos_present.clear();
                return;
            }
            ll nxt = *filled.upper_bound(pos);
            del(1, nxt);
            if(nxt <= N)
                ins(-nxt + 2, nxt);
            else {
                filled.erase(pos);
                filled.clear();
                diff.clear();
                starting_positions.clear();
                pos_present.clear();
            }
            return;
        }
        if(pos == N) {
            if((int)filled.size() == 1) {
                filled.erase(pos);
                filled.clear();
                diff.clear();
                starting_positions.clear();
                pos_present.clear();
                return;
            }
            auto it = filled.lower_bound(pos);
            --it;
            ll prev = *it;
            del(prev, pos);
            if(prev > 0)
                ins(prev, 2LL * N - prev);
            else {
                filled.erase(pos);
                filled.clear();
                diff.clear();
                starting_positions.clear();
                pos_present.clear();
            }
            return;
        }
        if((int)filled.size() == 1) {
            filled.clear();
            diff.clear();
            starting_positions.clear();
            pos_present.clear();
            return;
        }
        auto it = filled.upper_bound(pos);
        ll nxt = *it;
        --it;
        assert(it != filled.begin());
        --it;
        ll prev = *it;
        del(prev, pos);
        del(pos, nxt);
        // cerr << "prev: " << prev << ' ' << "nxt: " << nxt << '\n';
        if(prev <= 0 && nxt > N) {
            filled.clear();
            diff.clear();
            starting_positions.clear();
            pos_present.clear();
        }else if(prev <= 0) 
            ins(2 - min(nxt, N), min(nxt, N));
        else if(nxt > N) 
            ins(prev, 2LL * N - prev);
        else
            ins(prev, nxt);
    };
    while(M--) {
        ll type, i; cin >> type >> i;
        if(type == 1) {
            cout << add(i) << '\n';
        } else
            remove(i);
        /*cerr << "filled:\n";
        for(auto x : filled) cerr << x << ' ';
        cerr << '\n';
        cerr << "diff:\n";
        for(auto x : diff) cerr << x << ' ';
        cerr << '\n';
        cerr << "starting_positions:\n";
        for(auto [x, st] : starting_positions) {
            cerr << "with diff = " << x << '\n';
            for(auto x : st) cerr << x << ' ';
            cerr << '\n';
        }
        cerr << '\n';
        cerr << "pos_present:\n";
        for(auto [x, y] : pos_present) cerr << x << " -> " << y << '\n';*/
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ll t=1;
    // in(t);
    W(t)
        solution();
    return 0;
}