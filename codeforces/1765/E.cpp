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
            if (n % a == 0)
            {
                printf("%d\n", n / a);
            }
            else
            {
                printf("%d\n", n / a + 1);
            }
        }
    }
    return 0;
}