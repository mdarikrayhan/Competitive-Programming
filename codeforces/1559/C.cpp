#include<cstdio>
#include<algorithm>
using namespace std;
int a[10004];
int main()
{
    int t,n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
            scanf("%d",a+i);
        int pos=0;
        for (int i = n; i >= 1; i--)
        {
            if (!a[i])
            {
                pos=i;
                break;
            }
        }
        if (pos)
        {
            for (int i = 1; i <= pos; i++)
            {
                printf("%d ",i);
            }
            printf("%d ",n+1);
            for (int i = pos + 1; i <= n; i++)
            {
                printf("%d ",i);
            }
            printf("\n");
        }
        else
        {
            printf("%d ",n+1);
            for (int i = 1; i <= n; i++)
            {
                printf("%d ",i);
            }
            printf("\n");
        }
    }
    return 0;
}