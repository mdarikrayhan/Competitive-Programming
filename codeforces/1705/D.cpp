#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s,t;
void solve(){
	ans=0;
	cin>>n>>s>>t;
	for(long long sp=0,tp=0;sp<=n&&tp<=n;sp++,tp++){
		if(s[sp]!=t[tp]){
			printf("-1\n");
			return;
		}
		ans+=abs(sp-tp);
		while(s[sp+1]==t[tp]) sp++;
        while(s[sp]==t[tp+1]) tp++;
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	long long t;
	scanf("%lld",&t);
	while(t--){
		solve();
	}
	return 0;
}