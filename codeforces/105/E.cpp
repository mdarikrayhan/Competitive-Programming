#include<bits/stdc++.h>
using namespace std;
int p[3],m[3],t[3],ans;
bitset<30000000>vis;
#define can(i) (i)!=p[0]&&(i)!=p[1]&&(i)!=p[2]
int hsh(int*p,short x,short y){return((((p[0]-1)*70+(p[1]-1))*70+(p[2]-1))<<6)|(x<<3)|y;}
void dfs(int*p,short x,short y){
	if(vis[hsh(p,x,y)])return;
	vis[hsh(p,x,y)]=1;
	int mx(0),mn(2e9);
	for(int i(0);i<3;++i)!(p[i]&64)&&p[i]>mx&&(mx=p[i]),p[i]<mn&&(mn=p[i]);
	mx>ans&&(ans=mx);
	for(int j(0);j<3;++j){
		int q[3]={p[0],p[1],p[2]},z(1<<j);
		if(p[j]&64){for(int T(p[j]^64),i(p[T]+t[T]);!(p[T]&64)&&i>=p[T]-t[T]&&i>mn-2&&i;--i)if(can(i))q[j]=i,dfs(q,x,y);}
		else if(can(j|64)){
			if(y&z)for(int i(0);i<3;++i)if(abs(p[i]-p[j])==1)q[i]=j|64,dfs(q,x,y^z),q[i]=p[i];
			if(x&z)for(int i(p[j]+m[j]);i>=p[j]-m[j]&&i>mn-2&&i;--i)if(can(i))q[j]=i,dfs(q,x^z,y);
		}
	}
}
int main(){
	//int T;cin>>T;
	//while(T--){
		for(int i(0);i<3;++i)cin>>p[i]>>m[i]>>t[i];
		vis=0,ans=0,dfs(p,7,7),cout<<ans<<'\n';
	//}
	return 0;
}