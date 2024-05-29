#include <bits/stdc++.h>
using namespace std;
vector<int> G[1001];
map<pair<int, int>, int> idx;
int N; double t[1001];
void dfs(int x, int l){
	int d = G[x].size();
	double v = l == 0 ? 0 : 1 + t[x],dt = 2. / d;
	for (int y : G[x]) if (y != l){
		v += dt;
		while (v >= 2) v -= 2;
		t[y] = v;
		printf ("1 %d ",idx[{x,y}]);
		if (v < 1) printf ("%d %d %.12lf\n",x,y,v);
		else printf ("%d %d %.12lf\n",y,x,v-1);
		dfs(y,x);
	}
}
int main(){
	scanf("%d",&N);
	for (int i=1;i<N;i++){
		int x,y; scanf ("%d %d",&x,&y);
		idx[{x,y}] = idx[{y,x}] = i;
		G[x].push_back(y),G[y].push_back(x);
	}
	printf ("%d\n",N-1);
	dfs(1,0);
}