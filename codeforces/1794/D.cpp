#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// // order_of_key(k) : no. of elements < k
// // *find_by_order(i) : value at index i (0-based)
#define int long long int
#define vi vector<int>
#define mi map<int,int>
#define si set<int>
#define mv map<int,vector<int>> 
const int mod=998244353;
const int N=1e6+3;
int prime[N];
void filll(){
    prime[0]=prime[1]=0;
    for(int i=2;i<N;i++){
        prime[i]=-1;
    }
    for(int i=2;i<N;i++){
        if(prime[i]==-1){
            prime[i]=1;
        }
        for(int j=i+i;j<N;j+=i){
            prime[j]=0;
        }
    }
}
int power(int a,int b){
    int ans=1;
    while(b>0){
        if(b&1){
            ans=ans*a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        b/=2;
    }   
    return ans%mod;
}
int modinv(int n){
    return power(n,mod-2);
}

int factorial[N];
int inv[N];
void fact(){
    factorial[0]=1;
    inv[0]=1;
    for(int i=1;i<N;i++){
        factorial[i]=factorial[i-1]*i;
        factorial[i]%=mod;
        inv[i]=modinv(factorial[i]);
        
    }
}
void solve(){
    int n;
    cin>>n;
    int a[2*n];
    mi m;
    for(int i=0;i<2*n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    vi primes,non;
    for(auto i:m){
        if(prime[i.first] && i.first>1){
            primes.push_back(i.first);
        }
        else{
            non.push_back(i.first);
        }
    }
    int ans=1;

    ans*=factorial[n];
    for(auto i:non){
        ans*=(inv[m[i]]);
        ans%=mod;
    }
    int sz=primes.size();
    if(sz<n){
        cout<<0<<endl;
        return;
    }
    int dp[sz+1][sz+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=sz;i++){
        dp[i][0]=dp[i-1][0]*(inv[m[primes[i-1]]]);
        dp[i][0]%=mod;
    }
    for(int i=1;i<=sz;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j]*(inv[m[primes[i-1]]]);
            dp[i][j]%=mod;
            dp[i][j]+=dp[i-1][j-1]*(inv[m[primes[i-1]]-1]);
            dp[i][j]%=mod;
        }
    }
    ans*=dp[sz][n];
    ans%=mod;
    cout<<ans<<endl;
}
int32_t main(){
ios::sync_with_stdio(0);
cin.tie(0);
int t;
t=1;
fact();
filll();
while(t--){
solve();
}
}