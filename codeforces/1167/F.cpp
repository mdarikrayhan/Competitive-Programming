#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define int  long long
#define F    first
#define S    second
#define pb   push_back
#define endl "\n"

const int mod=1e9+7;
const int mod1=998244353;
const int inf=1e18;
const long double pi=2*acos(0.0);
const long double eps=1e-9;
const int N=2e5;

template<class T, class U>
// T -> node, U->update.
struct Lsegtree{
    vector<T>st;
    vector<U>lazy;
    int n;
    T identity_element;
    U identity_update;
    Lsegtree(int n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n,identity_element);
        lazy.assign(4*n, identity_update);
    }
    T combine(T l, T r)
    {
        // change this function as required.
        T ans = (l + r);
        return ans;
    }
    void buildUtil(int v, int tl, int tr, vector<T>&a)
    {
        if(tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        int tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }
    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, int tl, int tr)
    {
        T ans = (curr+ (tr-tl+1)*upd);
        return ans;
    }
    U combineUpdate(U old_upd, U new_upd, int tl, int tr)
    {
        U ans = old_upd;
        ans += new_upd;
        return ans;
    }  
    void push_down(int v, int tl, int tr)
    {
        if(lazy[v] == identity_update)return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if(2*v + 2 < 4*n)
        {
            int tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);            
        }
        lazy[v] = identity_update;
    }
    T queryUtil(int v, int tl, int tr, int l, int r)
    {
        push_down(v,tl,tr);
        if(l > r)return identity_element;
        if(tr < l or tl > r)
        {
            return identity_element;
        }
        if(l <= tl and r >= tr)
        {
            return st[v];
        }
        int tm = (tl + tr)>>1;
        return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
    }
 
    void updateUtil(int v, int tl, int tr, int l, int r, U upd)
    {
        push_down(v,tl,tr); 
        if(tr < l or tl > r)return;
        if(tl >=l and tr <=r)
        {
            lazy[v] = combineUpdate(lazy[v],upd,tl,tr);
            push_down(v,tl,tr);
        }
        else
        {
            int tm = (tl + tr)>>1;
            updateUtil(2*v+1,tl,tm,l,r,upd);
            updateUtil(2*v+2,tm+1,tr,l,r,upd);
            st[v] = combine(st[2*v + 1], st[2*v+2]);
        }
    }



    void build(vector<T>a)
    {
        assert(a.size() == n);
        buildUtil(0,0,n-1,a);
    }
    T query(int l, int r)
    {
        return queryUtil(0,0,n-1,l,r);
    }
    void update(int l,int r, U upd)
    {
        updateUtil(0,0,n-1,l,r,upd);
    }
};

void solve(){

    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    Lsegtree<int,int>tree1(n+1,0,0),tree2(n+1,0,0);
    for(int i=0;i<n;i++){
        cin>>v[i].F;
        v[i].S=i+1;
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++){
        int idx=v[i].S;
        tree1.update(idx,idx,idx);
        tree2.update(idx,idx,n-idx+1);
        int sum_l=tree1.query(1,idx-1);
        int sum_r=tree2.query(idx,n);
        sum_l%=mod;
        sum_r%=mod;
        int curr=(sum_l*(n-idx+1)+idx*sum_r)%mod;
        curr=(curr*v[i].F)%mod;
        ans+=curr;
        if(ans>=mod){
            ans-=mod;
        }
        //cout<<curr<<endl;
    }
    cout<<ans<<endl;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
    while(t--){
        solve();  
    }
    return 0;
}