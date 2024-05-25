#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define nl "\n"
#define gcd __gcd
#define bin(x) __builtin_popcountll(x)
#define read(v, n)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define in insert
#define con continue
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int ll
#define vi std::vector<int>
#define vpi vector<pair<int, int>>
#define pii pair<int,int>

int mod = 1e9 + 7;
int m1 = 998244353;
ll max1(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll min1(ll a, ll b)
{
    if (a > b)
        return b;
    return a;
}
bool eq(string &a,string &b,vector<int> &v){
    for(int i=0;i<v.size();i++)if(a[v[i]-1]!=b[v[i]-1]){return 0;}
        return 1;
}
ll inv(ll a,ll b){
    if(gcd(a,b)!=1)return -1;
    return a<=1?a:b-(b/a)*inv(b%a,b)%b;
}
ll modpow(ll x, ll n, ll m)
{
    if (n == 0)
        return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2)
        u = (u * x) % m;
    return u;
}


int n;
int a[5005];
int dp[5005][4];
ll rec(int ver,int del){
    if(dp[ver][del]!=-1)return dp[ver][del];
    if(ver==n)return dp[ver][del]=0;
    if(del==0){
        ll ans=rec(ver+1,del)+a[ver];
        ans=max1(rec(ver+1,1)-a[ver],ans);
        return dp[ver][del]=ans;
       }
     if(del==1){
        ll ans=rec(ver+1,del)-a[ver];
        ans=max1(rec(ver+1,2)+a[ver],ans);
        return dp[ver][del]=ans;

     }  
     if(del==2){
       
        ll ans=rec(ver+1,del)+a[ver];
        ans=max1(rec(ver+1,3)-a[ver],ans);
        return dp[ver][del]=ans;
       
     }
     else return dp[ver][del]=rec(ver+1,3)-a[ver];
}

void print(){
    int del=0;
    for(int i=0;i<n;i++){
        int ver=i;
        if(del==3)return;
        if(del==0){
            if(rec(ver+1,del)+a[ver]<=rec(ver+1,1)-a[ver]){cout<<ver<<" ";del++;}
        }
        else if(del==1){
            if(rec(ver+1,del)-a[ver]<=rec(ver+1,2)+a[ver]){cout<<ver<<" ";del++;}

        }
        else{
            if(rec(ver+1,del)+a[ver]<=rec(ver+1,3)-a[ver]){cout<<ver<<" ";del++;}
        }
    }
    while(del<3){del++;cout<<n<<" ";}
    return ;
}

int32_t main()
{
    int t = 1;
    // cin >> t;
    
    while (t--)
    {
        memset(dp,-1,sizeof(dp));
cin>>n;
read(a,n);
int l=rec(0,0);

print();



    }
    return 0;
}