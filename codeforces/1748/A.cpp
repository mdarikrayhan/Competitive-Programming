#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include <iomanip>
#include<queue>
#include<cmath>
#include<map>
using namespace std;
#define int long long
#define INF 1e18
#define x first 
#define y second 
typedef pair<int,int> PII;
const int N = 2e6 + 10;
const int M = 2e6 + 10;
const int mod = 998244353;
int n, m, k;

void sovel()
{
    cin >> n;
    int res = 0;
    if (n % 2 != 0)res = n / 2 + 1;
    else res = n / 2;
    cout << res << endl;
}

signed main()
{
    int pp = 1;
    cin >> pp;
    while (pp--)
    {
        sovel();
    }
    return 0;
}