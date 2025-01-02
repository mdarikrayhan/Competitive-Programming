/*
    Created by:- milind0110
*/
// #pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #pragma comment(linker, "/STACK:268435456");
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define int long long
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 5;
const int inf = 1e9;

class segtree{
public:
    vector<int> tree;
    vector<int> v;
    int l,r,ind,val,n,segnull;
    segtree(int nn,vector<int> a){
        n = nn;
        tree.resize(4 * n);
        v = a;
        buildTree(0,n - 1,1);
        //assign segnull
        //update comb and upd
        segnull = 0;
    }
    inline int comb(const int &x,const int &y){
        return x + y;
    }
    inline void upd(int &x,const int &val){
        x = val;
    }
    void buildTree(int start,int end,int node){
        if(start == end){
            tree[node] = v[start];
            return ;
        }
        int mid = (start+end)/2;
        buildTree(start,mid,node*2);
        buildTree(mid+1,end,node*2+1);
        tree[node] = comb(tree[node*2],tree[node*2+1]);
    }
    void build(){
        buildTree(0,n - 1,1);
    }
    void updateTree(int start,int end,int node){
        if(start == end){
            upd(v[ind],val);
            upd(tree[node],val);
            return;
        }
        int mid = (start+end)/2;
        if(ind <= mid){
            updateTree(start,mid,node*2);
        }
        else{
            updateTree(mid+1,end,node*2+1);
        }
        tree[node] = comb(tree[node*2],tree[node*2+1]);
    }
    void update(int iind,int vval){
        ind = iind,val = vval;
        updateTree(0,n - 1,1);
    }
    int query(int start,int end,int node){
        if(end < l || start > r)
            return segnull;
        if(l <= start && end <= r){
            return tree[node];
        }
        int mid = (start+end)/2;
        int sol1 = query(start,mid,node*2);
        int sol2 = query(mid+1,end,node*2+1);
        return comb(sol1,sol2);
    }
    int query(int ll,int rr){
        l = ll,r = rr;
        return query(0,n - 1,1);
    }
};
void solve(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    segtree s(n,a);
    int sum = accumulate(a.begin(),a.end(),0LL);
    int ans = 0;
    int cnt = n;
    while(sum > 0){
        if(t >= sum){
            ans += t / sum * cnt;
            t %= sum;
        } else {
            int low = 0,high = n - 1;
            int r = -1;
            while(low <= high){
                int mid = (low + high) >> 1;
                if(s.query(0,mid) <= t){
                    r = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            sum -= a[r + 1];
            s.update(r + 1,0);
            cnt--;
        }
    }
    cout << ans << "\n";
    


}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int32_t t = 1;
    // cin >> t;
    for(int32_t i = 1; i <= t; i++){
        solve();
    }
    return 0; 
}  
