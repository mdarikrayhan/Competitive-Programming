#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &x, &m, &y);
    
 
    int l = abs(y - x);
    
 
    long long ans = n + m + 1;
    

    for (int i = 1; i <= n; i++) {
        if (abs(l - i) < m) {
        
            ans += 2 * min(m, i + l - 1)+((l-i)*2^-int(l>=i));
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}
