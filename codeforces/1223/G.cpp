#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m,pre[N],cnt[N],s[N*2],p1,p2; ll ans;
void ins(int z){
	p2=max(p2,min(p1,z)),p1=max(p1,z);
}
void chk(int x,int y){
	if(x>1&&y>1) ans=max(ans,1ll*x*y);
}
int main(){
	cin>>n;
	for(int i=1,x;i<=n;++i)	
		scanf("%d",&x),++cnt[x],m=max(m,x);
	for(int i=1;i<=m;++i) pre[i]=cnt[i]?i:pre[i-1];
	for(int i=m;i;--i) s[i]=s[i+1]+cnt[i];
	for(int y=2;y<=m;++y){
		ll sm=0; p1=p2=-1e9;
		for(int i=y;i<=m;i+=y) sm+=s[i];
		for(int i=m/y;~i;--i){
			int las=pre[min(m,y*i+y-1)];
			if(las>=y*i){
				ins(las%y);
				las=(cnt[las]==1?pre[las-1]:las);
				if(las>=y*i) ins(las%y);
			}
			chk(min((ll)(y*i+p1)/2,sm-i),y);
			chk(min((ll)(y*i+p2),sm-2*i),y);
			if(p1>=0&&s[y*i+p1]>=2) chk(min((ll)(y*i+p1),sm-2*i-1),y);
		}
	}
	cout<<ans;
	return 0;
}