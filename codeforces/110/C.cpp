#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    if (n == 0 || n == 1 || n == 2 || n == 3 || n == 5 || n == 6 || n == 9 || n == 10)
    {
        std::cout << "-1";
        return 0;
    }
    for (int i = 0; i < ((n % 7) / 4) + (((n % 7) % 4) * 2); i++)
    {
        std::cout << "4";
    }
    for (int i = 0; i < ((n / 7) - ((n % 7) % 4)); i++)
    {
        std::cout << "7";
    }
    return 0;
}