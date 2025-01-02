// LUOGU_RID: 158686764
#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int x, y, id;
};
node a[1000010];
int cnt[1000010], ans[1000010];
bool cmp1(node x,node y){
	if (x.x != y.x) return x.x < y.x;
	return x.y < y.y;
}
bool cmp2(node x, node y) {
	if (x.y != y.y) return x.y < y.y;
	return x.x < y.x;
}
bool cmp3(node x, node y){
	if (x.x + x.y != y.x + y.y) return x.x + x.y < y.x + y.y;
	return x.x < y.x;
}
bool cmp4(node x, node y){
	if (x.x - x.y != y.x - y.y) return x.x - x.y < y.x - y.y;
	return x.x < y.x;
}
bool cmp5(node x, node y) {
	return x.id < y.id;
}
signed main(){
	cin>>n>>m;
	a[0]=((node){2*n+1,4*n + 1, 0});
	a[m+1]=((node){4 * n + 1, 8 * n + 1, m + 1});
	for (int i = 1; i <= m; i++){
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	sort(a + 1, a + m + 1, cmp1);
	for (int i = 1; i <= m; i++)
	{
		ans[a[i].id] += 2; 
		if (a[i].x != a[i - 1].x) ans[a[i].id]--;
		if (a[i].x != a[i + 1].x) ans[a[i].id]--;
	}
	sort(a + 1, a + m + 1, cmp2);
	for (int i = 1; i <= m; i++)
	{
		ans[a[i].id] += 2; 
		if (a[i].y != a[i - 1].y) ans[a[i].id]--;
		if (a[i].y != a[i + 1].y) ans[a[i].id]--;
	} 
	sort(a + 1, a + m + 1, cmp3);
	for (int i = 1; i <= m; i++)
	{
		ans[a[i].id] += 2; 
		if (a[i].y + a[i].x != a[i - 1].y + a[i - 1].x) ans[a[i].id]--;
		if (a[i].y + a[i].x != a[i + 1].y + a[i + 1].x)	ans[a[i].id]--;
	}
	sort(a + 1, a + m + 1, cmp4);
	for (int i = 1; i <= m; i++)
	{
		ans[a[i].id] += 2; 
		if (a[i].x - a[i].y != a[i - 1].x - a[i - 1].y) ans[a[i].id]--;
		if (a[i].x - a[i].y != a[i + 1].x - a[i + 1].y) ans[a[i].id]--;
	}
	sort(a+1,a+m+1,cmp5);
	for (int i = 1; i <= m; i++) cnt[ans[i]]++;
	for (int i = 0; i <= 8; i++) cout << cnt[i] << " ";
    return 0;
}
