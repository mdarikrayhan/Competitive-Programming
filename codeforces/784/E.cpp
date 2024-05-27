// LUOGU_RID: 160450079
#include <bits/stdc++.h>
    
#define x first
#define y second
#define ls (k << 1)
#define rs (k << 1 | 1)
#define mp make_pair
#define pb push_back
    
using namespace std; 

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, char> PIC;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<PII, PII> PIIII;
typedef pair<double, double> PDD;

const int N = 1000010;
const int M = 21;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-8;

/*
维护累加串和当前正在枚举的串的哈希即可
*/

int T;
int s[5];

void solve1() {
    cin >> s[1] >> s[2] >> s[3] >> s[4];
    int val1 = (s[1] ^ s[2]);
    int val2 = (s[3] | s[4]);
    int val3 = (s[2] & s[3]);
    int val4 = (s[1] ^ s[4]);
    int val5 = (val1 & val2);
    int val6 = (val3 | val4);
    cout << (val5 ^ val6) << "\n";
}                                                                                                                  

void solve2() {
    
}
    
void prepare() {
    
}

void init() {

}
    
void solve() {
    solve1();
    // solve2();
}
    
int main() {
    #ifdef LOCAL_TEST
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    T = 1;
    // cin >> T;
    prepare();
    while (T--) {
        init();
        solve();
    }
    
    return 0;
}