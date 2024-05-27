#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
const int N = 1e5 + 5;
int n, m, x, y, cnt, ans[N];
bool vis[N];
vector<int> e[N];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	if(n * (n - 1) / 2 == m){
		printf("NO");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		if((int)e[i].size() == n - 1)	continue;
		for(auto j : e[i])	vis[j] = true;
		for(int j = 1; j <= n; j++){
			if(i != j && !vis[j]){
				x = i;
				y = j;
				break;
			}
		}
		break;
	}
	for(int i = 1; i <= n; i++){
		if(i != x && i != y)	ans[i] = ++cnt;
	}
	ans[x] = n - 1;
	ans[y] = n;
	printf("YES\n");
	for(int i = 1; i <= n; i++)	printf("%d ", ans[i]);
	printf("\n");
	for(int i = 1; i <= n; i++)	printf("%d ", min(ans[i], n - 1));
	return 0;
}