// LUOGU_RID: 160596453
#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD1=998244353,MOD2=1000000007,K=1000000;
int n,ans,cur,s[9],pw[9];
vector<int>a[9];
void dfs1(int x,int y){
	if(x>6)
		return;
	a[x].push_back((cur-y+MOD1)%MOD1);
	s[x]=(s[x]+cur-y+MOD2)%MOD2;
	cur++;
	for(int i=0;i<10;i++)
		dfs1(x+1,y*10+i);
}
int dfs2(int x,int y){
	if(y>n)
		return 0;
	if(y*K+K-1<=n&&y*K*10>n){
		int res=0;
		for(int i=0;i<7;i++){
			int t=(cur-y%MOD1*pw[i]%MOD1+MOD1)%MOD1,
				tot=a[i].size(),
				cnt=tot-(lower_bound(a[i].begin(),
					a[i].end(),MOD1-t)-a[i].begin());
			res=(res+t*tot%MOD2+s[i]-MOD1*cnt%MOD2+MOD2)%MOD2;
		}
		cur+=1111111;
		return res;
	}
	int res=(cur-y%MOD1+MOD1)%MOD1;
	cur++;
	for(int i=!x;i<10;i++)
		res=(res+dfs2(x+1,y*10+i))%MOD2;
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=0;i<7;i++)
		pw[i]=i?pw[i-1]*10:1;
	cin>>n,dfs1(0,0);
	for(int i=0;i<7;i++)
		sort(a[i].begin(),a[i].end());
	cur=0,cout<<dfs2(0,0)<<"\n";
}