#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("a\n");
        break;
    case 2:
        printf("ab\n");
        break;
    case 3:
        printf("abc\n");
        break;

    default:
        for (int i = 0; i < n / 4; i++)
        {
            printf("abcd");
        }

        int t = n % 4;
        switch (t)
        {
        case 1:
            printf("a\n");
            break;
        case 2:
            printf("ab\n");
            break;
        case 3:
            printf("abc\n");
            break;
        }
        break;
    }

    return 0;
}