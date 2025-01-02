#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((long long)(x).size())
#define all(x) (x).begin(), (x).end()
#define lli long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
int fact[200007];
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


void init_code() {
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("outputf.txt", "w", stdout);

#endif // ONLINE_JUDGE

}
struct node{
    int maxi;
    
    node(lli m=-1)
    {
        maxi=m;
        
    }

};
node merge(node a, node b)
{
    if(a.maxi>=b.maxi)
   return  a;
    else
    return b;
    

}

class seg_tree{
public:
    void build(int ind,int lo, int hi,vector<int>&a,vector<node>&seg,int x)
    {
        if(lo==hi)
        {
            seg[ind]=node(a[lo]);
            return;
        }
        int mid=(lo+hi)/2;
        build(2*ind+1,lo,mid,a,seg,1-x);
        build(2*ind+2,mid+1,hi,a,seg,1-x);
       seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
    }
    node query(int ind, int lo,int hi, int l, int r, vector<node>&seg)
    {
        if(hi<l || lo>r)
        {
            return 0;
        }
        if(lo>=l && hi<=r)
        {
            return seg[ind];
        }
        int mid=(lo+hi)/2;
        node left=query(2*ind+1, lo,mid, l,r, seg);
        node right=query(2*ind+2,mid+1,hi,l,r,seg);
        return merge(left,right); 

    }
    void update(int ind, int lo, int hi, int i, int val, vector<node>&seg)
    {
        if(lo==hi)
        {
            seg[ind]=node(val);
            return;
        }
        int mid=(lo+hi)/2;
        if(i<=mid)update(2*ind+1,lo,mid,i,val,seg);
        else update(2*ind+2,mid+1,hi,i,val,seg); 
        
    }

};

void solve()
{
    
    int n,m;
    cin>>n>>m;
    vector<int>a(m);
    for(int i=0; i<m; i++)
    {
        cin>>a[i];
    }
   
    vector<node>seg(4*m+1);
    int q;
    cin>>q;
    seg_tree sg1;
    sg1.build(0,0,m-1,a,seg,0);
    while(q--)
    {
        int xs,ys,xf,yf,k;
        cin>>xs>>ys>>xf>>yf>>k;
        if(abs(xs-xf)%k!=0 || abs(ys-yf)%k!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        xs=n-abs(n-xs)%k;
        int value=sg1.query(0,0,m-1,ys-1,yf-1,seg).maxi;
         value=max(value,sg1.query(0,0,m-1,yf-1,ys-1,seg).maxi);
        //int x=sg1.query(0,0,m-1,ys-1,ys-1,seg).maxi;
        debug(xs);
        //debug(x);
        debug(value);
        if(value>=xs)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }

    }
    seg.clear();

    


}


signed main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    init_code();
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    // long long T;
    // cin >> T;
    // while (T--)
        solve();
    return 0;
}