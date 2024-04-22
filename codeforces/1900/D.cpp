#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>

const int N = 1e5;
long long a[N], ct[N+1], sb[N+1];
std::vector<int>d[N+1];
int main() {
    int cas, n; long long sm;
    for (int i=1, j; i<=N; i++) {
        for (j=i; j<=N; j+=i) d[j].push_back(i);
        for (j=i*2, sb[i]+=i; j<=N; j+=i) sb[j] -= sb[i];
    }
    for (std::cin >> cas; cas--; printf("%lld\n", sm)) {
        std::cin >> n, memset(ct, 0, sizeof ct);
        for (int i=0; i<n; i++) std::cin >> a[i];
        std::sort(a, a+n), sm = 0;
        for (int i=0; i<n; i++) for (int k : d[a[i]])
            sm += (n-i-1)*ct[k], ct[k] += sb[k];
    }
}
