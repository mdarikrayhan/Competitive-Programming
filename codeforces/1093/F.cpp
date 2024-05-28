//   you're already the best
//             _
//   ^ ^      //
// >(O_O)<___//
//   \ __ __  \
//    \\ \\ \\\\
//
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200010,M=110,mod=998244353;

int n,k,len;
int a[N],l[N][M];
int f[N][M],s[N];

void solve(){
	cin>>n>>k>>len;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			if(a[i]==j||a[i]==-1) l[i][j]=l[i-1][j]+1;
			
	s[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++){
			if(a[i]!=j&&a[i]!=-1) continue;
			f[i][j]=s[i-1];
			if(l[i][j]>=len) f[i][j]=((s[i-1]-s[i-len]+f[i-len][j])%mod+mod)%mod;
			s[i]=(s[i]+f[i][j])%mod;
		}
		
	cout<<s[n]<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return (0-0);
}
