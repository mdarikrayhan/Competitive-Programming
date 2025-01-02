// LUOGU_RID: 159903257
#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=1e9+7;

int s[N],f[N],h[N],epl[N],epr[N],sum[N],ec[N],num[N];
vector<int> buk[N];

void llz(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>s[i],sum[s[i]]++;
	for(int i=1;i<=m;++i){
		cin>>f[i]>>h[i];
		if(h[i]>sum[f[i]])continue;
		buk[f[i]].push_back(i);
		int now=0;
		for(int j=1;j<=n;++j){
			if(s[j]==f[i])now++;
			if(now==h[i]){epl[i]=j,ec[j]=i;break;}
		}
		now=0;
		for(int j=n;j>=1;--j){
			if(s[j]==f[i])now++;
			if(now==h[i]){epr[i]=j;break;}
		}
	}
	auto cmp=[&](const int& a,const int& b){return h[a]<h[b];};
	for(int i=1;i<=n;++i)sort(buk[i].begin(),buk[i].end(),cmp);
	int mx=0;
	for(int i=0;i<=n;++i){
		int res=0;		
		if(i==0){
			for(int j=1;j<=n;++j){
				if(buk[j].size()>0)res++;
			}
		}
		else{
			res++;
			if(!ec[i])continue;
			if(buk[f[ec[i]]].size()>1){
				int id=0;
				if(buk[f[ec[i]]][id]==ec[i])id++;
				if(epr[buk[f[ec[i]]][id]]>i)res++;
			}
			for(int j=1;j<=n;++j){
				if(!buk[j].size())continue;
				if(j==f[ec[i]])continue;
				if(buk[j].size()==1){
					int id=buk[j][0];
					if(epl[id]<i||epr[id]>i)res++;
				}
				else{
					int id0=buk[j][0],id1=buk[j][1];
					if((epl[id0]<i&&epr[id1]>i)||(epl[id1]<i&&epr[id0]>i))res+=2;
					else if(epl[id0]<i||epr[id0]>i)res++;
				}
			}
		}
		num[i]=res;
		mx=max(mx,res);
	}
	int ans=0;
	for(int i=0;i<=n;++i){
		if(num[i]<mx)continue;
		int res=1;		
		if(i==0){
			for(int j=1;j<=n;++j)if(buk[j].size())res=1ll*res*buk[j].size()%MOD;
		}
		else{
			if(!ec[i])continue;
			if(buk[f[ec[i]]].size()>1){
				int t=0;
				for(auto v:buk[f[ec[i]]])if(v!=ec[i]&&epr[v]>i)t++;
				res=1ll*res*max(1,t)%MOD;
			}
			for(int j=1;j<=n;++j){
				if(!buk[j].size())continue;
				if(j==f[ec[i]])continue;
				if(buk[j].size()==1){
					int v=buk[j][0];
					int t=(epl[v]<i)+(epr[v]>i);
					res=1ll*res*max(t,1)%MOD;
				}
				else{
					int cnt1=0,cnt2=0;
					for(auto v:buk[j]){
						int t=(epl[v]<i)+(epr[v]>i);
						if(t==1)cnt1++;
						else if(t==2)cnt2++;
					}
					if(cnt1==0&&cnt2==0){}
					else if(cnt2==0)res=1ll*res*cnt1%MOD;
					else if(cnt1==0&&cnt2==1)res=2ll*res%MOD;
					else res=1ll*res*(1ll*cnt2*(cnt2-1)%MOD+1ll*cnt1*cnt2%MOD)%MOD;
				}
			}
		}
		ans=(ans+res)%MOD;
	}
	cout<<mx<<" "<<ans<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)llz();
	return 0;
} 
