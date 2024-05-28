// LUOGU_RID: 160482444
/*
*            /$$           /$$
*           |__/          |__/
*  /$$$$$$$$ /$$ /$$$$$$$$ /$$  /$$$$$$
* |____ /$$/| $$|____ /$$/| $$ /$$__  $$
*    /$$$$/ | $$   /$$$$/ | $$| $$  \ $$
*   /$$__/  | $$  /$$__/  | $$| $$  | $$
*  /$$$$$$$$| $$ /$$$$$$$$| $$|  $$$$$$$
* |________/|__/|________/|__/ \____  $$
*                                   | $$
*                                   | $$
*                                   |__/
*/
//hj23308保佑我
//Missile保佑我
/*
* 醒了在梦里挣扎，不觉黯淡了朝霞
*/
/*
* 我很高兴你没有忘了我，但是我现在更希望你已经忘了我了。
* 希望在你的记忆中，我只是尘土一撮，从你的全世界路过，然后四散飞扬不留下一点痕迹，而你要不回头的往前走。
* 我更希望我只是从你的全世界路过，只是路过
*/
/*
* 只是我在十字路口守了太久，守到黄沙如雨掩埋一切痕迹，才发现自己等的人已经离开了。
*/
/*
* 听我的 别回头 回头就可能会泪流满面，会被黄沙掩埋，所以即使痛苦也要向前走
*/
/*
* 我听到了「天行健」的回响，这是一个伟大斗士的不息自强；
* 我听到了「破万法」的回响，这是一个黑道打手的守护欲望；
* 我看见了「生生不息」的激荡，这是一个骗子的伟大乐章！
*/
#include<bits/stdc++.h>
#define Ls(u) (u<<1)
#define Rs(u) (u<<1|1)
using namespace std;
const int MAXN=5e5+5;
const int MOD=998244353;
int n,m;
string a;
struct Mat {
	long long sum[2][2];
	Mat(bool flag=false)
	{
		memset(sum,0,sizeof(sum));
		if(flag) sum[0][0]=sum[1][1]=1;
	}
	Mat operator * (const Mat &u)const {
		Mat Ans;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					Ans.sum[i][j]+=sum[i][k]*u.sum[k][j]%MOD;
					if(Ans.sum[i][j]>MOD) Ans.sum[i][j]-=MOD;
				}
			}
		}
		return Ans;
	}
	void Cout()
	{
		cout<<sum[0][0]<<" "<<sum[0][1]<<"\n"<<sum[1][0]<<" "<<sum[1][1]<<"\n";
	}
}tree[4*MAXN],Base[10];
void Init()
{
	for(int i=0;i<=9;i++)
	{
		Base[i].sum[0][0]=i+1;
		Base[i].sum[1][0]=9-i;
		if(i==1) Base[i].sum[0][1]=1;
	}
}
void push_up(int u)
{
	tree[u]=tree[Ls(u)]*tree[Rs(u)];
}
void Build(int u,int l,int r)
{
	if(l==r)
	{
//		cout<<"LLL:"<<l<<"\n";
		tree[u]=Base[a[l]-'0'];
//		tree[u].Cout();
		return;
	}
	int mid=(l+r)>>1;
	Build(Ls(u),l,mid);
	Build(Rs(u),mid+1,r);
	push_up(u);
}
void Modify(int u,int l,int r,int site,int val)
{
	if(l==r)
	{
		tree[u]=Base[val];
		return;
	}
	int mid=(l+r)>>1;
	if(site<=mid) Modify(Ls(u),l,mid,site,val);
	else Modify(Rs(u),mid+1,r,site,val);
	push_up(u);
}
int Query()
{
	return tree[1].sum[0][0];
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>a;
	a=" "+a;
	Init();
	Build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int site,val;
		cin>>site>>val;
		Modify(1,1,n,site,val);
		cout<<Query()<<"\n";
	}
	return 0;
}
/*
2 1
14
2 4
*/