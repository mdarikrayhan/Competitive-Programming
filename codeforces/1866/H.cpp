#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pb push_back
#define in insert
//#define mid (l+r)/2
#define endl "\n"
//#define pop pop_back
using namespace std;
const int M=998244353;
const int N=2e5+5;
int fac[N],inv[N];
int f(int a , int b){
    int prod=1;
    while(b){
          if(b&1){
             prod*=a;
             prod%=M;
             b--;
          }
          a*=a;
          a%=M;
          b/=2;
    }
    return prod;
}
void init(){
     fac[0]=1;
     for(int i=1;i<N;i++) fac[i]=(fac[i-1]*i)%M;
     inv[N-1]=f(fac[N-1],M-2);
     for(int i=N-1;i>=1;i--) inv[i-1]=(inv[i]*i)%M;
     return ;
}
int C(int n , int r){
    if(r>n) return 0;
    int res=fac[n]*inv[r];
    res%=M;
    res*=inv[n-r];
    res%=M;
    return res;
}
int solve(int n , int k){
    if(k<n) return 0;
    int cnt=(f(n+1,k-n+1)-f(n,k-n+1)+M)%M;
    cnt*=fac[n];
    return cnt%M;
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int n,k;
    cin>>n>>k;
    int res=0;
    for(int i=0;i<=n;i++){
        int cur=C(n,i);
        cur*=solve(n-i,k);cur%=M;
        cur*=fac[n-i];
        res+=cur;
        res%=M;
    }
    cout<<res;
    return 0;
}
