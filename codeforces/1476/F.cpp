//Never compromise. Not even in the face of Armageddon.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

//pragmas
#pragma GCC optimize("03")
#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("01, 02, 03, 0fast, unroll-loops")              //Retard mode
//#pragma GCC optimize("Ofast,unroll-loops,omit-frame-pointer,inline")     //Optimization flags
//#pragma GCC option("arch=native,tune=native,no-zero-upper")              //Enable AVX

//types
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll int
#define TYPE long long
#define ppair pair<TYPE, TYPE>
#define vecvec(a, i, j, x) vector<vector<TYPE>> a (i, vector<TYPE> (j, x))
#define vecvecvec(a, i, j, k, x) vector<vector<vector<TYPE>>> a (i + 1, vector<vector<TYPE>>(j + 1, vector<TYPE>(k + 1, x)))

using namespace std;
using namespace __gnu_pbds;

//random stuff
#define all(a) a.begin(),a.end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define sz(x) (long long int)x.size()
#define F first
#define S second
#define sp " " 
const int inf = 0x3f3f3f3f, INF = 1;

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;             //for multiset, use less_equal and erase x in multiset a -> a.erase(a.find_by_order(a.order_of_key(x)))
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define safe_map unordered_map<long long, int, custom_hash>
#define hashmap gp_hash_table<int, int, custom_hash>


//debug
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) {cerr << "[" << #x << "] = ["; _print(x);}
#define reach cerr<<"reached"<<endl
#else
#define debug(x...)
#define reach 
#endif


//#define int int64_t

const int MAXN = 2e5+5;

struct node
{
    pair<int, int> mx=mp(-inf, -inf);
    node() : mx(mp(-inf, -inf)) {};
};
struct SegTree
{
    ll N;
    vector<node> st;
    vector<bool> cLazy;
    vector<int> lazy;
    void init(ll n)
    {
        N=n;
        st.resize(4*N+5);
        cLazy.assign(4*N+5,false);
        lazy.assign(4*N+5,-inf);
    }
    void merge(node &cur,node &l,node &r) 
    {
        cur.mx=max(l.mx, r.mx);
    }

    // be careful about that one lifting case in range add, range max qr for ex
    void propagate(ll ver,ll L,ll R)
    {
        if(L!=R)		//passing on lazy shit to children
        {
            cLazy[ver*2]=cLazy[ver*2+1]=1;
            lazy[ver*2]=max(lazy[ver], lazy[ver*2]),lazy[ver*2+1]=max(lazy[ver], lazy[ver*2 + 1]); 
        }
        st[ver].mx = max(st[ver].mx, mp(lazy[ver], (int)R));
        cLazy[ver]=0,lazy[ver]=-inf;
    }
    node Query(ll ver,ll L,ll R,ll i,ll j)
    {
        if(cLazy[ver])propagate(ver, L, R);
        if(j<L || i>R)return node();
        if(i<=L && R<=j)return st[ver];
        ll M=(L+R)/2;
        node left=Query(ver*2,L,M,i,j),right=Query(ver*2+1,M+1,R,i,j),cur;
        merge(cur,left,right);
        return cur;
    }
    node pQuery(ll ver,ll L,ll R,ll pos)
    {
        if(cLazy[ver])propagate(ver,L,R);
        if(L==R)return st[ver];
        ll M=(L+R)/2;
        if(pos<=M)return pQuery(ver*2,L,M,pos);
        else return pQuery(ver*2+1,M+1,R,pos);
    }	
    void Update(ll ver,ll L,ll R,ll i,ll j,ll val)
    {
        if(cLazy[ver])propagate(ver,L,R);
        if(j<L||i>R)return;
        if(i<=L && R<=j)
        {
            cLazy[ver]=1,lazy[ver]=max(lazy[ver], (int)val);
            propagate(ver,L,R);
            return;
        }
        ll M=(L+R)/2;
        Update(ver*2,L,M,i,j,val),Update(ver*2+1,M+1,R,i,j,val);

        merge(st[ver],st[ver*2],st[ver*2+1]);
    }
    void pUpdate(ll ver,ll L,ll R,ll pos,ll val)
    {
        if(cLazy[ver])propagate(ver,L,R);
        if(L==R)
        {
            st[ver].mx = max(st[ver].mx, mp((int)val, (int)L));
            return;
        }
        ll M=(L+R)/2;
        if(pos<=M)pUpdate(ver*2,L,M,pos,val);
        else pUpdate(ver*2+1,M+1,R,pos,val);

        merge(st[ver],st[ver*2],st[ver*2+1]);
    }

    node query(ll pos)
    {
        return pQuery(1, 1, N, pos);
    }
    node query(ll l, ll r)
    {
        return Query(1, 1, N, l, r);
    }
    void update(ll pos, ll val)
    {
        pUpdate(1, 1, N, pos, val);
    }
    void update(ll l, ll r, ll val)
    {
        Update(1, 1, N, l, r, val);
    }
};

//code starts
int32_t main()
{
    fastio();
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for(int i = 1; i <= n; i ++)    cin >> p[i];

        SegTree rq;
        rq.init(n + 2);

        string s(n, 'R');
        vector<int> b(n + 2);       //back link for creation of state using a left-oriented segment (i or i - 1)
        vector<int> m(n + 2);       //back link for maximum value encountered when creating a particular L-type (m[i] for original i, not shifted)

        b[0] = 0;
        m[0] = 0;

        int till = 1;
        b[1] = 0;
        m[1] = 0;
        rq.update(1, 1 + p[1]);

        for(int i = 2; i <= n; i ++)
        {
            auto qr1 = rq.query(i).mx;
            auto qr2 = rq.query(max(1, i - p[i]), i - 1).mx;

            // set right (only to possible states)
            rq.update(1, till, i + p[i]);

            int self = -inf, next = -inf;

            //prefix satisfied set right
            if(qr1.first >= i)                  //prefix shit covers i
            {
                till = max(till, i + 1);
                b[i + 1] = b[qr1.second];
                rq.update(i + 1, max(qr1.first, i + p[i]));
                next = max(qr1.first, i + p[i]);
            }
            else if(qr1.first == i - 1)         //prefix shit does not cover i
            {
                till = max(till, i);
                b[i] = b[qr1.second];
                rq.update(i, i + p[i]);
                self = i + p[i];
            }

            if(p[i] == 0)   continue;

            //set left
            if(qr2.first >= i and qr2.first > next)
            {
                till = max(till, i + 1);
                b[i + 1] = i;
                rq.update(i + 1, qr2.first);
            }
            else if(qr2.first > 0 and qr2.first < i and i > self)
            {
                till = max(till, i);
                b[i] = i;
                rq.update(i, i);
            }

            m[i] = qr2.second;
        }

        int opt = rq.query(n + 1).mx.first;

        if(opt >= n)
        {
            cout << "YES" << endl;
            
            int i = n + 1;

            while(b[i] != 0)
            {
                s[b[i] - 1] = 'L';
                i = m[b[i]];
            }

            cout << s << endl;
        }
        else
            cout << "NO" << endl; 
    }
}





// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.