#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define sz(a) (int)a.size()
#define ALL(v) v.begin(), v.end()
#define ALLR(v) v.rbegin(), v.rend()
#define ll long long
#define pb push_back
#define forr(i, a, b) for(int i = a; i < b; i++)
#define dorr(i, a, b) for(int i = a; i >= b; i--)
#define ld long double
#define vt vector
#include<fstream>
#define fi first
#define se second
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mpp make_pair
#define ull unsigned long long
const ld PI = 3.14159265359, prec = 1e-9;;
//using u128 = __uint128_t;
//const int x[4] = {1, 0, -1, 0};
//const int y[4] = {0, -1, 0, 1};
const ll mod = 1e9 + 19972207, pr = 31;
const int mxn = 5e5 + 5, mxq = 1e5 + 5, sq = 500, mxv = 64;
const ll P = 1e7 + 19, Q = 1e9 + 7;
//const int base = (1 <<18);
const ll inf = 1e9 + 5, neg = -69420, inf2 = 1e18;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// have fun!
// fix A
// count (B, C) so that:
//all cards with a >= A, B > b and C > c -> B > max b and C > maxc
//all cards with a < A, B > b or C > c
struct Card{
    int a, b, c;
    bool operator <(const Card &other){
        return(a < other.a);
    }
};
ll n, p, q, r;
Card card[mxn + 1];
int cntb[mxn + 1], cntc[mxn + 1], pb = mxn, pc = mxn;
void recalc(){
    while(pb && cntb[pb] == 0)pb--;
    while(pc && cntc[pc] == 0)pc--;
}
ll st[4 * mxn + 1], lz[4 * mxn + 1];
void push(int nd, int l, int mid, int r){
    ll &v = lz[nd];
    if(v == -1)return;
    lz[nd << 1] = lz[nd << 1 | 1] = v;
    st[nd << 1] = v * (mid - l + 1); st[nd << 1 | 1] = v * (r - mid);
    v = -1;
    return;
}
ll get(int nd, int l, int r, int ql, int qr){
    if(ql > r || qr < l)return(0);
    if(ql <= l && qr >= r)return(st[nd]);
    int mid = (l + r) >> 1;
    push(nd, l, mid, r);
    return(get(nd << 1, l, mid, ql, qr) + get(nd << 1 | 1, mid + 1, r, ql, qr));
}
void upd(int nd, int l, int r, int ql, int qr, ll v){
    if(ql > r || qr < l)return;
    if(ql <= l && qr >= r){
        st[nd] = v * (r - l + 1); lz[nd] = v;
        return;
    }
    int mid = (l + r) >> 1;
    push(nd, l, mid, r);
    upd(nd << 1, l, mid, ql, qr, v); upd(nd << 1 | 1, mid + 1, r, ql, qr, v);
    st[nd] = st[nd << 1] + st[nd << 1 | 1];
}
void solve(){
    cin >> n >> p >> q >> r; pb = q; pc = r;
    for(int i = 1; i <= 4 * q; i++)lz[i] = -1;
    for(int i = 1; i <= n; i++){
        cin >> card[i].a >> card[i].b >> card[i].c; cntb[card[i].b]++; cntc[card[i].c]++;
    }
    set<pair<int, int>>pos, height; // maintaining decreasing heights 
    pos.insert(mpp(0, inf)); height.insert(mpp(inf, 0)); 
    sort(card + 1, card + n + 1);
    ll ans = 0;
    int rp = 1;
    for(int i = 1; i <= p; i++){
        while(rp <= n && card[rp].a < i){
            cntb[card[rp].b]--; cntc[card[rp].c]--; 
            auto it = pos.lower_bound(mpp(card[rp].b, -1));
            if(it == pos.end() || (*it).se < card[rp].c){
                while(1){
                    auto it2 = pos.lower_bound(mpp(card[rp].b + 1, -1));
                    --it2;
                    if((*it2).se <= card[rp].c){
                        pos.erase(it2); height.erase(mpp((*it2).se, (*it2).fi));
                    }else{
                        break;
                    }
                }
                auto it2 = pos.lower_bound(mpp(card[rp].b + 1, -1));
                --it2;
                upd(1, 1, q, (*it2).fi + 1, card[rp].b, card[rp].c);
                pos.insert(mpp(card[rp].b, card[rp].c)); height.insert(mpp(card[rp].c, card[rp].b));
            }
            rp++;
        }
        recalc();
        ll mxb = pb + 1, mxc = pc + 1, area = (q - mxb + 1) * (r - mxc + 1);
        //cout << area << " ";
        auto it = height.lower_bound(mpp(mxc, -1));
        
           
        int lastpos = (*it).se;
            
        if(lastpos >= mxb){
            area -= get(1, 1, q, mxb, lastpos) - mxc * (lastpos - mxb + 1) + (lastpos - mxb + 1);
        }
        
        //cout << mxb << " " << mxc << "\n";
        //for(auto j: pos)cout << j.fi << ' ' << j.se << "\n";
        //cout << area << "\n";
        ans += area;
    }
    cout << ans;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("i.inp", "r", stdin);
    //freopen("i.out", "w", stdout);
    int tt; tt = 1;
    while(tt--){
        solve();
 
    }
    return(0);
}