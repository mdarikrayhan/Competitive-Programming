#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define str string
#define mod (ll)1000000007
ll n,a[1000010],dp[200002],co[1000010];
str s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //if(fopen("a.inp","r")){
    //   freopen("a.inp","r",stdin);
    //   freopen("a.out","w",stdout);
    //}
    cin>>n;
    a[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ll t1=lower_bound(a+1,a+n+1,a[i]-90+1)-a-1;
        ll t2=lower_bound(a+1,a+n+1,a[i]-1440+1)-a-1;
        dp[i]=dp[i-1]+20;
        dp[i]=min(dp[i],dp[t1]+50);
        dp[i]=min(dp[t2]+120,dp[i]);
        cout<<dp[i]-dp[i-1]<<'\n';
    }
}