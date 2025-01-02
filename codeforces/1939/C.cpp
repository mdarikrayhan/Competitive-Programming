#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N=3e5+5;
const int LG=49;
const ll INF=LLONG_MAX/2;

int n,m;
ll k,t;
ll a[N],b[N],cnt[N];
ll dp[LG][N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k >> t;
    for(int i=0;i<n;i++)cin >> a[i],b[i]=a[i];
    sort(b,b+n);
    m=unique(b,b+n)-b;
    if(t>=m)cout << 1,exit(0);
    for(int i=0;i<n;i++)a[i]=lower_bound(b,b+m,a[i])-b;
    for(int l=0,r=0,uniq=0;l<n;l++){
        while(uniq<=t)if(++cnt[a[r++%n]]==1)uniq++;
        dp[0][l]=r-l-1;
        if(--cnt[a[l]]==0)uniq--;
    }
    for(int i=1;i<LG;i++)for(int j=0;j<n;j++){
        ll p=dp[i-1][j];
        dp[i][j]=min(p+dp[i-1][(j+p)%n],INF);
    }
    k*=n;
    int c=0;
    ll ans=0;
    for(int i=LG-1;i>=0;i--){
        ll p=dp[i][c];
        if(k<=p)continue;
        k-=p;
        ans|=1LL<<i;
        c=(c+p)%n;
    }
    cout << ans+1;
}