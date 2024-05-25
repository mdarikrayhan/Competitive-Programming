#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned prefix_xor(unsigned x)
{
    switch (x & 3) {
        case 0: return x;
        case 1: return 1;
        case 2: return x + 1;
    }
    return 0;
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    unsigned q = 0;
    for (size_t i = 0, k = 1; i < n; ++i, ++k) {
        q ^= p[i];
        q ^= (n / k % 2) * prefix_xor(i) ^ prefix_xor(n % k);
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
