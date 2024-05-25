#pragma gcc diagnostic "-std=c++1z"
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
using namespace std;
int n,m,T,k;
void test_case() {
     cin>>n>>m;
     int dp[max(n,m)+5]; dp[0]=1; dp[1]=1;
     for (int i=2; i<=max(n,m); i++) {
          dp[i]=dp[i-1]+dp[i-2]; dp[i]%=MOD;
     }
     cout<<(dp[m]*2-2+dp[n]*2+MOD)%MOD<<endl;
}
main () {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	T=1; 
	while (T--) test_case();
}
