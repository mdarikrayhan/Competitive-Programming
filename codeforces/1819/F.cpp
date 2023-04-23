#include<cstdio>
#include<iostream>
#include<map>
#include<utility>
using namespace std;
#define fi first
#define se second
const long long inf=2e18;
int n,q;pair<long long,long long> ans;char s[99];
struct info{
	int cnt;pair<long long,long long> v[6],ans;
	inline void calc(info*a,bool flg){
		cnt=0;
		for(int i=0;i<4;cnt+=a[i++].cnt){
			v[i].fi=inf;v[i].se=-inf;
			v[i].fi=min(v[i].fi,a[i].v[(i+3)&3].fi+a[(i+3)&3].v[4^(i&1)].fi+a[(i+2)&3].v[5^(i&1)].fi+a[(i+1)&3].v[(i+1)&3].fi+3);
			v[i].se=max(v[i].se,a[i].v[(i+3)&3].se+a[(i+3)&3].v[4^(i&1)].se+a[(i+2)&3].v[5^(i&1)].se+a[(i+1)&3].v[(i+1)&3].se+3);
			if(!a[(i+2)&3].cnt&&!a[(i+3)&3].cnt)
				v[i].fi=min(v[i].fi,a[i].v[i].fi+a[(i+1)&3].v[i].fi+1),v[i].se=max(v[i].se,a[i].v[i].se+a[(i+1)&3].v[i].se+1);
		}
		for(int i=4,t1=0,t2=0;i<6;++i){
			v[i].fi=inf;v[i].se=-inf;
			for(int j=(i^1)-2;j>=0;j-=2) if(!a[j].cnt){
				if(i==4&&j==1) t1=3,t2=2;
				if(i==4&&j==3) t1=0,t2=1;
				if(i==5&&j==0) t1=1,t2=2;
				if(i==5&&j==2) t1=0,t2=3;
				v[i].fi=min(v[i].fi,a[i-4].v[t1].fi+a[j^2].v[i].fi+a[i-2].v[t2].fi+2);
				v[i].se=max(v[i].se,a[i-4].v[t1].se+a[j^2].v[i].se+a[i-2].v[t2].se+2);
			}
		}
		ans.fi=inf;ans.se=-inf;
		ans.fi=min(ans.fi,a[0].v[5].fi+a[1].v[4].fi+a[2].v[5].fi+a[3].v[4].fi+4);
		ans.se=max(ans.se,a[0].v[5].se+a[1].v[4].se+a[2].v[5].se+a[3].v[4].se+4);
		for(int i=0;i<4;++i) if(a[0].cnt+a[1].cnt+a[2].cnt+a[3].cnt==a[i].cnt)
			ans.fi=min(ans.fi,a[i].ans.fi),ans.se=max(ans.se,a[i].ans.se);
		if(flg) for(int i=0;i<4;++i) if(!a[i].cnt&&!a[(i+1)&3].cnt) ans.fi=min(ans.fi,2ll),ans.se=max(ans.se,2ll);
	}
}f[21],tmp[4],New;
map<pair<int,int>,info> mp[21];
inline info Mp(int i,int x,int y){
	if(mp[i].find(make_pair(x,y))==mp[i].end()) return f[i];
	return mp[i][make_pair(x,y)];
}
int main(){
	scanf("%d%d",&n,&q);
	f[0].cnt=0;f[0].ans=make_pair(inf,-inf);
	for(int i=0;i<6;++i) f[0].v[i]=make_pair(0,0);
	for(int i=1;i<=n;++i) tmp[0]=tmp[1]=tmp[2]=tmp[3]=f[i-1],f[i].calc(tmp,i==1);
	for(int x,y;q--;){
		scanf("%s",s);x=y=0;
		for(int i=0;i<n;++i) x|=(s[i]=='c'||s[i]=='d')<<(n-i-1),y|=(s[i]=='b'||s[i]=='c')<<(n-i-1);
		if(mp[0].find(make_pair(x,y))==mp[0].end()) mp[0][make_pair(x,y)]=f[0];
		New=mp[0][make_pair(x,y)];New.cnt^=1;mp[0][make_pair(x,y)]=New;
		for(int i=1;i<=n;++i){
			if((x>>(i-1))&1) x^=1<<(i-1);
			if((y>>(i-1))&1) y^=1<<(i-1);
			tmp[0]=Mp(i-1,x,y);tmp[1]=Mp(i-1,x,y+(1<<(i-1)));
			tmp[2]=Mp(i-1,x+(1<<(i-1)),y+(1<<(i-1)));tmp[3]=Mp(i-1,x+(1<<(i-1)),y);
			New.calc(tmp,i==1);
			mp[i][make_pair(x,y)]=New;
		}
		ans=mp[n][make_pair(0,0)].ans;
		if(ans.fi<inf) printf("%lld %lld\n",ans.fi,ans.se);
		else printf("-1\n");
	}
	return 0;
}