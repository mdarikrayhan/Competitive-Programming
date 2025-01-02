// LUOGU_RID: 158354717
#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=1e6+10;
int a[N];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1) res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
void solve(){
	int n,k;
	scanf("%lld %lld",&n,&k);
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		int a1,a2,a3,a4;
		scanf("%lld.%lld.%lld.%lld",&a1,&a2,&a3,&a4);
		a[i]=(a1<<24)+(a2<<16)+(a3<<8)+a4;		
	}
	int ans=0;
	int cnt=0;
	for(int i=31;i>=1;i--){
		ans+=ksm(2,i);
		cnt=0;
		for(int j=1;j<=n;j++){
			if(!mp[ans&a[j]]){
				cnt++;
				mp[ans&a[j]]++;
			}
		}
		mp.clear();
		if(cnt==k){
			printf("%lld.%lld.%lld.%lld",ans>>24,(ans>>16)&255,(ans>>8)&255,ans&255);
			return;
		}
	}
	cout<<-1;
	return;
}
signed main(){
	int T=1;
	while(T--) solve();
	return 0;
}



