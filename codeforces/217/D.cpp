#include <bits/stdc++.h>
#define int long long
#define double long double
#define mid ((l+r)>>1)
using namespace std;
const int mod=1e9+7;
int ans=0,m;
int cntt[61],tp;
bitset<120> mv;
bitset<120> sft(bitset<120> bs,int pos){
	return (bs>>pos)|(bs<<(m-pos));
}
int cnt=0,maxv;
void dfs(int now,bitset<120> bs,int tot,int num){
	(ans+=tot)%=mod;
	cnt++;
	maxv=max(maxv,num);
	if(now==tp+1){
		return ;
	}
	for(int i=now;i<=tp;i++){
		if(!bs[i]){
			bitset<120> nw=bs;
			if(!nw[i]) nw[i]=1;
			if(!nw[m-i]) nw[m-i]=1;
			dfs(i+1,(nw|sft(bs,i)|sft(bs,m-i))&mv,tot*cntt[i]%mod,num+1);
		}
	}
}
bitset<120> ept;
signed main(){
	int n,t; cin>>n>>m>>t;
	tp=min(m,60ll);
	for(int i=1;i<=t;i++){
		int a; cin>>a;
		cntt[min(a%m,m-a%m)]++;
	}
	for(int i=0;i<m;i++) mv.set(i);
	dfs(1,ept,1,0);
	cout<<ans;
	return 0;
}