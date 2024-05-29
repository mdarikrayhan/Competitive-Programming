// LUOGU_RID: 159835368
/*本代码含有小众情感元素，请于 114514 岁以上，1919810 岁以下时观看

/se/se/se/se/se/se/se/se/se/se/se/se/se/se/se
/kk/kk/kk/kk/kk/kk/kk/kk/kk/kk/kk/kk/kk/kk/kk
/qd/qd/qd/qd/qd/qd/qd/qd/qd/qd/qd/qd/qd/qd/qd

《CE:从爆 0 开始的OI生活》
《青春 OIer 不会梦到唐氏状压+ds+卡常》
《为美好的概率期望献上生成函数》

play genshin impact!!!play genshin impact!!!play genshin impact!!!play genshin impact!!!play genshin impact!!!play genshin impact!!!play genshin impact!!!play genshin impact!!!play genshin impact!!!play genshin impact!!!play genshin impact!!!play genshin impact!!!play genshin impact!!!

What should I do???What should I do???What should I do???What should I do???What should I do???What should I do???What should I do???What should I do???What should I do???What should I do???What should I do???What should I do???What should I do???What should I do???What should I do???

What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???What can I say???

Never gonna give you up!
Never gonna let you down!
Never gonna run around and desert you!
Never gonna make you cry!
Never gonna say good bye!
Never gonna tell a lie and hurt you!
*/
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
bool f[4][4][4]={{{0,0,0,0},{0,1,1,1},{0,1,1,1},{0,1,1,1}},{{0,0,0,0},{1,1,1,1},{1,1,1,1},{1,1,1,1}},{{0,0,0,0},{1,1,1,1},{1,1,1,1},{1,1,1,1}},{{0,0,0,0},{1,1,1,1},{1,1,1,1},{1,1,1,1}}};
ull id[4][4][4]={{{0,0,0,0},{0,1,2,3},{0,4,5,6},{0,7,8,9}},{{0,0,0,0},{1,10,11,12},{4,13,14,15},{7,16,17,18}},{{0,0,0,0},{2,11,19,20},{5,14,21,22},{8,17,23,24}},{{0,0,0,0},{3,12,20,25},{6,15,22,26},{9,18,24,27}}};
int base=28;
//unordered_map<ull,double> dp;
ull val[6000005];
double dp[6000005];
int nxt[6000005];
int head[5000005];
int a[25][4];
int n;
int cnt,fl;
int bb=5e6;
int get(ull x)
{
	fl=1;
	int p=x%bb;
	for(int i=head[p];i;i=nxt[i])
		if(val[i]==x)
			return i;
	fl=0;
	++cnt;
	nxt[cnt]=head[p];
	head[p]=cnt;
	val[cnt]=x;
	return cnt;
}
const int inf=0x3f3f3f3f;
ull v[1145];
ull get_hash()
{
	int c=0;
	for(int i=1;i<n;i++)
		if(f[a[i][1]][a[i][2]][a[i][3]])
			v[++c]=id[a[i][1]][a[i][2]][a[i][3]];
	sort(v+1,v+c+1);
//	v.push_back(id[a[n][1]][a[n][2]][a[n][3]]) 
	ull s=0;
	for(int i=1;i<=c;i++)
		s=s*base+v[i];
	if(a[n][1]<=a[n][3])
		s=s*(1<<6)+a[n][1]*(1<<4)+a[n][2]*(1<<2)+a[n][3];
	else
		s=s*(1<<6)+a[n][3]*(1<<4)+a[n][2]*(1<<2)+a[n][1];
	return s;
}
double dfs(ull x)
{
	int pos=get(x);
	if(fl)
		return dp[pos];
//	if(dp.count(x))
//		return dp[x];
	double p=0;
	double ans=1;
	for(int i=1;i<=3;i++)
	{
		double minn=inf;
		for(int j=1;j<n;j++)
		{
			bool full=(a[n][1]&&a[n][2]&&a[n][3]);
			if(full)
				n++;
			for(int k=1;k<=3;k++)
			{
				if(a[j][k]!=i)
					continue;
				if(k==2&&!(a[j][1]&&a[j][3]))
					continue;
				if((k==1||k==3)&&!a[j][2])
					continue;
				a[j][k]=0;
				for(int l=1;l<=3;l++)
				{
					if(a[n][l])
						continue;
					a[n][l]=i;
					minn=min(minn,dfs(get_hash()));
					a[n][l]=0;
				}
				a[j][k]=i;
			}
			if(full)
				n--;
		}
		if(minn>=inf-1)
			continue;
		if(i==1)
			ans+=minn*1./6,p+=1./6;
		else
			ans+=minn*1./3,p+=1./3;
	}
	if(p==0)
		dp[pos]=0;
	else
		dp[pos]=ans/p;
	return dp[pos];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			char x;
			cin>>x;
			if(x=='R')
				a[i][j]=1;
			if(x=='G')
				a[i][j]=2;
			if(x=='B')
				a[i][j]=3;
		}
	}
	cout<<fixed<<setprecision(15)<<dfs(get_hash());
//	cout<<"\n"<<cnt;
}
/*
6
RGB
GRG
BBB
GGR
BRG
BRB
*/