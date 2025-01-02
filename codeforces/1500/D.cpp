// LUOGU_RID: 160537263
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int maxn = 1505;
const int p = 998244353;

int n, q, a[maxn][maxn], ans[maxn];

struct node
{
    int x, y;
    node operator+(const node& rhs) const
    {
        return (node) { x + rhs.x, y + rhs.y };
    }
    bool operator<(const node& rhs) const
    {
        return max(x, y) < max(rhs.x, rhs.y);
    }
};

vector<node> hsh[maxn][maxn];

bool vis[maxn * maxn];

int read()
{
	int ret = 0, ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		;
	for (; isdigit(ch); ch = getchar())
		ret = (ret << 3) + (ret << 1) + (ch & 15);
	return ret;
}

int main()
{
    n = read(), q = read();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            a[i][j] = read();
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            vector<node> vec;
            vec.push_back((node) { 0, 0 });
            for (auto it : hsh[i - 1][j])
                vec.push_back(it + (node) { 1, 0 });
            for (auto it : hsh[i][j - 1])
                vec.push_back(it + (node) { 0, 1 });
            for (auto it : hsh[i - 1][j - 1])
                vec.push_back(it + (node) { 1, 1 });
            sort(vec.begin(), vec.end());
            for (auto it : vec)
            {
                if (vis[a[i - it.x][j - it.y]])
                    continue;
                vis[a[i - it.x][j - it.y]] = 1;
                hsh[i][j].push_back(it);
                if (hsh[i][j].size() > q)
                    break;
            }
            for (auto it : hsh[i][j])
                vis[a[i - it.x][j - it.y]] = 0;
            int len = min(i, j);
            if (hsh[i][j].size() > q)
                len = min(len, max(hsh[i][j].rbegin()->x, hsh[i][j].rbegin()->y));
            ++ans[len];
        }
    }
    for (int i = n; i >= 1; --i)
        ans[i] += ans[i + 1];
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
	return 0;
}