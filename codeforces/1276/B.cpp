// LUOGU_RID: 159857653
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a, b;
ll u, v;
ll T;
vector <ll> Adjacency_List[200002];//邻接表
bool vis_Stop_At_Point_B[200002];//标记数组
bool vis_Stop_At_Point_A[200002];
bool vis_Whether_To_Walk_Through[200002];
void dfs_Stop_At_Point_B(ll x)
{
	vis_Stop_At_Point_B[x] = 1;
	if(x == b)//到b停止
	{
		return ;
	}
	for(int i = 0; i < Adjacency_List[x].size(); i++)//遍历
	{
		if(!vis_Whether_To_Walk_Through[Adjacency_List[x][i]])//判断是否走过
		{
			vis_Whether_To_Walk_Through[Adjacency_List[x][i]] = 1;//标记为1即走过
			dfs_Stop_At_Point_B(Adjacency_List[x][i]);//继续深搜
		}
	}
}
void dfs_Stop_At_Point_A(ll x)
{
	vis_Stop_At_Point_A[x] = 1;
	if(x == a)//到a停止
	{
		return ;
	}
	for(int i = 0; i < Adjacency_List[x].size(); i++)//遍历
	{
		if(!vis_Whether_To_Walk_Through[Adjacency_List[x][i]])//判断是否走过
		{
			vis_Whether_To_Walk_Through[Adjacency_List[x][i]] = 1;//标记为1即走过
			dfs_Stop_At_Point_A(Adjacency_List[x][i]);//继续深搜
		}
	}
}
void Run()
{
	cin >> n >> m >> a >> b;
	for(int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		Adjacency_List[u].push_back(v);//放入邻接表
		Adjacency_List[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
		sort(Adjacency_List[i].begin(), Adjacency_List[i].end());//排序
	vis_Whether_To_Walk_Through[a] = a;//标记
	dfs_Stop_At_Point_B(a);
	memset(vis_Whether_To_Walk_Through, 0, sizeof(vis_Whether_To_Walk_Through));//还原
	vis_Whether_To_Walk_Through[b] = b;//标记
	dfs_Stop_At_Point_A(b);
	ll cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!vis_Stop_At_Point_B[i])//数0的个数
			cnt1++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis_Stop_At_Point_A[i])//数0的个数
			cnt2++;
	}
	cout << cnt1 * cnt2 << "\n";//用乘法原理算结果
}
int main()
{
	cin >> T;
	while(T--)
	{
		Run();
		memset(vis_Whether_To_Walk_Through, 0, sizeof(vis_Whether_To_Walk_Through));//初始化
		memset(vis_Stop_At_Point_A, 0, sizeof(vis_Stop_At_Point_A));
		memset(vis_Stop_At_Point_B, 0, sizeof(vis_Stop_At_Point_B));
		for(int i = 1; i <= n; i++)
			Adjacency_List[i].clear();
		
	}
	return 0;
}