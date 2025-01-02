// LUOGU_RID: 159841490
#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> e[100005], ans[100005];
bool vis[100005] = {0};
void dfs(long long x, long long p){
	vis[x] = 1;
	for(int i: e[x]){
		if(i == p)
			continue;
		if(vis[i]){
			ans[i].push_back(x);
			continue;
		}
		dfs(i, x);
		if(ans[i].size()){
			cout << ans[i][ans[i].size() - 1] << ' ' << i << ' ' << x << endl;
			ans[i].pop_back();
		}
		else
			ans[x].push_back(i);
	}
	while(ans[x].size() >= 2){
		cout << ans[x][ans[x].size() - 1] << ' ' << x << ' ' << ans[x][ans[x].size() - 2] << endl;
		ans[x].pop_back(), ans[x].pop_back();
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1, x, y;i <= m;i++){
		cin >> x >> y;
		e[x].push_back(y), e[y].push_back(x);
	}
	if(m % 2 == 1){
		cout << "No solution\n";
		return 0;
	}
	dfs(1, 0);
	return 0;
} 