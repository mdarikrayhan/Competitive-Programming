// LUOGU_RID: 160531436
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n;
struct node {
	int x, y;
} a[N];
bool cmp(node x, node y) {return x.x + x.y < y.x + y.y;}
priority_queue<int> L;
priority_queue< int, vector<int>, greater<int> > R;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1, cmp);
	L.push(a[1].x); R.push(a[1].x);
	int delta = 0;
	long long ans = 0;
	for(int i = 2; i <= n; i++)
	{
		delta += (a[i].x + a[i].y) - (a[i - 1].x + a[i - 1].y);
		int l = L.top(), r = R.top() + delta;
		if(a[i].x < l)
		{
			L.pop();
			L.push(a[i].x);
			L.push(a[i].x);
			R.push(l - delta);
			ans += l - a[i].x;
		}
		else if(a[i].x > r)
		{
			R.pop();
			R.push(a[i].x - delta);
			R.push(a[i].x - delta);
			L.push(r);
			ans += a[i].x - r;
		}
		else
		{
			L.push(a[i].x);
			R.push(a[i].x - delta);
		}
	}
	cout << ans;
	return 0;
}