// Problem: F. Cookies
// Contest: Codeforces - Codeforces Round 530 (Div. 2)
// Created: 2024-05-12 23:47:49
// 
// Powered by CP Editor

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
ll T;

const int N = 1e6+1;

ll nums[N];
struct ST{
    ll total;
	ll timer;
	ST *ch[2];
	ST(){
		total = 0;
		timer = 0;
	}
} tree[N << 1], *root;
int stcnt = 0;
void pull(ST *a){
	ST *b = a->ch[0], *c = a->ch[1];
	a->timer = b->timer + c->timer;
	a->total = b->total + c->total;
}
void build(ST *a, int tl, int tr){
	if(tl >= tr){
		return;
	}
	a->ch[0] = &tree[stcnt++];
	a->ch[1] = &tree[stcnt++];
	int tm = (tl+tr)/2;
	build(a->ch[0], tl, tm);
	build(a->ch[1], tm+1, tr);
	pull(a);
}
void update(ST *a, int i, int tl, int tr){
	if(tl == tr){
	    a->total = nums[i];
	    a->timer = 1ll * nums[i] * i;
		return;
	}
	int tm = (tl+tr)/2;
	if(i <= tm){
		update(a->ch[0], i, tl, tm);
	}
	else{
		update(a->ch[1], i, tm+1, tr);
	}
	pull(a);
}
ll query(ST *a, ll ti, int tl, int tr){
    if(tl == tr){
        if(tl == 0) return 0;
        return min(ti / tl, nums[tl]);
    }
    int tm = (tl+tr)/2;
    ll lti = a->ch[0]->timer;
    if(ti >= lti){
        return a->ch[0]->total + query(a->ch[1], ti - lti, tm+1, tr);
    }
    else{
        return query(a->ch[0], ti, tl, tm);
    }
}

int x[N], t[N], p[N], l[N];
vector<int> ch[N];
ll tt[N];
ll dp[N];

void dfs2(int u){
    tt[u] = tt[p[u]] + 2 * l[u];
    nums[t[u]] += x[u];
    update(root, t[u], 0, 1000000);
    dp[u] = query(root, T - tt[u], 0, 1000000);
    // cout << u << ": " << dp[u] << endl;
    for(int v : ch[u]){
        dfs2(v);
    }
    nums[t[u]] -= x[u];
    update(root, t[u], 0, 1000000);
}

ll dp2[N];

void dfs3(int u){
    ll mx1 = -1, mx2 = -1;
    for(int v : ch[u]){
        dfs3(v);
        if(dp2[v] > dp[u]){
            if(dp2[v] > mx1){
                mx2 = mx1; mx1 = dp2[v];
            }
            else if(dp2[v] > mx2) mx2 = dp2[v];
        }
    }
    if(mx1 == -1 || (mx2 == -1 && u != 1)){
        dp2[u] = dp[u];
        return;
    }
    if(u == 1){
        dp2[u] = mx1;
    }
    else{
        dp2[u] = mx2;
    }
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	root = &tree[stcnt++];
	build(root, 0, 1000000);
	cin >> n >> T;
	for(int i=1; i<=n; i++) cin >> x[i];
	for(int i=1; i<=n; i++) cin >> t[i];
	for(int i=2; i<=n; i++){
	    cin >> p[i] >> l[i];
	    ch[p[i]].push_back(i);
	}
	dfs2(1);
	dfs3(1);
	cout << dp2[1] << endl;
}