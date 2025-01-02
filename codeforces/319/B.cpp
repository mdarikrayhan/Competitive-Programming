// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int ttime[MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for(int i = 0 ; i < n;  i++)
	{
		cin >> v[i];
	}
	ttime[0] = -1;
	stack<int> st;
	int ans = 0;
	for(int i = 0 ; i < n ; i++)
	{
		while(!st.empty() and v[st.top()] <= v[i])
		{
			ttime[i] = max(ttime[i],ttime[st.top()]);
			st.pop();
		}
		ttime[i]++;
		if(st.empty())
		{
			ttime[i] = -1;
		}
		ans = max(ans,ttime[i]);
		st.push(i);
	}

	cout << ans << '\n';

}
