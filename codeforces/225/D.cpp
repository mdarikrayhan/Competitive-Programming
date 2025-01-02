// LUOGU_RID: 157868773
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 20;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, m, len;
int sx, sy;
string g[N], now[N], nnow[N];
unordered_map<int, bool> st;

int get1(string g[])
{
    int sx, sy;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            if (g[i][j] == '1') sx = i, sy = j;
        }
    int id = sx * m + sy, sum = 0;
    for (int T = 2, p = 1; T <= len; T ++ , p *= 4)
        for (int i = 0; i < 4; i ++ )
        {
            int nx = sx + dx[i], ny = sy + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (g[nx][ny] == T + '0')
            {
                sum = sum + i * p;
                sx = nx, sy = ny;
            }
        }
    return id * 65536 + sum;
}

void get2(int v, int op)
{
    int id = v / 65536, sum = v % 65536;
    sx = id / m, sy = id % m;
    if (op)
    {
        nnow[sx][sy] = '1';
        if (len > 1) now[sx][sy] = '2';
    }
    else now[sx][sy] = nnow[sx][sy] = '.';
    int x = sx, y = sy;
    for (int T = 2; T < len; T ++ )
    {
        int oop = sum % 4; sum /= 4;
        int nx = x + dx[oop], ny = y + dy[oop];
        if (op) now[nx][ny] = T + 1 + '0', nnow[nx][ny] = T + '0';
        else now[nx][ny] = '.', nnow[nx][ny] = '.';
        x = nx, y = ny;
    }
    int oop = sum;
    int nx = x + dx[oop], ny = y + dy[oop];
    if (op) nnow[nx][ny] = len + '0';
    else nnow[nx][ny] = '.';
}

int main()
{
    scanf("%d%d", &n, &m);
    int mbx, mby;
    for (int i = 0; i < n; i ++ )
    {
        cin >> g[i];
        for (int j = 0; j < m; j ++ )
        {
            if ('1' <= g[i][j] && g[i][j] <= '9') len = max(len, g[i][j] - '0');
            if (g[i][j] == '@') mbx = i, mby = j;
        }
        now[i] = nnow[i] = g[i];
        for (int j = 0; j < m; j ++ )
        {
            if ('0' <= now[i][j] && now[i][j] <= '9') now[i][j] = nnow[i][j] = '.';
        }
    }
    queue<PII> q;
    int tmp = get1(g);
    q.push({tmp, 0}), st[tmp] = true;
    while (q.size())
    {
        PII t = q.front(); q.pop();
        get2(t.first, 1);
        for (int i = 0; i < 4; i ++ )
        {
            int nx = sx + dx[i], ny = sy + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (('0' <= nnow[nx][ny] && nnow[nx][ny] <= '9' && nnow[nx][ny] != len + '0') || nnow[nx][ny] == '#') continue;
            if (nx == mbx && ny == mby)
            {
                printf("%d\n", t.second + 1);
                return 0;
            }
            char pre = now[nx][ny];
            now[nx][ny] = '1';
            int tmp = get1(now);
            now[nx][ny] = pre;
            if (st[tmp]) continue;
            q.push({tmp, t.second + 1}), st[tmp] = true;
        }
        get2(t.first, 0);
    }
    printf("-1\n");
    return 0;
}