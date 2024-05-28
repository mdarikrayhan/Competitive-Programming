#include<bits/stdc++.h>
using namespace std;
const long long inf=2e9;
const int val=2e3+5;
char ar[3000][3000];
long long dp[3000][3000];
void solve  (){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ar[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=m;j++){
            cnt+=(ar[i][j-1]=='1');
            dp[i][j]+=cnt;
            dp[i][j]+=dp[i-1][j]+(ar[i][j]=='1');
        }
    }
    long long ans=0,mn=inf,x1,y1,x2,y2,cnt;
    for(int x=2;x<=2500;x++){
        for(int i=x;i<=x-n%x+n;i+=x){
            for(int j=x;j<=x-m%x+m;j+=x){
                x1=min(i,n);
                 y1=min(j,m);
                x2=i-x;
                y2=j-x;
                cnt=dp[x1][y1]-dp[x2][y1]-dp[x1][y2]+dp[x2][y2];
                ans+=min(cnt,x*x-cnt);
            }
        }
        mn=min(mn,ans);
        ans=0;
    }
    cout<< mn;
}       
int main (){ 

    ios::sync_with_stdio(0);
    
    
    //cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve ();
    }
}