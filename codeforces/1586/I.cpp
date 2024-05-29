// LUOGU_RID: 160440847
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
#define MAX_N 2222

using namespace std;

ll read(){ll x = 0;char c = 0, v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c < 33)c = getchar();return c;}

int n;
char mp[MAX_N][MAX_N];
int a[MAX_N][MAX_N];
int b[MAX_N][MAX_N];
char val[MAX_N];
const int trans = 'G' + (int)'S';

void MAIN()
{
    n = read();
    for(int i = 1; i <= n; i++)
        scanf("%s", mp[i] + 1);
    if(n & 1)
    {
        printf("NONE\n");
        return;
    }
    for(int i = 1; i <= n; i++)
        a[1][i] = a[i][1] = a[n][n + 1 - i] = a[n + 1 - i][n] = (i + 1) >> 1;
    for(int i = 2; i < n; i++)
        for(int j = 2; j < n; j++)
            if((i + j) & 1)
                a[i][j] = a[i - 1][j - 1];
            else
                a[i][j] = a[i - 1][j + 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            b[i][j] = (min(min(i - 1, n - i), min(j - 1, n - j)) & 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(mp[i][j] != '.')
            {
                char c = mp[i][j];
                if(b[i][j])
                    c = trans - c;
                int id = a[i][j];
                if(val[id] && val[id] != c)
                {
                    printf("NONE\n");
                    return;
                }
                val[id] = c;
            }
    for(int i = 1; i <= n / 2; i++)
        if(!val[i])
        {
            printf("MULTIPLE\n");
            return;
        }
    printf("UNIQUE\n");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%c", b[i][j] ? trans - val[a[i][j]] : val[a[i][j]]);
        printf("\n");
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