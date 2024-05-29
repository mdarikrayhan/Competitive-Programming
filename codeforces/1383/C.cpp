#include<bits/stdc++.h>
using namespace std;
int N,to[20],fa[20],dp[1<<20],ct[1<<20];char s[100005],t[100050];
int find(int r){return r==fa[r]?r:(fa[r]=find(fa[r]));}
void solve(){
	memset(to,0,sizeof(to));
	for(int i=0;i<20;++i)fa[i]=i;
	for(int i=0;i<(1<<20);++i)dp[i]=0;
	scanf("%d%s%s",&N,s+1,t+1);
	for(int i=1;i<=N;++i){
		int a=(int)(s[i]-'a'),b=(int)(t[i]-'a');
		fa[find(a)]=find(b),to[a]|=(1<<b);
	}
	int res=20,ans;
	for(int i=0;i<20;++i)if(i==find(i))--res;
	dp[0]=1,ans=res+20;
	for(int i=0;i<(1<<20);++i){
		if(!dp[i])continue;
		ans=min(ans,res+20-ct[i]);
		for(int j=0;j<20;++j)if(!((i>>j)&1)&&!(i&to[j]))dp[i|(1<<j)]=1;
	}printf("%d\n",ans);
}
int main(){
	for(int i=1;i<(1<<20);++i)ct[i]=ct[i>>1]+(i&1);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
