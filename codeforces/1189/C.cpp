#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define vll vector<ll>
#define vi vector<int>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
double pi = acos(-1);
#define int long long
template<typename T = int>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v) in >> x;
    return in;
}

template<typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    //cin.tie(0); cin.sync_with_stdio(0);
}

/*ll gcd(ll a, ll b)
{
    return(b == 0) ? a : gcd(b, a % b);
}*/
ll gcd(ll a, ll b)
{
    return(b == 0) ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b) * b);
}
ll getbit(ll n, ll i)
{
    return ((n >> i) & 1);
}
int mod = (ll)1e9+7;
ll inv(ll nn, ll xx = mod - 2)
{
    return !xx ? 1 : (inv(((nn % mod) * (nn % mod)) % mod, (xx >> 1)) % mod * ((xx & 1) ? (nn % mod) : 1) % mod) % mod;
}
int dx[8] = { 1,0,-1,0,1,-1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,-1,1};
struct node
{
    int x=0,s=0;
};
const int N=2e5+5;
node merg(node &l,node &r){
    return {(r.x+l.x)%10,((r.x+l.x)>=10)+r.s+l.s};
}
node st[300005][30];

int solve(int ttttc)
{
    int n;cin>>n;
    vi a(n);
    cin>>a;
    for(int i=0;i<n;i++){
        st[i][0].x=a[i];st[i][0].s=0;
    }
    for(int mask=1;(1LL<<mask)<=n;mask++){
        for(int i=0;i+(1ll<<mask)<=n;i++){
            st[i][mask]=merg(st[i][mask-1],st[i+(1ll<<(mask-1))][mask-1]);
        }
    }
    int m;cin>>m;
    while(m--){
        int l,r;cin>>l>>r;
        cout<<st[l-1][((int)log2(r-l+1))].s<<"\n";
    }
    return 0;
}
signed main()
{
    //memset(vs,-1,sizeof(vs));
    /*for(int i=0;i<n;i++)*/
    //freopen("street.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //memset(dp,-1,sizeof(dp));
    //memset(vs,-1,sizeof(vs));
    fast();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {

        //cout<<"Case #"<<ttttc<<": ";
        solve(tc);
        if (tc != T)
            cout << "\n"
                 ;

    }
    return 0;
}

	  					  			      	   	 		 	 	