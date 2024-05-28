#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define vc vector
#define vci vc<int>
#define psb push_back
using namespace std;
int n, c, ans, mn = 2e9;
vci hv[1000005];
struct P{
	int op, l, r;
};
vc<P> qj;
bool cmp(P a, P b){
	if(a.op != b.op) return a.op;
	if(a.l != b.l) return a.l < b.l;
	return a.r < b.r;
}
void dfs(int x, int l, int r){
//	cout << x << ' ' << l << ' ' << r << endl;
	if(l >= r) return ;
	for(int i = l, j = l; i <= r;){
		while(j <= r && ((hv[i].size() == x && hv[j].size() == x) || (hv[i].size() > x && hv[j].size() > x && hv[i][x] == hv[j][x]))) j++;
//		cout << i << ',' << j << endl;
		if(hv[i].size() > x) dfs(x + 1, i, j - 1);
		if(i > l){
			if(hv[i].size() == x && hv[i - 1].size() > x){
				cout << -1;
				exit(0);
			}
			if(hv[i].size() > x && hv[i - 1].size() > x){
				if(hv[i - 1][x] < hv[i][x]) qj.psb({0, c - hv[i][x] + 1, c - hv[i - 1][x]});
				else qj.psb({1, c - hv[i - 1][x] + 1, c - hv[i][x]});
			}
		}
		i = j;
		j++;
	}
}
//bool chk(int x){
//	int fl = 1;
//	for(int i = 0; i < min(hv[x].size(), hv[x + 1].size()); i++) fl &= (hv[x][i] == hv[x + 1][i]);
//	return hv[x].size() > hv[x + 1].size() && fl;
//}
int main(){
	cin >> n >> c;
	for(int i = 1, s, a; i <= n; i++){
		scanf("%d", &s);
		while(s--){
			scanf("%d", &a);
			hv[i].psb(a);
		}
	}
//	for(int i = 1; i < n; i++)
//		if(chk(i)){
//			cout << -1;
//			return 0;
//		}
	dfs(0, 1, n);
	sort(qj.begin(), qj.end(), cmp);
//	for(int i = 0; i < qj.size(); i++) cout << qj[i].op << ' ' << qj[i].l << ' ' << qj[i].r << endl;
	for(int i = 0; i < qj.size(); i++)
		if(qj[i].op) ans = qj[i].l, mn = min(qj[i].r, mn);
		else if(qj[i].l <= ans && qj[i].r >= ans) ans = qj[i].r + 1;
	if(qj.size() && qj[0].op && ans > mn) cout << -1;
	else cout << ans;
	return 0;
}
   			 		   		 			 		   		   		