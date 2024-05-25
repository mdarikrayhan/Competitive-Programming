#include<bits/stdc++.h>
#include <complex>
#define MOGA ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
typedef long double ld;
#define point complex<ld>
#define X real()
#define Y imag()
#define pi acos(-1)
const ll mod = 1e9 + 7, N = 1e5 + 5;
using namespace std;
point vec(point a, point b) {
    return point(b - a);
}
int cross(point a, point b) {
    return (b * conj(a)).Y;
}
int dot(point a, point b) {
    return (b * conj(a)).X;
}
int Gcd(int x,int y) {
    if (y % x == 0)
        return x;
    return Gcd(y % x, x);
}
ll add(ll x,ll y){
    return (x+y)%mod;
}
ll mul (ll x, ll y){
    return x*y%mod;
}
ll sub(ll x,ll y){
    return (x-y+mod)%mod;
}
ll fast( ll n,ll base){
    if(n==0)
        return 1;
    ll cur=fast(n/2,base);
    cur=mul(cur,cur);
    if(n%2)
        cur= mul(cur,base);
    return cur;
}
ll dp[20][1<<20];
vector<vector<int>>b;
ll n, t=1,m,k;
vector<bool>vis;
ll f_ans(int ix,int mask ,int pr,int pofi){

    ll& ans=dp[ix][mask];
    if(~ans)
        return ans;
    ans=0;
    for(auto i:b[ix]){
        if(mask&(1<<i)){
            if(i==pr&&i!=pofi)
                ans++;
            continue;
        }
        if(i>pr)
        ans+=f_ans(i,(mask|(1<<i)),pr,ix);
    }
    return ans;
}
void go() {
    std::memset(dp,-1,sizeof dp);
    cin>> n >> m ;
    b=vector<vector<int>>(n+1);
    vis=vector<bool>(n+1);
    for(int i=0,o,x;i<m;i++){
        cin>>x >> o;
        b[x].push_back(o);
        b[o].push_back(x);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i])
        ans+=f_ans(i,1<<i,i,i)/2;
    }
    cout << ans;
}
int main()
{
    MOGA
   // cin >> t;
    for (int i = 1;i <= t;i++)
    {
        go();
        cout << '\n';
    }
    return 0;
}