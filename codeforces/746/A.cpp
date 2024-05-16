#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int sum = 0;
    for (int i = 1; i <= a; i++) {
        int x = i;
        int y = 2 * x;
        int z = 4 * x;

        if (y <= b and z <= c)
            sum = x + y + z;
    }

    std::cout << sum << std::endl;

    return 0;
}
