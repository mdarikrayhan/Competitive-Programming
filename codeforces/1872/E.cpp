// Omar Farhan
#define ll long long
#define isON(n, k) (((n) >> (k)) & 1)
#define sz(x) int(x.size())
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
template<class T> using  ordered_multiset= tree<pair<T, T>, null_type, less<pair<T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
constexpr int N=2e5+7,OO=0x3f3f3f3f,M=1e6+6,MOD=1e9+7;
constexpr ll LINF = 1LL << 62;
int dx[]={1,0, -1,0,1,1,-1,-1};
int dy[]={0,1, 0,-1,1,-1,1,-1};
template < typename T = int > using Pair = pair < T, T >;
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x: v) in >> x;
    return in;
}
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x<<' ';
    return out;
}
void burn() {
int n;cin>>n;
vector<int>a(n+1);
for(int i=1;i<=n;i++){
    cin>>a[i];
}
string s;cin>>s;
s='#'+s;
vector<int>pre_o(n+1),pre_z(n+1);
int cur=0;
for(int i=1;i<=n;i++){
    if(s[i]=='1'){
        pre_o[i]=a[i]^pre_o[i-1];
        pre_z[i]=pre_z[i-1];
    }
    else {
        pre_z[i]=a[i]^pre_z[i-1];
        pre_o[i]=pre_o[i-1];
    }
}
int q;cin>>q;
    while (q--){
        int op;cin>>op;
        if(op&1){
            int l,r;cin>>l>>r;
            cur^=(pre_z[r]^pre_z[l-1])^(pre_o[r]^pre_o[l-1]);
        }
        else {
            int g;cin >> g;
            if(g & 1){
                cout<<(pre_o[n]^cur);
            }
            else {
                cout<<(pre_z[n]^cur);
            }
            cout<<' ';
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;cin>>T;
    while (T--) {
        burn();
        cout << '\n';
    }
    return 0;
}