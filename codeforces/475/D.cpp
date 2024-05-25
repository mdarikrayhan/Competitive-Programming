#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define forn(i,a, n) for(long long i = a; i<(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vec(n)  vector <ll>a(n);
#define endl "\n"
#define sz size()
const long double PI = 3.14159265358979323846;
int dx[] = { +0, +0, -1, +1, +1, +1, -1, -1 };
int dy[] = { -1, +1, +0, +0, +1, -1, +1, -1 };

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
//998244353
#define isON(mask,i) ((((mask)>>i))&1)
// (__builtin_popcount(mask)
#define ispow2(n) (!(n&(n-1)))
#define lpr pair<long long ,long long >
#define sec second
#define fi first
#define ll long long
using vl = vector<ll>;
using pl = pair<ll, ll>;
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define no cout << "NO\n"
#define yes cout << "YES\n"
//log10(n) + 1 = size n
const int INV_2 =5e8+4;
const ll OOL =0x3f3f3f3f3f3f3f3fLL;
const int OOI = 0x3f3f3f3f;
#define EPS 1e-7
const ll Mod = 998244353;
bool compd(long double A, long double B){ long double diff = A - B; return (diff < EPS) && (-diff < EPS);}

ll mul (ll a , ll b,ll mod){
    return (((a %mod + mod) * (b%mod+mod)) %mod);
}

ll bpow(ll n, ll x) { return x <= 0 ? 1 : bpow(n * n, x / 2)  * (x % 2 ? n : 1) ; }
ll binpow(ll base,ll exp,ll mod){ll res=1;while(exp>0){if(exp & 1)res=mul(res,base,mod);base= mul(base,base,mod);exp>>=1;}return res;}
ll binpow(ll base,ll exp){ll res=1;while(exp>0){if(exp & 1)res=res*base;base= base*base;exp>>=1;}return res;}
ll inv(ll a,ll mod){
    return binpow(a,mod-2,mod);
}
const int LOG = 20;
const ll mod=1e9+7;
const int N = 2e5+9;
typedef long double ld;

int sparse[N][LOG];
void buildSparse(vector <int>&v){

    for (int k = 0; k < LOG; ++k){
        for (int i =0; i+(1<<(k))-1 < (int)v.sz; ++i){
            if (k==0)
                sparse[i][k] = v[i];
            else
                sparse[i][k] = gcd(sparse[i][k-1],sparse[i+(1<<(k-1))][k-1]);
        }
    }
}

int query(int l, int r){

    if (r<l)swap(l,r);
    int len =(r-l+1);
    int k = 31-(__builtin_clz(len));
    return gcd(sparse[l][k],sparse[r-(1<<k)+1][k]);
}

void solve(){


    int n,q; cin >>n;
    vector<int>v(n);
    forn (i,0,n)cin >> v[i];
    map<int,ll>freq;
    buildSparse(v);


    for (int i =0; i < n; ++i) {
        int endpoint = i-1;
        int curGcd = v[i];
        do {
            endpoint++;
            int l = endpoint,r = n-1;
            curGcd = gcd(curGcd,v[endpoint]);
            while (l<=r){
                int mid = (l+r)/2;

                int gc = query(i,mid);
                if (gc==curGcd){
                    l = mid+1;
                }
                else r = mid-1;
            }

            freq[curGcd] +=(l-endpoint);
            endpoint = l-1;
        }while (endpoint!=n-1);
    }

    cin >> q;
    for (int i =0; i < q; ++i){
        int x; cin >> x;
        cout << freq[x]<<endl;
    }




}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //  build();
    // cin >> t;

    int cnt = 1;
    while (t--) {
        //  cout <<"Case #"<<cnt++<<" :"<<" ";
        solve();
        cout << endl;
    }

}

