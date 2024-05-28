// Hydro submission #663c8ecf3ffdbb8aa73ef719@1715244752262
#include <iostream>
using namespace std;

const int MAXN = 55;
const int INF = 1e6 + 10;

int a[MAXN], dp[INF];

int main() {
    int n, d, last, now;
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = INF; j >= a[i]; j--){
            if(dp[j - a[i]] != 0) {
                dp[j] = 1;
            }
        }
    }
    for(int i = 1; i <= INF; i++){
        last = now;
        for(int j = d + last; j >= now; j--){
            if(dp[j] != 0) {
                now = j;
                break;
            }
        }
        if(last == now) {
            cout << now << " " << i - 1 << endl;
            return 0;
        }
    }
    return 0;
}