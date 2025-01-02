#include <bits/stdc++.h>
using namespace std;
int n;
int x[200005] ,y[200005] ,s[200005];
long long dp[200005] ,sum[200005] ,ans;
long long mod=998244353;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i] >> s[i];
        int nxt=lower_bound(x+1 ,x+i+1 ,y[i])-x;
        dp[i]=((x[i]-y[i])+sum[i-1]-sum[nxt-1]+mod)%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
        if(s[i])
            ans=(ans+dp[i])%mod;
    }
    cout << (ans+x[n]+1)%mod << endl;
}
	   		   	  	  		 				  	 	 			