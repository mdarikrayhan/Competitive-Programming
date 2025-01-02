// LUOGU_RID: 159328040
#include<bits/stdc++.h>
#define ls nd[x].son[0]
#define rs nd[x].son[1]
using namespace std;

int read()
{
	int x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x;
}

const int N = 400010;

namespace LCT{
	struct Node
	{
        bool isCurColor;
		int allsize;
        int imsize;
        long long imsize2sum;
		int son[2], fa;
		bool flip;
        long long allsize2() const{ return (long long) allsize * allsize; }
	} nd[N];
	int sta[N],top=0;
	int colcnt = 0;

	inline bool nroot(int y){int x=nd[y].fa;return ls==y||rs==y;}
	inline void maintain(int x){
		nd[x].allsize = nd[ls].allsize + nd[rs].allsize + nd[x].imsize + 1;
	}
	inline void pushr(int x){swap(ls,rs);nd[x].flip^=1;}
	inline void pushdown(int x)
	{
		if(nd[x].flip)
		{
			if(ls) pushr(ls);
			if(rs) pushr(rs);
			nd[x].flip=0;
		}
	}

	void rotate(int x)
	{
		int y=nd[x].fa,z=nd[y].fa;
		int k=(nd[y].son[1]==x),w=nd[x].son[k^1];
		if(nroot(y)) nd[z].son[nd[z].son[1]==y]=x;
		nd[x].son[k^1]=y;
		nd[y].son[k]=w;
		if(w) nd[w].fa=y;
		nd[x].fa=z;
		nd[y].fa=x;
		maintain(y);
		maintain(x);
	}

	void splay(int x)
	{
		int y=x,z;top=0;
		sta[++top]=y;
		while(nroot(y)) y=nd[y].fa,sta[++top]=y;
		while(top) pushdown(sta[top--]);
		while(nroot(x))
		{
			y=nd[x].fa;
			z=nd[y].fa;
			if(nroot(y)) rotate((nd[y].son[0]==x)^(nd[z].son[0]==y)?x:y);
			rotate(x);
		}
		maintain(x);
	}

	void access(int x)
	{
		int y=0;
		while(x)
		{
			splay(x);
            nd[x].imsize -= nd[y].allsize;
            nd[x].imsize2sum -= nd[y].allsize2();
            nd[x].imsize += nd[rs].allsize;
            nd[x].imsize2sum += nd[rs].allsize2();
			rs=y;
			maintain(x);
			y=x;x=nd[x].fa;
		}
	}
	int find(int x)
	{
		access(x);splay(x);
		while(ls) pushdown(x),x=ls;
		return x;
	}
    // y 在 x 上面
	void cut(int x,int y)
	{
		access(x);
        splay(x);
        nd[ls].fa = 0;
        ls = 0;
        maintain(x); 
	}
    // y 在 x 上面
	void link(int x,int y)
    {
        access(y);
        splay(y);
        access(x);
        splay(x);
        nd[y].son[1] = x;
        nd[x].fa = y;
        maintain(y);
    }
}

struct Modify{
    int u;
    int time;
};

int n, m, col[N];
vector<Modify> update[N];
long long ans[N];
int treefa[N];
vector<int> g[N];

long long doModify(int u){
    using namespace LCT;
    long long updans = 0;
    if(nd[u].isCurColor == true){
        // 变成非当前色（白变黑）
        int y = treefa[u];
        access(u);
        updans -= nd[u].imsize2sum;
        access(y);
        splay(y);
        int x = find(y);
        splay(x);
        updans -= nd[rs].allsize2();
        link(u, y);
        splay(x);
        updans += nd[rs].allsize2();
    } else {
        // 变成当前色（黑变白）
        int y = treefa[u];
        access(u);
        updans += nd[u].imsize2sum;
        // cout << "check1: " << nd[u].imsize2sum << endl;
        splay(u);
        int x = find(u);
        // cout << u << " " << x << endl;
        splay(x);
        updans -= nd[rs].allsize2();
        cut(u, y);
        access(y);
        splay(x);
        updans += nd[rs].allsize2();
    }
    nd[u].isCurColor ^= 1;
    // exit(0);
    return updans;
}

void dfs(int u){
    for(int v : g[u]){
        if(v == treefa[u]) continue;
        treefa[v] = u;
        LCT::link(v, u);
        dfs(v);
    }
}

int main()
{
    // freopen("input", "r", stdin);
    n = read(); m = read();
    for(int i = 1; i <= n; ++i){
        col[i] = read();
        LCT::nd[i].allsize = 1;
        update[col[i]].push_back((Modify){i,0});
    }
    for(int i = 1; i < n; ++i){
        int u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    treefa[1] = n + 1;
    LCT::nd[n+1].allsize = 1;
    LCT::nd[n+1].isCurColor = true;
    LCT::link(1, n+1);

    for(int i = 1; i <= m; ++i){
        int u = read(), c = read();
        update[col[u]].push_back((Modify){u,i});
        update[col[u]=c].push_back((Modify){u,i});
    }
    for(int c = 1; c <= n; ++c){
        for(int i = 0; i < update[c].size(); ++i)
            ans[update[c][i].time] += doModify(update[c][i].u);
        for(int i = update[c].size() - 1; i >= 0; --i)
            doModify(update[c][i].u);
    }
    for(int i = 0; i <= m; ++i){
        if(i) ans[i] += ans[i-1];
        printf("%lld\n", -ans[i]);
    }
	return 0;
}