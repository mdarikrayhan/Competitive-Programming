#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int,int>

const int N = 1e5 + 10;

struct edges{
	int to;
	int before;
}e[2 * N];
int last[N],cnt;

void add(int u,int v){
	e[++ cnt].to = v;
	e[cnt].before = last[u];
	last[u] = cnt;
}

struct segment_tree{
	int l;
	int r;
	int x;
	int tagx;
	int sumroot;
	int tagsum;
}tr[N << 2];

void build(int u,int l,int r){
	tr[u] = {l,r,0,0,0};
	if (l == r) return;
	int mid = l + r >> 1;
	build(u << 1,l,mid);
	build(u << 1 | 1,mid + 1,r);
}

void modify1(int u,int l,int r,int x){
	if (l > r) return;
//	cout << "modify1" << " " << l << " " << r << " " << x << "\n";
	if (r < tr[u].l || tr[u].r < l) return;
	if (l <= tr[u].l && tr[u].r <= r){
		tr[u].tagx += x;
		tr[u].x += x;
		return;
	}
	modify1(u << 1,l,r,x);
	modify1(u << 1 | 1,l,r,x);
}
void push_downx(int u){
	if (tr[u].tagx){
		tr[u << 1].x += tr[u].tagx;
		tr[u << 1].tagx += tr[u].tagx;
		tr[u << 1 | 1].x += tr[u].tagx;
		tr[u << 1 | 1].tagx += tr[u].tagx;
		tr[u].tagx = 0;
	}
}

int query1(int u,int pos){
	if (tr[u].l == tr[u].r) return tr[u].x;
	push_downx(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (pos <= mid) return query1(u << 1,pos);
	return query1(u << 1 | 1,pos);
}

void push_downroot(int u){
	if (tr[u].tagsum){
		tr[u << 1].sumroot += tr[u].tagsum;
		tr[u << 1].tagsum += tr[u].tagsum;
		tr[u << 1 | 1].sumroot += tr[u].tagsum;
		tr[u << 1 | 1].tagsum += tr[u].tagsum;
		tr[u].tagsum = 0;
	}
}

void modify2(int u,int l,int r,int x){
	if (l > r) return;
//	cout << "modify2" << " " << l << " " << r << " " << x << "\n";
	if (r < tr[u].l || tr[u].r < l) return;
	if (l <= tr[u].l && tr[u].r <= r){
		tr[u].tagsum += x;
		tr[u].sumroot += x;
		return;
	}
	modify2(u << 1,l,r,x);
	modify2(u << 1 | 1,l,r,x);
}

int query2(int u,int pos){
	if (tr[u].l == tr[u].r) return tr[u].sumroot;
	push_downroot(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (pos <= mid) return query2(u << 1,pos);
	return query2(u << 1 | 1,pos);
}

int dfn[N],deep[N],maxd[N],dfntamp;

void dfs(int u){
	dfn[u] = ++ dfntamp;
	maxd[u] = dfn[u];
	for (int i = last[u]; i ;i = e[i].before){
		int v = e[i].to;
		if (dfn[v]) continue;
		deep[v] = deep[u] + 1;
		dfs(v);
		maxd[u] = max(maxd[u],maxd[v]);
	}
}

void solve(){
	int n,q;
	cin >> n >> q;
	for (int i = 1,u,v;i <= n - 1;i ++){
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	deep[1] = 1;
	dfs(1);
	build(1,1,n);
	while(q --){
		int op;
		cin >> op;
		if (op == 0){
			int u,x,d;
			cin >> u >> x >> d;
//			cout << u << " " << d << ":\n";
			if (u == 1){
				modify2(1,1,d + 1,x);
				continue;
			}
			if (deep[u] - d > 1){
				modify1(1,dfn[u] - d,min(dfn[u] + d,maxd[u]),x);
			}else{
				int dd = d - deep[u] + 2;
				modify2(1,1,dd,x);
				modify1(1,dfn[u] - deep[u] + dd + 1,min(dfn[u] + d,maxd[u]),x);
			}
		}else{
			int u;
			cin >> u;
			cout << query1(1,dfn[u]) + query2(1,deep[u]) << "\n";
		}
	}
	
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t --){
		solve();
	}
}