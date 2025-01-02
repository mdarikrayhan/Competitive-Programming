#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef unordered_map<string,ll> usl;
typedef unordered_map<ll,ll> uml;
typedef unordered_set<ll> ul;
#define FOR(a, b, c) for (ll a = b; a < c; ++a)
#define FORD(a, b, c) for (ll a = b; a >= c; --a)
#define FORSQ(a, b, c) for (ll a = b; a * a <= c; ++a)
#define FORC(a, b, c) for (char a = b; a <= c; ++a)
#define FOREACH(a, b) for (auto&(a) : (b))
#define SQR(x) ((ll)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
#define debug(x) cout<<#x<<' '<<x<<'\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define fsp(x) fixed<<setprecision(x)
#define nl cout<<"\n"
#define int long long
const string all = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string number = "0123456789";
const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string lower = "abcdefghijklmnopqrstuvwxyz";
const vector<pair<int,int>>adj={{1,0},{0,1},{-1,0},{0,-1}};
int mod=1e9+7;
int binpow(int num,int exp,int MOD=mod){
    if(exp==0)return 1;
    if(exp%2)
        return (num*binpow(num,exp-1,MOD))%MOD;
    else{
        int temp=binpow(num,exp/2,MOD);
        return temp*temp%MOD;}}
int inverse(int a,int MOD=mod){return binpow(a,MOD-2,MOD);}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/
    int t;
    cin>>t;
    TC(t){
        int n,q;
        cin>>n>>q;
        vl c(n);
        FOR(i,0,n)
            cin>>c[i];
        vl l(q),r(q);
        FOR(i,0,q)
            cin>>l[i]>>r[i];
        vl sum(n+1),cnt(n+1);
        sum[0]=0;
        cnt[0]=0;
        FOR(i,1,n+1)
        {
            sum[i]=sum[i-1]+c[i-1];
            cnt[i]=cnt[i-1]+(c[i-1]==1);
        }

        FOR(i,0,q)
        {
            int x=l[i],y=r[i];
            int total=sum[y]-sum[x-1];
            int min=(cnt[y]-cnt[x-1])*2+(y-x+1)-(cnt[y]-cnt[x-1]);
            if(min>total||x==y)
                no;
            else
                yes;
        }
        
    }
    return 0;
}