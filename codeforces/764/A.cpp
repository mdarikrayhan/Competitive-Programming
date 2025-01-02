#include <iostream>

int gcd(int x, int y) {
    if (y == 0)
        return x;

    return gcd(y, x % y);
}

int lcm(int x, int y) {
    return (x * y) / gcd(x, y);
}

int main() {
    int n, m, z;
    std::cin >> n >> m >> z;

    std::cout << (z / lcm(n, m)) << std::endl;

    return 0;
}
