// LUOGU_RID: 160071434
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int n, L, R, ans;
int a[1010], ct[1010];
int f[1010][1 << 8];
vector <int> rec[1010];
int check(int x)//判断M是否合法
{
    memset(ct, 0, sizeof(ct));
    
    for (int i = 0; i <= n; i++)
        for (int j = 1; j < (1 << 8); j++) f[i][j] = -INF;
    
    f[0][0] = 0; //初始化
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << 8); j++)
            if (f[i][j] != -INF)
                for (int k = 0; k < 8; k++)
                    if ((j & (1 << k)) == 0)
                    {
                        int h = x + ct[k] - 1;
                        
                        if (h >= rec[k].size()) continue; //判断h是否存在
                        
                        f[rec[k][h] + 1][j | (1 << k)] = max(f[rec[k][h] + 1][j | (1 << k)], f[i][j]);
                        h++;
                        
                        if (h >= rec[k].size()) continue;
                        
                        f[rec[k][h] + 1][j | (1 << k)] = max(f[rec[k][h] + 1][j | (1 << k)], f[i][j] + 1); //DP，详见题解
                    }
        
        ct[a[i + 1] - 1]++; 
    }
    
    int cnt = -INF;
    for (int i = 0; i <= n; i++) cnt = max(cnt, f[i][(1 << 8) - 1]);
    return cnt == -INF ? -1 : x * 8 + cnt; 
}
int main()
{
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i++) rec[a[i] - 1].push_back(i - 1); //存储数字i出现的位置
    
    L = 1;
    R = n >> 3;
    
    while (L <= R) //二分答案a
    {
        int M = (L + R) >> 1;
        
        if (check(M) != -1) ans = max(ans, check(M)), L = M + 1; //M合法，保存其值并去除非最优解
        else R = M - 1; //M不合法，去除M及M以上的不合法解
    }
    
    if (ans == 0) for (int i = 0; i < 8; i++) if (rec[i].size()) ans++; //讨论x=0的情况
    
    printf("%d", ans);
    
    return 0;
}