// LUOGU_RID: 160055667
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

struct node{
	int s[2], fa;//0左儿子,1右儿子 父亲
	int cnt, num;//子树节点数 节点权值 
	int tot = 0, mn = 0x3f3f3f3f;//子树总权值 节点最小值 
	int tag_rev, tag_mn = 0x3f3f3f3f;//翻转标记 最小值标记 
};
node t[2000001];
int cur = 0, rot = 0;
inline bool isroot(int k){//节点k是不是父亲的虚儿子，或者节点k是不是辅助树的树根 
	if((t[t[k].fa].s[0] != k &&  t[t[k].fa].s[1] != k) || t[k].fa == 0)
		return true;//是虚儿子 
	return false;
}
inline void pushdown(int k){//下传节点k的lazytag 
	if(t[k].tag_rev == 1)
	{
		t[t[k].s[0]].tag_rev ^= 1, t[t[k].s[1]].tag_rev ^= 1;
		swap(t[t[k].s[0]].s[0], t[t[k].s[0]].s[1]), swap(t[t[k].s[1]].s[0], t[t[k].s[1]].s[1]);
		t[k].tag_rev = 0;
	}
	t[t[k].s[0]].mn = min(t[k].tag_mn, t[t[k].s[0]].mn), t[t[k].s[1]].mn = min(t[k].tag_mn, t[t[k].s[1]].mn);
	t[t[k].s[0]].tag_mn = min(t[k].tag_mn, t[t[k].s[0]].tag_mn), t[t[k].s[1]].tag_mn = min(t[k].tag_mn, t[t[k].s[1]].tag_mn);
	t[k].tag_mn = 0x3f3f3f3f;
}
inline int gt(int k){//节点k是父亲的哪个儿子 
	if(t[t[k].fa].s[1] == k)
		return 1;
	return 0;
}
inline void pushup(int k){//计算节点k的cnt 
	t[0].cnt = 0, t[0].tot = 0;
	t[k].cnt = t[t[k].s[0]].cnt + 1 + t[t[k].s[1]].cnt;
	t[k].tot = max(t[k].num, max(t[t[k].s[0]].tot, t[t[k].s[1]].tot));
}
inline void rotate(int k){//将节点k上旋 
	int p = t[k].fa, q = t[p].fa, chk = gt(k);
	t[p].s[chk] = t[k].s[chk ^ 1];
	if(t[k].s[chk ^ 1] != 0)
		t[t[k].s[chk ^ 1]].fa = p;
	t[k].fa = q;
	if(isroot(p) == false)
		t[q].s[gt(p)] = k;
	t[k].s[chk ^ 1] = p, t[p].fa = k;
	pushup(p), pushup(k);
}
inline void update(int k){//将节点k到rot的路径pushdown 
	if(isroot(k) == false)
		update(t[k].fa);
	pushdown(k);
}
inline void splay(int k){//将节点k旋到当前子树的根 
	update(k);
	while(isroot(k) == false)//节点k还没到树根 
	{
		int p = t[k].fa, q = t[t[k].fa].fa;
		if(isroot(p) == false)
		{
			if(gt(p) == gt(k))
				rotate(p);
			else
				rotate(k);
		}
		rotate(k);
		pushup(q), pushup(p), pushup(k);
	}
}
inline void access(int k){//将节点k到rot连接实链 
	splay(k), t[k].s[1] = 0, pushup(k);
	while(t[k].fa != 0)
	{
		splay(t[k].fa);
		t[t[k].fa].s[1] = k, pushup(t[k].fa);
		splay(k);
	}
}
inline void makeroot(int k){//将节点k设置为原树的根节点 
	access(k);
	swap(t[k].s[0], t[k].s[1]), t[k].tag_rev ^= 1;
}
inline int fd(int k){//查找节点k所在子树的树根 
	access(k);
	while(t[k].s[0] != 0)
		k = t[k].s[0], pushdown(k);
	splay(k);
	return k;
}
inline void link(int x, int y){//连接节点x与节点y 
	makeroot(x), access(y);
	pushdown(x), t[x].s[0] = y, t[y].fa = x, pushup(x);
}
inline void cut(int x, int y){//删除节点x与节点y之中的连线 
	makeroot(x), access(y);
	if(t[y].s[0] == x && t[x].fa == y)
		pushdown(y), t[y].s[0] = 0, t[x].fa = 0, pushup(y);
}
inline void split(int x, int y){//将节点x到节点y的路径转化成实边，取出这条链 
	makeroot(x), access(y);
}

int n, m;
int dis[300005];

struct edg{
	int u, v, w, id;
};
edg e[200005];
bool cmp(edg x, edg y){
	return x.w < y.w;
}
int ans[200005];

int fth[200005];
int fdd(int x){
	if(fth[x] == x)
		return x;
	fth[x] = fdd(fth[x]);
	return fth[x];
}

int main()
{
	scanf("%d %d", &n, &m);
	memset(ans, 0x3f3f3f3f, sizeof(ans));
	for(int i = 1; i <= n; i++)
		fth[i] = i;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
		e[i].id = i;
	}
	sort(e + 1, e + m + 1, cmp);
	
	for(int i = 1; i <= m; i++)
	{
		if(fdd(e[i].u) == fdd(e[i].v))//不是MST上的边 
		{
			split(e[i].u, e[i].v);
			ans[e[i].id] = t[e[i].v].tot - 1;
			t[e[i].v].tag_mn = min(t[e[i].v].tag_mn, e[i].w - 1);
			t[e[i].v].mn = min(t[e[i].v].mn, e[i].w - 1);
		}
		else
		{
			t[n + i].num = e[i].w;
			link(e[i].u, n + i);
			link(n + i, e[i].v);
			fth[fdd(e[i].u)] = fdd(e[i].v);
		}
	}
	for(int i = 1; i <= m; i++)
		if(ans[e[i].id] == 0x3f3f3f3f)
		{
			splay(n + i);
			ans[e[i].id] = t[n + i].mn;
		}
	for(int i = 1; i <= m; i++)
		if(ans[i] <= 1000000000)
			cout << ans[i] << ' ';
		else
			cout << -1 << ' ';
	cout << endl;
	return 0;
}
/*

10 21
5 6 88
6 3 74
1 5 7
1 6 27
8 1 50
4 1 24
10 6 37
9 7 39
5 7 63
2 7 98
3 4 28
9 2 5
2 4 96
9 6 67
9 10 47
10 4 64
2 5 70
6 8 89
3 5 54
6 7 18
1 7 26

*/