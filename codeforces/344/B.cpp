#include <cstdio>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int sum = a + b + c;

    if(sum % 2 == 0)
    {
        sum /= 2;
        int x = sum - c;
        int y = sum - a;
        int z = sum - b;

        if(x >= 0 && y >= 0 && z >= 0)
            printf("%d %d %d\n", x, y, z);
        else
            printf("Impossible\n");
    }
    else
        printf("Impossible\n");

    return 0;
}