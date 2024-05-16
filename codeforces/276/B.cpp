#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <random>
#include <chrono>
#include <memory>
#include <list>
#if __cplusplus >= 201703L
#include <variant>
#endif
#include <complex>
#include <cassert>
#include <bitset>
#if __cplusplus > 201703L
//#include <ranges>
#endif

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

void fast_input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

long long gcd(long long a, long long b) {
    while (b) {
        swap(a, b);
        b %= a;
    }
    return a;
}

long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }

bool is_prime(long long n) {
    if (n == 1) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int number_sum(long long num) {
    int sum=0;
    while (num) {
        sum+=(num%10);
        num/=10;
    }
    return sum;
}

template<class T>
bool bmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T>
bool bmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()

void solve() {
    string s;
    cin >> s;
    int k1=0;
    int k2=0;
    map<char, int> mp;
    for (char c: s) mp[c]++;
    for (auto p: mp) p.second%2 ? k1++ : k2++;
    if ((max(1ll, k1)-1)%2) cout << "Second";
    else cout << "First";
}

int32_t main() {
    //fast_input();
    long long te = 1;
    int k=1;
    //cin >> te;
    while (te--) {
        //cerr << "I AM TEST NUMBER " << k++ << endl;
        solve();
        cout << endl;
    }
}
