// LUOGU_RID: 158995106
#include <bits/stdc++.h>
using namespace std;
#define getchar() p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++
char buf[1000000], *p1 = buf, *p2 = buf;
template <typename T>
void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -f;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= f;
}
template <typename T, typename... Args>
void read(T &x, Args &...y)
{
    read(x);
    read(y...);
}
template <class T>
void write(T x)
{
    static int stk[30];
    if (x < 0)
        putchar('-'), x = -x;
    int top = 0;
    do
    {
        stk[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(stk[--top] + '0');
}
template <class T>
void write(T x, char lastChar) { write(x), putchar(lastChar); }
const int inf = 1e9;
typedef array<int, 3> pii;
int n, k;
pii a[300020];
int len, L, R;
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
    read(n, k);
    for (int i = 1; i <= n; i++)
        read(a[i][0], a[i][1]), a[i][2] = i;
    sort(a + 1, a + n + 1);
    for (int i = 1; i < k; i++)
        q.push(a[i][1]);
    for (int i = k; i <= n; i++)
    {
        q.push(a[i][1]);
        if (len < q.top() - a[i][0] + 1)
            len = q.top() - (L = a[i][0]) + 1;
        q.pop();
    }
    if (!len)
    {
        write(len, '\n');
        for (int i = 1; i <= n && k > 0; i++)
            write(a[i][2], ' '), k--;
        putchar('\n');
        return 0;
    }
    R = L + len - 1;
    write(len, '\n');
    for (int i = 1; i <= n && k > 0; i++)
        if (a[i][0] <= L && R <= a[i][1])
            write(a[i][2], ' '), k--;
    putchar('\n');
    return 0;
}