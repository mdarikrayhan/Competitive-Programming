// LUOGU_RID: 159105135
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 205
#define M 205
#define endl '\n'
int a[N];
string s;
struct Trie
{
    int fail;                // 失配指针
    int vis[26];             // 子节点的位置
    int end;                 // 标记有几个单词以这个节点结尾
} AC[M];                     // Trie树
int cnt = 0;                 // Trie的指针
void build(string s, int id) // 建字典树
{
    int pos = 0;
    for (int i = 0; s[i]; ++i)
    {
        if (!AC[pos].vis[s[i] - 'a'])
            AC[pos].vis[s[i] - 'a'] = ++cnt;
        pos = AC[pos].vis[s[i] - 'a'];
    }
    AC[pos].end += a[id];
}
void getfail() // 构造fail指针,基于bfs
{
    queue<int> q;
    for (int i = 0; i < 26; ++i) // 预处理第二层的fail指针,指向根节点
        if (AC[0].vis[i])
        {
            //  AC[AC[0].vis[i]].fail = 0;
            q.push(AC[0].vis[i]);
        }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        AC[u].end += AC[AC[u].fail].end;
        for (int i = 0; i < 26; ++i)
            if (AC[u].vis[i])
            {
                AC[AC[u].vis[i]].fail = AC[AC[u].fail].vis[i]; // 子节点的fail指针指向当前节点的fail指针所指向的节点的相同子节点
                q.push(AC[u].vis[i]);
            }
            else
                AC[u].vis[i] = AC[AC[u].fail].vis[i]; // 当前节点的这个子节点指向当前节点fail指针的这个子节点
    }
}
struct matrix
{
    int n, m;
    int a[205][205];
    matrix() { memset(a, -0x3f3f, sizeof(a)); }
    matrix operator*(const matrix x) const
    {
        matrix ret;
        ret.n = n;
        ret.m = x.m;
        for (int k = 0; k <= m; k++) // floyed,k放最外层
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= x.m; j++)
                    ret.a[i][j] = max(ret.a[i][j], a[i][k] + x.a[k][j]);
        return ret;
    }
} base, ans;
matrix ksm(matrix n, int k)
{
    matrix ret;
    ret.m = ret.n = n.n;
    for (int i = 0; i <= n.n; i++)
        ret.a[i][i] = 0;
    while (k)
    {
        if (k & 1)
            ret = ret * n;
        n = n * n;
        k >>= 1;
    }
    return ret;
}
void init()
{
    base.n = base.m = cnt;
    for (int i = 0; i <= cnt; i++)
        for (int j = 0; j < 26; j++)
            base.a[i][AC[i].vis[j]] = AC[AC[i].vis[j]].end;
    ans.n = 0;
    ans.m = cnt;
    ans.a[0][0] = 0;
}
int n, l;
signed main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        build(s, i);
    }
    AC[0].fail = 0; // 结束
    getfail();      // 求出失配指针
    init();
    ans = ans * ksm(base, l);
    int res = 0;
    for (int i = 0; i <= cnt; i++)
        res = max(res, ans.a[0][i]);
    cout << res;
    return 0;
}
