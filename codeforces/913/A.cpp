#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int powmod(int a, int b, int c) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = 1LL * res * a % c;
        }
        a = 1LL * a * a % c;
        b >>= 1;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    if (n >= 30) {
        cout << m << endl;
    }
    else {
        cout << m % powmod(2, n, 1e9 + 7) << endl;
    }
    return 0;
}
    	     