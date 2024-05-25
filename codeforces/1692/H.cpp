#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+5;
typedef pair<char,int> PII;
const int mod=1e9+7;
const int inf=1e9;
int dp[N],L[N];
void solve(){  
    int n;cin>>n;
    int a[n+1];
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(mp[a[i]]==0){
            L[i]=i;
            dp[i]=1;
        }else{
            int lst=mp[a[i]];
            if(dp[lst]+1-(i-lst-1)>1){
                dp[i]=dp[lst]+1-(i-lst-1);
                L[i]=L[lst];
            }else{
                dp[i]=1;
                L[i]=i;
            }
        }
        res=max(res,dp[i]);
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(dp[i]==res){
            cout<<a[i]<<" "<<L[i]<<" "<<i<<endl;
            return ;
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0^0;
} 