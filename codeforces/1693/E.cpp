#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
const ll ILL=2167167167167167167;
const int INF=1010000000;
const int mod=998244353;
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
bool yneos(bool a,bool upp=0){if(a){cout<<(upp?"YES\n":"Yes\n");}else{cout<<(upp?"NO\n":"No\n");}return a;}
template<class T> void vec_out(vector<T> &p,int ty=0){
if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}
else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}}
template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
template<class T> T vec_sum(vector<T> &a){T ans=T(0);for(auto &x:a) ans+=x;return ans;}
int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
template<class T> bool inside(T l,T x,T r){return l<=x&&x<r;}

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal


template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }
    void addl(int p,S x){
        set(p,op(get(p),x));
    }
    void addr(int p,S x){
        set(p,op(x,get(p)));
    }
    void inti(){
        for(auto &x:d) x=e();
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder
using namespace atcoder;

using F = array<array<int,3>,3>;

F op(F l,F r){
    swap(l,r);
    F tmp;
    rep(i,0,3) rep(j,0,3) tmp[i][j]=INF;
    rep(i,0,3) rep(j,0,3) rep(k,0,3){
        chmin(tmp[i][k],l[i][j]+r[j][k]);
    }
    return tmp;
}

F e(){
    F tmp;
    rep(i,0,3) rep(j,0,3) tmp[i][j]=(i==j?0:INF);
    return tmp;
}

F make_F(int a){
    F res;
    rep(i,0,3) rep(j,0,3) res[i][j]=INF;
    rep(i,0,3){
        int tmp=(i|a);
        if(tmp==3) res[i][0]=1;
        else res[i][tmp]=0;
    }
    return res;
}
void solve();
// oddloop
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    //cin>>t;
    rep(i,0,t) solve();
}

void solve(){
    int N;
    cin>>N;
    vector<int> A(N+2);
    rep(i,1,N+1){
        cin>>A[i];
    }
    vector<int> L(N+1,INF),R(N+1,-INF);
    rep(i,0,N+2){
        chmin(L[A[i]],i);
        chmax(R[A[i]],i);
    }
    vector<vector<int>> G(N+2);
    vector<vector<int>> H(N+2);
    segtree<F,op,e> seg(N+1);
    ll ans=0;
    vector<int> V(N+1,1);
    rep(i,0,N+1) if(L[i]!=INF){
        seg.set(i,make_F(1));
        G[L[i]+1].push_back(i);
        H[R[i]].push_back(i);
    }
    rep(i,0,N+2){
        for(auto x:G[i]){
            V[x]+=2;
            seg.set(x,make_F(V[x]));
        }
        for(auto x:H[i]){
            V[x]-=1;
            seg.set(x,make_F(V[x]));
        }
        auto tmp=seg.prod(0,A[i]);
        rep(j,0,3) if(tmp[0][j]!=INF) ans+=tmp[0][j]+min(j,0);
    }
    cout<<ans<<"\n";
}