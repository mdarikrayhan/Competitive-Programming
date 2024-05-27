#include <bits/stdc++.h>
// Common file
// #include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
// #include <ext/pb_ds/tree_policy.hpp>
// #include <map>
#define fors(n) for (int i = 0; i < n; i++)
#define ULL unsigned long long
#define int long long
#define F first
#define S second
#define pb push_back
#define newl cout << "\n";
#define show(c) cout << c << "\n";
#define spcshow(c) cout << c << ' ';
#define print(v) for(auto it : v){cout << it << ' ';}newl
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vvi vector<vector<int>>
using namespace std;
// using namespace __gnu_pbds; 
const int m1 = 1e9 + 7;
const int m2 = 998244353;
const long long modhash=6235320000053;
int max(int a, int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a < b ? a : b;
}
int absol(int n){
    if (n < 0)
        return -n;
    return n;
}
int binexp(int a, int b, int m=1000000000000000000){
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
        // show(res)
    }
    return res;
}
// segtree for min, can be modified for sum, max, gcd
// int const MAXN=7.2e5+2;
// struct node{
//     int mnv=0;
// };
// vector<node> t(4*MAXN);
// void combine(int v){
//     t[v].mnv=max(t[2*v].mnv,t[2*v+1].mnv);
//     return;
// }
// void build(int v,int l,int r, vi &a){
//     // if(l>r) return;
//     if(l==r){
//         t[v].mnv=a[l];
//         // show(l<<' '<<a[l])
//     }else{
//         int m=(l+r)>>1;
//         build(2*v,l,m,a);
//         build(2*v+1,m+1,r,a);
//         combine(v);
//     }
// }
// void update(int v, int l,int r,int index, int val){
//     if(l>r) return;
//     if(l==r){
//         t[v].mnv+=val;
//     }else{
//         int m=(l+r)>>1;
//         if(index <= m) update(2*v,l,m,index,val);
//         else update(2*v+1,m+1,r,index,val);
//         combine(v);
//     }
// }
// int query(int v,int l, int r,int ql,int qr){
//     // show(l<<' '<<r<<' '<<ql<<' '<<qr)
//     if(ql>qr) return INT_MAX;
//     if(l==ql && r==qr){
//         return t[v].mnv;
//     }else{
//         int m=(l+r)>>1;
//         return min(query(2*v,l,m,ql,min(qr,m)),query(2*v+1,m+1,r,max(ql,m+1),qr));
//     }
// }
void solve(){
    int n,q;
    cin>>n>>q;
    vi divs;
    int x = n;
    for (int d = 2; d * d <= x; ++d) {
        if (x % d != 0)
            continue;
        while (x % d == 0)
            x /= d;
        divs.push_back(n / d);
    }
    if (x > 1) divs.push_back(n / x);
    int e,sum=0;
    vi a;
    fors(n){
        cin>>e;
        a.pb(e);
    }
    vi st;
    map<int,int> freq;
    for(auto x:divs){
        fors(x){
            sum=0;
            for(int j=i;j<n;j+=x){
                sum+=a[j];
            }
            st.pb(sum*x);
            freq[sum*x]++;
        }
    }
    int m=st.size();
    // build(1,0,m-1,st);
    show(freq.rbegin()->F)
    int ind,ir=0,offs;
    fors(q){
        cin>>ind>>e;
        ind--;
        sum=e-a[ind];
        a[ind]=e;
        // show(sum<<' '<<ind)
        ir=0;
        for(auto x:divs){
            offs=ind%x;
            // show(ir+offs<<' '<<x*sum)
            // update(1,0,m-1,ir+offs,x*sum);
            freq[st[ir+offs]]--;
            if(!freq[st[ir+offs]]){
                freq.erase(st[ir+offs]);
            }
            st[ir+offs]+=x*sum;
            freq[st[ir+offs]]++;
            ir+=x;
        }
        show(freq.rbegin()->F)
    }
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase = 1;
    cin>>testcase;
    while (testcase--){
        solve();
    }
    return 0;
}