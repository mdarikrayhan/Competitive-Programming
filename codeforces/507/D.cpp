#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
#define LL long long
//#define mod 1000000007
#define pb push_back
#define mp make_pair
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))

using namespace std;

int mod;
int DP[1005][105][2];
int powers[1005],powers2[1005],k,n;

int solve(int ind,int rem, bool change)
{
    if(rem == 0 && change) return (ind != n ? ((powers[n - ind - 1] * 1LL * 9) % mod) : 1);
    if(ind == n || (rem == 0 && change)) return 0;
    int &temp = DP[ind][rem][change];
    if(temp != -1) return temp;
    temp = 0;
    for(int i=0;i<10;i++)
        temp+=solve(ind + 1, (rem + (i * 1LL * powers2[ind]) % k) % k,change || i != 0),temp%=mod;
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> mod;
    setdp(DP);
    LL y = 1;
    for(int i=0;i<=n;i++)
    {
        powers[i] = y;
        y*=10;
        y%=mod;
    }
    y = 1;
    for(int i=0;i<=n;i++)
    {
        powers2[i] = y;
        y*=10;
        y%=k;
    }
    cout << solve(0, 0, 0);
    return 0;
}