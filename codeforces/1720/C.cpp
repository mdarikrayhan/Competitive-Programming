#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, ans = 0, k = 0, flag = 0;
        scanf("%d%d", &n, &m);
        
        int w[n+5][m+5];
        for (int i = 0; i < n; i++)
        {
            char s[m+5];
            scanf("\n%s", s);
            for (int j = 0; j < m; j++)
            {
                ans += (w[i][j] = s[j] - '0');
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                k = w[i][j] + w[i + 1][j] + w[i][j + 1] + w[i + 1][j + 1];
                if (k <= 2)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            printf("%d\n", ans);
        else if(ans==(n*m))
            printf("%d\n", ans-2);
        else
            printf("%d\n", ans - 1);
    }
}