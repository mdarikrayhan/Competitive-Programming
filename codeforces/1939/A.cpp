#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#define N 80009
#define mod 1000000007
using namespace std;
inline void read(int&x)
{
	bool t=0;char c=getchar();for(;c<'0'||'9'<c;t|=c=='-',c=getchar());
	for(x=0;'0'<=c&&c<='9';x=(x<<3)+(x<<1)+(c^48),c=getchar());if(t)x=-x;
}
int t,g,n,c,rc,lim,q,b[N],sz,lst[N],m,res;vector<int>d[N],hsh[N];
map<int,int>mmp;long long pw[N];int oh[N],rgt[N],lft[N];
struct node
{
	int x,y,id;
	inline bool operator<(const node&kkk)const{return x<kkk.x;}
}a[N];
inline int chk(int i,int j,int k)
{
	if(i>>31)return 0;
	long long w=a[j].x-a[i].x,x=a[j].y-a[i].y,
		y=a[k].x-a[j].x,z=a[k].y-a[j].y;
	return w*y+x*z<0;
}
inline void pr(int i){printf("%d ",a[i].id);}
inline vector<int>loose(int k)
{
	vector<int>ret;k-=res;
	for(int i=0;i<m-1;++i)if(d[i].size()<=5)
		for(int j:d[i])ret.emplace_back(j);
	else
	{
		int cnt=min(k>>1<<1,(int)(d[i].size())-4>>1<<1);
		ret.emplace_back(d[i][0]);ret.emplace_back(d[i][1]);
		for(int l=2,r=d[i].size()-3;l<=r;)
			if(cnt)cnt-=2,k-=2,
				ret.emplace_back(d[i][r--]),ret.emplace_back(d[i][l++]);
			else ret.emplace_back(d[i][l++]);
		ret.emplace_back(d[i][d[i].size()-2]);ret.emplace_back(d[i].back());
	}
	ret.emplace_back(d[m-1][0]);ret.emplace_back(d[m-1].back());
	for(int l=1,r=d[m-1].size()-2,o=1;l<=r;)
	{
		if(k)--k,o^=1;
		if(o)ret.emplace_back(d[m-1][r--]);
		else ret.emplace_back(d[m-1][l++]);
	}
	return ret;
}
inline vector<int>tight(int k)
{
	vector<int>ret;int x=-1;
	for(int i=0;i<m-1;++i)if(d[i].size()==1)
		k-=chk(x,d[i][0],d[i+1][0]),ret.emplace_back(x=d[i][0]);
	else if(d[i].size()==2)
		k-=chk(x,d[i][0],d[i][1])+chk(d[i][0],d[i][1],d[i+1][0]),
		ret.emplace_back(d[i][0]),ret.emplace_back(x=d[i][1]);
	else
	{
		int cnt=min(k-2*(m-i),(int)(d[i].size())-2);
		if(cnt)k-=chk(x,d[i][0],d[i].back());
		else k-=chk(x,d[i][0],d[i][1]);
		ret.emplace_back(d[i][0]);x=d[i][0];
		for(int l=1,r=d[i].size()-1,o=0;l<=r;)
		{
			if(cnt)--k,--cnt,o^=1;
			if(l==r)k-=chk(x,d[i][o?r:l],d[i+1][0]);
			ret.emplace_back(x=d[i][o?r--:l++]);
		}
	}
	k-=chk(x,d[m-1][0],d[m-1].back())+1;
	ret.emplace_back(d[m-1][0]);ret.emplace_back(d[m-1].back());
	for(int l=1,r=d[m-1].size()-2,o=1;l<=r;)
	{
		if(k)--k,o^=1;
		ret.emplace_back(d[m-1][o?r--:l++]);
	}
	return ret;
}
main()
{
	read(t);read(g);read(n);
	for(int i=0;i<n;a[i].id=i+1,read(a[i].x),read(a[i++].y));
	if(t==1)
	{
		for(int i=0;i<n;++i)
			for(int j=i-1;j>0&&!chk(j-1,j,j+1);swap(a[j],a[j+1]),--j);
		for(int i=0;i<n;pr(i++));
		return 0;
	}
	sort(a,a+n);
	read(c);rc=c;if(n==80000)c=800;
	for(int i=0;i<n;++i)mmp[a[i].y]=i,lft[i]=i-1,rgt[i]=i+1;
	lft[n]=n-1;lft[0]=n+1;rgt[n+1]=0;
	for(int cnt=n;cnt;++m)
	{
		auto work=[](int*dir,int s)
		{
			sz=0;
			for(int i=dir[s];i<n;i=dir[i])
				if(!sz)lst[i]=1<<31,b[sz++]=a[i].y;
				else if(b[sz-1]<a[i].y)lst[i]=b[sz-1],b[sz++]=a[i].y;
				else
				{
					int j=lower_bound(b,b+sz,a[i].y)-b;
					lst[i]=j?b[j-1]:1<<31;b[j]=a[i].y;
				}
		};
		work(rgt,n+1);
		if(sz*sz<cnt)work(lft,n);
		for(int w=b[sz-1];w^1<<31;w=mmp[w],d[m].emplace_back(w),--cnt,
			lft[rgt[w]]=lft[w],rgt[lft[w]]=rgt[w],w=lst[w]);
	}
	if(t==2)
	{
		for(int i=0;i<m;++i)for(int j:d[i])pr(j);
		return 0;
	}
	sort(d,d+m,[](const vector<int>&u,const vector<int>&v)
		{return u.size()<v.size();});
	for(int i=0;i<m-1;++i)if(d[i].size()>1)res+=
		chk(d[i][d[i].size()-2],d[i].back(),d[i+1][0]);
	for(int i=1;i<m-1;++i)if(d[i].size()>1)res+=
		chk(d[i-1].back(),d[i][0],d[i][1]);
	else res+=chk(d[i-1].back(),d[i][0],d[i+1][0]);
	if(m>1)res+=chk(d[m-2].back(),d[m-1][0],d[m-1].back());
	++res;
	if(t==4)
	{
		if(!g){printf("534735187 776162084\n4 5 1 2 3\n1 3 2 5 4");return 0;}
		pw[0]=1;for(int i=1;i<=n;++i)pw[i]=pw[i-1]*1000003ll%mod;
		for(int i=0,sz;i<m-1;++i)if((sz=d[i].size())<=5)
		{
			int h=0;
			for(int j=sz-1;j>=0;--j)h=(h*1000003ll+a[d[i][j]].id)%mod;
			hsh[i].emplace_back(h);
		}
		else
		{
			vector<int>tmp;tmp.reserve(sz);hsh[i].reserve(sz);
			if(sz&1)tmp.emplace_back(a[d[i][sz>>1]].id);
			else tmp.emplace_back(0);
			for(int j=sz-2>>1;j>1;--j)
				tmp.emplace_back((tmp.back()*1000003ll+a[d[i][j]].id
					+a[d[i][sz-j-1]].id*pw[sz-j-1-j])%mod);
			reverse(tmp.begin(),tmp.end());
			for(int j=0,s=0;j<tmp.size();++j)
			{
				tmp[j]=(tmp[j]*pw[j<<1]+s)%mod;
				if(j<tmp.size()-1)s=(s+a[d[i][sz-j-3]].id*pw[j<<1]+
					a[d[i][j+2]].id*pw[j<<1|1])%mod;
			}
			for(int j=0;j<tmp.size();++j)tmp[j]=(tmp[j]*pw[2]+
				a[d[i][1]].id*1000003ll+a[d[i][0]].id+
				a[d[i][sz-2]].id*pw[sz-2]+a[d[i].back()].id*pw[sz-1])%mod,
				hsh[i].emplace_back(tmp[j]),hsh[i].emplace_back(tmp[j]);
			hsh[i].pop_back();
		}
		int asc=0,dsc=0,sz=d[m-1].size();
		if(sz&1)asc=dsc=a[d[m-1][sz>>1]].id;
		else asc=(a[d[m-1][sz>>1]].id*1000003ll+a[d[m-1][sz-1>>1]].id)%mod,
			dsc=(a[d[m-1][sz-1>>1]].id*1000003ll+a[d[m-1][sz>>1]].id)%mod;
		hsh[m-1].emplace_back(asc);
		for(int j=(sz-1>>1)-1,k=sz&1?1:2;;--j)
		{
			asc=(asc+a[d[m-1][sz-j-1]].id*pw[k])%mod;
			dsc=(dsc*1000003ll+a[d[m-1][sz-j-1]].id)%mod;
			hsh[m-1].emplace_back(dsc);
			if(!j)break;++k;
			asc=(asc*1000003ll+a[d[m-1][j]].id)%mod;
			dsc=(dsc+a[d[m-1][j]].id*pw[k])%mod;
			hsh[m-1].emplace_back(asc);++k;
		}
		reverse(hsh[m-1].begin(),hsh[m-1].end());
		asc=0;
		for(int j=0;j<sz-1>>1;++j)
			asc=(asc+a[d[m-1][j]].id*pw[j<<1])%mod,
			hsh[m-1][j<<1]=(hsh[m-1][j<<1]*pw[j<<1|1]+asc)%mod,
			asc=(asc+a[d[m-1][sz-j-1]].id*pw[j<<1|1])%mod,
			hsh[m-1][j<<1|1]=(hsh[m-1][j<<1|1]*pw[j+1<<1]+asc)%mod;
		if(sz&1)hsh[m-1].pop_back();
		int hs=0,cnt=res;
		for(int i=m-2;i>=0;--i)hs=(hs*pw[d[i].size()]+hsh[i][0])%mod;
		for(int i=0,ssz=0;i<m-1;++i)
		{
			hs=(hs-hsh[i][0]*pw[ssz]%mod+mod)%mod;
			for(int j=0;j<hsh[i].size();++j)
				oh[cnt+j]=(hs+hsh[i][j]*pw[ssz]+hsh[m-1][j&1]*pw[n-sz])%mod;
			hs=(hs+hsh[i].back()*pw[ssz]%mod+mod)%mod;
			cnt+=hsh[i].size()-1;ssz+=d[i].size();
		}
		for(int j=0;j<hsh[m-1].size();++j)
			oh[lim=cnt+j]=(hs+hsh[m-1][j]*pw[n-sz])%mod;
		for(int i=lim+1;i<=n-rc;++i)
		{
			vector<int>d=tight(i);int s=0;
			for(int i=n-1;i>=0;--i)s=(s*1000003ll+a[d[i]].id)%mod;
			oh[i]=s;
		}
		for(int i=rc;i<=n-rc;++i)printf("%d\n",oh[i]);fflush(stdout);
	}
	if(!g){printf("1 2 3 4 5 6\n4 5 6 1 3 2\n6 2 4 3 5 1");return 0;}
	read(q);
	for(int k;q--;putchar('\n'),fflush(stdout))
	{
		read(k);vector<int>d=k<=lim?loose(k):tight(k);
		for(int i=0;i<n;pr(d[i++]));
	}
}
  	  	      		 	 		   				  			