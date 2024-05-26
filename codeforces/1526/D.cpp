#include <bits/stdc++.h>
using namespace std;
#define overload1(a, ...) a
#define overload2(a, b, ...) b
#define overload3(a, b, c, ...) c
#define overload4(a, b, c, d, ...) d
#define overload5(a, b, c, d, e ...) e
#define overload6(a, b, c, d, e, f ...) f
#define overload7(a, b, c, d, e, f, g ...) g
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll;
typedef long double ld;
#define chmin(a,b) a = min(a,b);
#define chmax(a,b) a = max(a,b);
#define ceil(a,b) a = a / b + (a % b != 0);
#define bit_count(x) __builtin_popcountll(x)
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(...) overload4(__VA_ARGS__, rep2, rep1, rep0)(__VA_ARGS__)
#define rep0(n) for(int _ = 0 ; _ < n ; _++)
#define rep1(i,n) for(int i = 0 ; i < n ; i++)
#define rep2(i,a,b) for(int i = a ; i < b ; i++)
#define pt(a) cout << a << endl;
#define print(...) printall(__VA_ARGS__);
#define debug(a) cout << #a << " " << a << endl;
#define all(a) a.begin(), a.end()
#define endl "\n";
template<typename T> vector<T> v1(int a, T x) { return vector<T>(a, x); }
template<typename T> vector<vector<T>> v2(int a, int b, T x) { return vector<vector<T>>(a, v1(b, x)); }
template<typename T> vector<vector<vector<T>>> v3(int a, int b, int c, T x) { return vector<vector<vector<T>>>(a, v2(b, c, x)); }
template<typename T> vector<vector<vector<vector<T>>>> v4(int a, int b, int c, int d, T x) { return vector<vector<vector<vector<T>>>>(a, v3(b, c, d, x)); }
template<typename T> vector<vector<vector<vector<vector<T>>>>> v5(int a, int b, int c, int d, int e, T x) { return vector<vector<vector<vector<vector<T>>>>>(a, v4(b, c, d, e, x)); }
template<typename T> vector<vector<vector<vector<vector<vector<T>>>>>> v6(int a, int b, int c, int d, int e, int f, T x) { return vector<vector<vector<vector<vector<vector<T>>>>>>(a, v5(b, c, d, e, f, x)); }
template<typename T,typename U>istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<typename T,typename U>ostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T>istream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>istream &operator>>(istream&is,vector<vector<T>>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<vector<T>>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?"\n":"");}return os;}
template<typename T>ostream &operator<<(ostream&os,const set<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>ostream &operator<<(ostream&os,const multiset<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<class... Args> void printall(Args... args){for(auto i:initializer_list<common_type_t<Args...>>{args...}) cout<<i<<" ";cout<<endl;}

template<typename S, S (*op)(S, S), S (*mapping)(S, S), S (*e)()> struct SegmentTree{
    private:
        int n_, n, log;
        vector<S> node;

        void init_(S ev) { node = {}; node.resize(2*n-1,ev); }
        
        void build(vector<S> V){
            n = 1;
            log = 0;
            while(n < n_) n *= 2, log++;
            node.resize(2*n-1,e());
            for(int i = 0; i < n_; i++) node[n-1+i] = V[i];
            for(int i = n - 2; i >= 0; i--) node[i] = op(node[2*i+1], node[2*i+2]);
        }
        
        void apply_(int k, S x){
            k += n - 1;
            node[k] = mapping(node[k],x);
            while(k > 0){
                k = (k - 1) / 2;
                node[k] = op(node[2*k+1], node[2*k+2]);
            }
        }

        S get_(int k) const { return node[k+n-1]; }

        S prod_(int l, int r) const {
            S lval = e(), rval = e();
            l += n - 1;
            r += n - 1;

            while(l < r){
                if(!(l & 1)) lval = op(lval, node[l++]);
                if(!(r & 1)) rval = op(rval, node[--r]);
                l >>= 1;
                r >>= 1;
            }
            return op(lval, rval);
        }

        S all_prod_() const { return node[0]; }

        template<bool (*f)(S)> int max_right_(int l) const {
            return max_right_(l, [](S x) { return f(x); });
        }

        template<typename F> int max_right_(int l, F f) const {

            l += n;
            S sval = e();

            do {
                while(l % 2 == 0) l >>= 1;
                if(!f(op(sval, node[l-1]))) {
                    while(l < n){
                        l = 2 * l;
                        if(f(op(sval, node[l-1]))) {
                            sval = op(sval, node[l-1]);
                            l++;
                        }
                    }
                    return l - n;
                }
                sval = op(sval, node[l-1]);
                l++;
            } while ((l & -l) != l);

            return n_;
        }

        template<bool (*f)(S)> int min_left_(int r) const {
            return min_left_(r, [](S x) { return f(x); });
        }

        template<typename F> int min_left_(int r, F f) const {
            r += n;
            S sval = e();
            do {
                r--;
                while(r > 1 && r & 1) r >>= 1;
                if(!f(op(sval, node[r-1]))) {
                    while(r < n) {
                        r = 2*r+1;
                        if(f(op(sval, node[r-1]))) {
                            sval = op(sval,node[r-1]);
                            r--;
                        }
                    }
                    return r + 1 - n;
                }
                sval = op(sval, node[r-1]);
            } while((r & -r) != r);

            return 0;
        }

    public:
        SegmentTree(int n): SegmentTree(vector<S>(n, e())) {}
        SegmentTree(const vector<S>& V): n_((int)V.size()) { build(V); }
        void init(S ev) { init_(ev); }
        void apply(int k, S x) { apply_(k, x); }
        S get(int k) const { return get_(k); }
        S prod(int l, int r) const { return prod_(l, r); }
        S all_prod() const { return all_prod_(); }
        template<bool (*f)(S)> int max_right(int l) const { return max_right_<f>(l); }
        template<bool (*f)(S)> int min_left(int  r) const { return min_left_<f>(r); }

};

namespace monoid{
    struct S{ ll sum;};
    S e() { return S{0}; }
    S op(S x , S y) { return S{x.sum + y.sum}; }
    S mapping(S x , S y) { return S{x.sum + y.sum}; }
    int target;
    auto f = [](S x) -> bool { return x.sum < target; };
};


ll f(vector<int> &A, vector<int> &V) {
    int n = A.size();
    vector<monoid::S> INIT(n,{0});
    SegmentTree<monoid::S, monoid::op, monoid::mapping, monoid::e> segtree(INIT);
    vector<vector<int>> U(4);
    rep(i,n) U[V[i]].push_back(i);
    rep(i,4) reverse(all(U[i]));
    ll res = 0;
    rep(i,n){
        int a = A[i];
        int id = U[a].back(); U[a].pop_back();
        segtree.apply(id,{1});
        id += segtree.prod(id+1,n).sum;
        res += id - i;
    }
    return res;
}

void solve(){
    string S; cin >> S;
    ll n = S.size();
    map<char,int> mp;
    map<int,char> org;
    mp['A'] = 0; org[0] = 'A';
    mp['N'] = 1; org[1] = 'N';
    mp['T'] = 2; org[2] = 'T';
    mp['O'] = 3; org[3] = 'O';
    vector<int> A(n);
    rep(i,n) A[i] = mp[S[i]];
    vector<int> cnt(4,0);
    for(int u : A) cnt[u]++;
    vector<int> P = {0,1,2,3};
    ll res = 0;
    vector<int> ans = A;
    do {
        vector<int> V;
        for(int p : P){
            rep(cnt[p]) V.push_back(p);
        }
        ll val = f(A,V);
        if(res < val) {
            res = val;
            ans = V;
        }
    } while (next_permutation(all(P)));
    // pt(res)
    for(int u : ans) cout << org[u]; cout << endl;
}

int main(){
    fast_io
    int t = 1;
    cin >> t;
    rep(i,t) solve();
}