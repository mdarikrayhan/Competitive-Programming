#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll mod=998244353;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}
int n, m, a[200005], x[200005], y[200005], fa[200005], cnt[200005];
bool ans[200005], vis[200005];
void clr() {
	for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x) {
	if (fa[x] != x) return fa[x] = find(fa[x]);
	else return x;
}
int work() {
	for (int i = 1; i <= m; i++) {
		if (vis[i]) continue;
		int xx = find(x[i]), yy = find(y[i]);
		if (xx == yy) return i;
		else fa[xx] = yy;
	}
	return -1;
}

//int work2() {
//	for (int i = m; i >= 1; i--) {
//		if (vis[i]) continue;
//		int xx = find(x[i]), yy = find(y[i]);
//		if (xx == yy) return i;
//		else fa[xx] = yy;
//	}
//	return -1;
//}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
	}
	int need_to_find = m - n + 1;
	int bad = 0;
	for (int op = 1; op <= need_to_find; op++) {
		clr();
		int blue = work();
		if (blue == -1) break;
		cnt[x[blue]]++; cnt[y[blue]]++;
		if (cnt[x[blue]] == 2) bad++;
		if (cnt[y[blue]] == 2) bad++;
		if (bad == 3) {
			//no need to rollback
			clr();
			vis[blue] = 2;
			fa[x[blue]] = y[blue];
			int tmp = work();
			assert(blue != tmp);
			blue = tmp;
		}
		vis[blue] = 1;
		ans[blue] = 1;
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i];
	cout << '\n';
	
	for (int i = 1; i <= m; i++) ans[i] = 0, vis[i] = 0;
	for (int i = 1; i <= n; i++) cnt[i] = 0;
} 
	return 0;
}

/*

*/


/*
unordered_map<int,int> mp;
void update(int pos,int val)
{
    for(int i=pos;i<=maxn;i+=lowbit(i))  //change maxn here
    {
        bit[i]+=val;
    }
}
int query(int pos)
{
    int res=0;
    for(int i=pos;i;i-=lowbit(i))
    {
        res+=bit[i];
    }
    return res;
}
*/ 

