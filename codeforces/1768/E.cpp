#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int N = 1e6 + 7;

int n, M;
int fact[3 * N], ifact[3 * N];

int add(int a, int b) {
    a += b;
    if (a >= M) return a - M;
    if (a < 0) return a + M;
    return a;
}

int add(int a, int b, int c) {
    return add(a, add(b, c));
}

int mul(int a, int b) {
    return (ll) a * b % M;    
}

int mul(int a, int b, int c) {
    return mul(a, mul(b, c));
}

int pw(int a, int b) {
    int r = 1;
    while (b > 0) {
        if (b & 1) r = mul(r, a);
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int dv(int a, int b) {
    return mul(a, pw(b, M - 2));
}

int comb(int n, int k) {
    if (n < k) return 0;
    return mul(fact[n], ifact[k], ifact[n - k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> M;
    fact[0] = 1;
    for (int i = 1; i < 3 * N; ++i) fact[i] = mul(fact[i - 1], i);
    ifact[3 * N - 1] = dv(1, fact[3 * N - 1]);
    for (int i = 3 * N - 2; i >= 0; --i) ifact[i] = mul(ifact[i + 1], i + 1);

    int zero = 0;
    int one = 0;
    int two = 0;
    int three = 0;

    zero = 1;

    one = add(mul(2, fact[2 * n]), -fact[n]);
    
    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        int cur = 1;
        cur = mul(cur, comb(n, n - i));
        cur = mul(cur, comb(n, i));
        cur = mul(cur, comb(2 * n - i, n));
        cur = mul(cur, fact[n]);
        cur = mul(cur, fact[n]);
        cur = mul(cur, fact[n]);
        sum = add(sum, cur);
    }
    two = mul(2, mul(comb(2 * n, n), fact[n], fact[2 * n]));
    two = add(two, -sum);


    three = fact[3 * n];

    one = add(one, -zero);
    two = add(two, -add(zero, one));
    three = add(three, -add(zero, one, two));

    int ans = 0;
    ans = add(ans, mul(1, one));
    ans = add(ans, mul(2, two));
    ans = add(ans, mul(3, three));
    cout << ans << "\n";
    return 0;
}


