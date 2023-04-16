# include <bits/stdc++.h>
using namespace std;
int lst[200010],que[200010];
bool flag[200010],vis[200010];
vector<int> a[200010];
inline void chkmax(int &x,const int &y){x=max(x,y);}
int main()
{
	flag[0]=1;
	int T,n,m;
	cin>>T;
	while(T--)
	{
		int sz,t=0,l=0,r=0,ans=0;
		scanf("%d%d",&n,&m);
		que[r++]=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&sz);
			a[i].resize(sz);
			if(sz)
			{
				for(int &j:a[i])
				{
					scanf("%d",&j);
					flag[i]|=(l<r && que[l]<=lst[j]);
					while(l<r && que[l]<=lst[j]) l++;
					lst[j]=i;
				}
				flag[i]|=(l<r && t>=que[l]);
				if(flag[i]) que[r++]=i+1;
			}
			else t=i,flag[i]=1,que[r++]=i+1;
		}
		bool have0=0;
		for(int i=n,cnt=0;i;i--)
		{
			bool ok=1;
			for(int j:a[i])
				if(vis[j]) ok=0;
				else vis[j]=1,cnt++;
			if(!ok) break;
			have0|=a[i].empty();
			if(flag[i-1]) chkmax(ans,have0?m:cnt);
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			flag[i]=0;
			for(int j:a[i]) lst[j]=vis[j]=0;
			a[i].clear();
		}
	}
	return 0;
}