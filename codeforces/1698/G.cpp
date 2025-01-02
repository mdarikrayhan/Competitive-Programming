// LUOGU_RID: 158638019
#include <iostream>
#include <bitset>
#include <unordered_map>
using Poly = std::bitset<70>;
using LL = long long;
int H;
Poly mul(Poly a, Poly b, const Poly &S) {
    Poly c;
    for (int i = 0; i < 70; ++i)
        if (a[i]) c ^= b << i;
    for (int i = 69; i >= H; --i)
        if (c[i]) c ^= S << (i - H);
    return c;
}
int main() {
    std::string s;
    std::cin >> s;
    if (s.find('1') == std::string::npos) {
        std::cout << -1 << "\n";
        return 0;
    }
    int p = s.find('1');
    s = s.substr(p);
    while (s.back() == '0')
        s.pop_back();
    int n = s.size();
    LL V = 0;
    for (int i = 0; i < n; ++i) {
        V |= LL(s[i] - '0') << i;
        if (s[i] == '1') H = i;
    }
    Poly S = V, T = S, O;
    if (S.count() == 1) {
        std::cout << p + 1 << " " << p + 2 << "\n";
        return 0;
    }
    T[0] = 0; O[1] = 1;
    LL B = 1 << (n / 2 + 1);
    std::unordered_map<Poly, int> M;
    for (int b = 0; b < B; ++b) {
        M[T] = b;
        T = mul(T, O, S);
    }
    T = 1;
    for (int b = 0; b < B; ++b)
        T = mul(T, O, S);
    Poly P = T;
    for (int i = 1; ; ++i) {
        if (M.find(P) != M.end()) {
            std::cout << p + 1 << " " << p + i * B - M[P] + 1 << "\n";
            break;
        }
        P = mul(P, T, S);
    }
    return 0;
}