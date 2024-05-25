#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define lowbit(x) ((x)&(-x))
#define endl '\n'
#define sc scanf
#define pt printf
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define ls k+k
#define rs k+k+1
using pll = pair<ll, ll>;
using pii = pair<int, int>;
const int N = 2e5 + 10;
vector<string>v;
struct node
{
	int x, y;
	bool tp;
};
int suf[4][200];
bool vis[4][200][2];
void UraykevoliQwQ()
{
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n + 10; i++)
	{
		for (int j = 1; j <= 3; j++)suf[j][i] = vis[j][i][0] = vis[j][i][1] = 0;
	}
	v.clear();
	string tmp;
	for (int i = 1; i <= n + 10; i++)tmp.push_back('*');
	v.push_back(tmp);
	string s;
	cin >> s;
	s = "*" + s + ".*****";
	v.push_back(s);
	cin >> s;
	s = "*" + s + ".*****";
	v.push_back(s);
	cin >> s;
	s = "*" + s + ".*****";
	v.push_back(s);
	v.push_back(tmp);
	for (int i = 1; i <= 3; i++)
	{
		for (int j = n; j >= 1; j--)
		{
			if (v[i][j] != '.')suf[i][j] = suf[i][j + 1] + 1;
			else suf[i][j] = suf[i][j + 1];
		}
	}
	queue<node>q;
	if (v[1][1] == 's')q.push({ 1,1,0 });
	if (v[2][1] == 's')q.push({ 2,1,0 });
	if (v[3][1] == 's')q.push({ 3,1,0 });
	while (q.size())
	{
		auto now = q.front();
		q.pop();
		int x = now.x, y = now.y, tp = now.tp;
		if (suf[x][y] == 0)
		{
			cout << "YES" << endl;
			return;
		}
		if (vis[x][y][tp])continue;
		vis[x][y][tp] = 1;
		if (v[x][y] != '.'&&v[x][y]!='s')continue;
		if (y > n)continue;
		if (tp == 0)
		{
			if (v[x][y + 1] != '.')continue;
			else
			{
				q.push({ x,y + 1,1 });
				if (x + 1 <= 3 && v[x + 1][y + 1] == '.')q.push({ x + 1,y + 1,1 });
				if (x - 1 >= 1 && v[x - 1][y + 1] == '.')q.push({ x - 1,y + 1,1 });
			}
		}
		else
		{
			if (v[x][y + 1] == '.' && v[x][y + 2] == '.')q.push({ x,y + 2,0 });
		}
	}
	cout << "NO" << endl;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--)UraykevoliQwQ();
	return 0;
}