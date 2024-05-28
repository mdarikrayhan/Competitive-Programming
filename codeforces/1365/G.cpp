// LUOGU_RID: 159832963
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pr;
inline LL rd(){
	LL x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
LL n,m,po[2005],cn,g[14];vector<LL>vc;
int main(){
	cin>>n;
	for(LL i=0;i<(1<<13);++i){
		LL sm=0;
		for(LL j=0;j<13;++j)if(i>>j&1)++sm;
		if(sm==6)po[++cn]=i;if(cn==n)break;
	}
	for(LL i=0;i<13;++i){
		vc.clear();
		for(LL j=1;j<=n;++j)if(po[j]>>i&1)vc.push_back(j);
		if(vc.size()){
		cout<<"? "<<vc.size()<<" ";
		for(auto j:vc)cout<<j<<" ";cout<<endl;
		fflush(stdout);cin>>g[i];
		}
	}
	cout<<"! ";
	for(LL i=1;i<=n;++i){
		LL sm=0;
		for(LL j=0;j<13;++j)if(!(po[i]>>j&1))sm|=g[j];
		cout<<sm<<" ";
	}
	cout<<endl;fflush(stdout);
	return 0;
}