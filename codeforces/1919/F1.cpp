#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi> 
#define pb push_back
#define fi first
#define se second
#define TII tuple<int, int, int>
#define ts to_string
#pragma gcc optimize("O3")
using namespace std;
const int N=5e5;
int tr[4*N], lazy[4*N], n;
void push(int pos) {
    tr[2*pos+1]+=lazy[pos];
    tr[2*pos+2]+=lazy[pos];
    lazy[2*pos+1]+=lazy[pos];
    lazy[2*pos+2]+=lazy[pos];
    lazy[pos]=0;
}
void update(int ll, int rr, int add, int pos=0, int l=0, int r=n-1) {
    if(ll>rr) return;
    if(ll==l && rr==r) {tr[pos]+=add; lazy[pos]+=add; return;}
    push(pos); int mid=l+r>>1;
    update(ll, min(rr, mid), add, 2*pos+1, l, mid);
    update(max(mid+1, ll), rr, add, 2*pos+2, mid+1, r);
    tr[pos]=min(tr[2*pos+1], tr[2*pos+2]);
}
int get(int idx, int pos=0, int l=0, int r=n-1) {
    if(idx<0) return 0;
    if(l==r) return tr[pos];
    push(pos); int mid=l+r>>1;
    if(idx<=mid) return get(idx, 2*pos+1, l, mid);
    return get(idx, 2*pos+2, mid+1, r);
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin >> n >> q;
    int sum=0; 
    vi a(n), b(n), c(n-1);
    for(int &p : a) cin >> p;
    for(int i=0; i<n; i++) {
        cin >> b[i]; sum+=b[i];
        update(i, n-1, a[i]-b[i]);
    }
    for(int &p : c) cin >> p;
    while(q--) {
        // cout << "_________" << endl;
        // for(int i=0; i<n; i++) cout << get(i)-get(i-1) << ' '; cout << endl;

        int p, x, y, z; cin >> p >> x >> y >> z; --p;
        sum+=y-b[p]; b[p]=y;
        update(p, n-1, x-y-get(p)+get(p-1));
        cout << sum+min(0ll, tr[0]) << '\n';

        // cout << sum << ' ' << tr[0] << endl;
        // for(int i=0; i<n; i++) cout << get(i)-get(i-1) << ' '; cout << endl;
    }
    return 0;
}