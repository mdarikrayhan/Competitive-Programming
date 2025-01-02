// LUOGU_RID: 160460361
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ll long long
#define _mp make_pair
#define _pb push_back
#define _1 first
#define _2 second
#define inf 3423423423423423422ll
#define MAX_N 2222222

using namespace std;

ll read(){ll x = 0;char c = 0, v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c < 33)c = getchar();return c;}

int n, m, q;
char a[MAX_N];

int pid(int i, int j) { return (i - 1) * m + j; }

int v[MAX_N];

void MAIN()
{
    n = read();
    m = read();
    for(int i = 1; i <= n * m; i++)
        a[i] = gtc();
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            if(a[pid(j, i + 1)] == 'X' && a[pid(j + 1, i)] == 'X')
                v[i] = 1;
    for(int i = 2; i < m; i++)
        v[i] += v[i - 1];
    q = read();
    for(int i = 1; i <= q; i++)
    {
        int l = read();
        int r = read() - 1;
        printf(v[r] == v[l - 1] ? "YES\n" : "NO\n");
    }
}

void CLEAR()
{
    ;
}

void EXP()
{
    ;
}

int main()
{
    EXP();
    int T = 1;
    while(T--)
        MAIN(), CLEAR();
    return 0;
}