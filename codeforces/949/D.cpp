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
// #define double long double
// #define all(x) (x).begin(),(x).end()
// #define allr(x) (x).rbegin(),(x).rend()
// #define sz(x) (int)(x).size()
// #define pb push_back
// #define ppb pop_back
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// const int inf = 1e10;
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
        segnull = 0;
        //update comb and upd
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
    int n,d,b;
    cin >> n >> d >> b;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    //greedily start saving rooms from corners
    deque<pair<int,int>> q;
    segtree s(n,a);
    for(int i = 0; i < n; i++){
        q.push_back({a[i],i});
    }
    vector<int> left(n),right(n);
    int j = 0;
    for(int i = 0; i < n; i++){
        int curr = min(i + 1,n - i);
        while((i - j + d - 1) / d > curr) j++;
        left[i] = j;
    }
    j = n - 1;
    for(int i = n - 1; i >= 0; i--){
        int curr = min(i + 1,n - i);
        while((j - i + d - 1) / d > curr) j--;
        right[i] = j;
    }
    fill(a.begin(),a.end(),0);
    bool turn = true;
    int l = 0,r = n - 1;
    int ans1 = (n + 1) / 2,ans2 = n / 2;
    while(l <= r){
        if(turn){
            int sum = s.query(left[l],right[l]);
            if(sum >= b){
                ans1--;
                int req = b;
                while(!q.empty() && req){
                    auto [val,ind] = q.front();
                    q.pop_front();
                    if((abs(l - ind) + d - 1) / d > l + 1){
                        s.update(ind,0);
                        continue;
                    }
                    int mn = min(val,req);
                    val -= mn;
                    req -= mn;
                    s.update(ind,val);
                    if(val) q.push_front({val,ind});
                }
            }
            l++;
        } else {
            int sum = s.query(left[r],right[r]);
            if(sum >= b){
                ans2--;
                int req = b;
                while(!q.empty() && req){
                    auto [val,ind] = q.back();
                    q.pop_back();
                    if((abs(ind - r) + d - 1) / d > n - r){
                        s.update(ind,0);
                        continue;
                    }
                    int mn = min(val,req);
                    val -= mn;
                    req -= mn;
                    s.update(ind,val);
                    if(val) q.push_back({val,ind});
                }
            }
            r--;
        }
        turn ^= 1;
    }
    cout << max(ans1,ans2) << "\n";
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
