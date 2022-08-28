#include <iostream>
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--)
    {
        int n, m, sx, sy, d;
        std::cin >> n >> m >> sx >> sy >> d;
        if (((sy - d > 1) && (d + sx < n)) || ((sx - d > 1) && (d + sy < m)))
        {
            std::cout << m + n - 2 << '\n';
        }
        else
        {
            std::cout << -1 << '\n';
        }
    }
    return 0;
}