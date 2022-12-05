#include <iostream>
int32_t main()
{
    int t, n, a, b;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &n, &a, &b);
        if (a > b)
        {
            printf("1\n");
        }
        else
        {
            printf("%d\n", (n + a - 1) / a);
        }
    }
    return 0;
}