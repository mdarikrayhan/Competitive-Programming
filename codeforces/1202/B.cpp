#include "bits/stdc++.h"
#include <complex>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#ifndef ONLINE_JUDGE
#include "err.h"
#else
#define debug(...) 
#endif
using namespace __gnu_pbds; 
 
#define int long long
#define float long double
#define pb push_back
 
using namespace std;
int mod=1e9+7;
int pow1(int n,int k){
    if(k<=0)return 1;
    int c=n;
    int ans=1;
    while(k){
        if(k%2)ans*=c;
        ans%=mod;
        c*=c;
        c%=mod;
        k>>=1;
    }
    return ans;
}
 
int gcd(int a,int b){
    if(a<b){
        swap(a,b);
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int64_t a,int b){
    //if(a<b)swap(a,b);
    if(b==1)return a;
    int k=gcd(a,b);
    if(k==0){
        return 0;
    }
    int c=b/k;
    return (a*c)%mod;
}
int fact[400010]={};
// int p[10000010]={};
// int t1=0;
int ncr(int a,int b){
    if(a<=0)return 0;
    if(b<0)return 1;
    if(a<b)return 0;
    if(b==0)return 1;
    int ans=1;
    //cout<<fact[a]<<" "<<fact[b]<<" "<<fact[a-b]<<"\n";
    ans*=fact[a];
    ans%=mod;
    ans*=pow1(fact[b],mod-2);
    ans%=mod;
    ans*=pow1(fact[a-b],mod-2);
    ans%=mod;
    return ans;
}
int log_a_to_base_b(int a, int b)
{
    return (a > b - 1)
            ? 1 + log_a_to_base_b(a / b, b)
            : 0;
}



void solve(){
    string s;
    cin>>s;
    int dp[10][10][10][10];
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int u=0;u<10;u++){
                    if(k==0&&u==0)dp[i][j][k][u]=0;
                    else dp[i][j][k][u]=1e9;
                }
            }
        }
    }
    int cnt[10][10][11]={};
    memset(cnt,0x1,sizeof(cnt));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            set<int>pos;
            pos.insert(0);
            for(int k=0;k<20;k++){
                set<int>temp;
                for(int x:pos){
                    
                    cnt[i][j][(x+i)%10]=min(k+1,cnt[i][j][(x+i)%10]);
                    
                    temp.insert((x+i)%10);
                
                    cnt[i][j][(x+j)%10]=min(k+1, cnt[i][j][(x+j)%10]);
                    
                    temp.insert((x+j)%10);
                }
                pos=temp;
            }
            // cout<<i<<" "<<j<<" ";
            // for(int k=0;k<10;k++){
            //     cout<<cnt[i][j][k]<<" ";
            // }
            // cout<<"\n";
            
            
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int u=0;u<10;u++){
                    int t=(u-k+10)%10;
                    dp[i][j][k][u]=(cnt[i][j][t]-1); 
                }
            }

        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int ans=0;
            //cout<<i<<" "<<j<<" ";
            for(int k=1;k<s.size();k++){
                
                    ans+=dp[i][j][s[k-1]-'0'][s[k]-'0'];
                    //cout<<dp[i][j][s[k-1]-'0'][s[k]-'0']<<" ";
                
            }
            if(abs(ans)<1e9)cout<<ans<<" ";
            else cout<<"-1 ";
        }
        cout<<"\n";
    }
}   

 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    fact[0]=1;
    fact[1]=1;
    // for(int i=2;i<=200010;i++){
    //     fact[i]=(fact[i-1]*i)%mod;
    // }
    // for(int i=2;i<1e7+10;i++){
    //     if(p[i])continue;
    //     int j=i*i;
    //     while(j<1e7+10){
    //         p[j]=i;
    //         j+=i;
    //     }
    // }
    int T=1;
    //cin>>T;
    for(int _=0;_<T;_++){
       // cout<<"Case #"<<_+1<<": ";
        cout.precision(15);
        solve();
    }
    return 0;
}
 
 
 
    