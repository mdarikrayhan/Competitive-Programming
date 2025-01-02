// LUOGU_RID: 157315634
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
#define ld double
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int x[3003],y[3003];
bool flg[3003];
ld l[3003],r[3003];
bool ok[3003][3003];
const ld pi=acos(-1.0L),eps=1e-9;
signed main()
{
	int n=read(),R=read();
	for(int i=1; i<=n; ++i) x[i]=read(),y[i]=read();
	for(int i=1; i<=n; ++i)
	{
		int lim=0;
		vector<pair<ld,int>> v,q;
		for(int j=1; j<=n; ++j) if(i!=j)
		{
			int dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			ld mid=atan2(y[j]-y[i],x[j]-x[i]);
			q.push_back({mid,j});
			if(dis>R*R)
			{
				ld shift=asin(R/sqrt(dis));
				ld tl=mid-shift,tr=mid+shift;
				++lim,
				v.push_back({tl-eps,1}),
				v.push_back({tr+eps,-1});
				if(tr>pi) --lim,
					v.push_back({tr-pi*2+eps,-1});
				if(tl<-pi)
					v.push_back({tl+pi*2-eps,1});
			}
		}
		sort(q.begin(),q.end());
		sort(v.begin(),v.end());
		auto it=v.begin();
		for(auto [x,y]:q)
		{
			while(it!=v.end()&&it->first<=x)
				lim-=(it++)->second;
			if(!lim) ok[i][y]=1;
		}
	}
	int ans=0;
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
			if(ok[i][j]&&ok[j][i]) ++ans;
	printf("%lld\n",ans);
	return 0;
}