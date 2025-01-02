#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 204;
#define inf (0x3f3f3f3f)
// 1把[l,r]所有都变成 k
// 2把[l,r]所有都变成不是 k
int dp1[N][N][N];
int dp2[N][N][N];
int nxt[N][N];
int prv[N][N];

vector<int> a;
int n, k;
int query2(int l, int r, int m);

int query1(int l, int r, int m) {
    if (l > r) return 0;
    if (l == r) return a[l] != m;
    if (dp1[l][r][m] != -1) return dp1[l][r][m];
    if (a[l] == m) return dp1[l][r][m] = query1(l + 1, r, m);
    if (a[r] == m) return dp1[l][r][m] = query1(l, r - 1, m);
    dp1[l][r][m] = query2(l, r, m) + 1;
    for (int i = l; i < r; ++i)
        dp1[l][r][m] = min(dp1[l][r][m], query1(l, i, m) + query1(i + 1, r, m));
    return dp1[l][r][m];
}

int query2(int l, int r, int m) {
    l = nxt[l][m];
    r = prv[r][m];
    if (l > r) return 0;
    if (l == r) return a[l] == m;
    if (dp2[l][r][m] != -1) return dp2[l][r][m];
    dp2[l][r][m] = inf;

    for (int k = 0; k < n; ++k) {
        int last = -1;
        for (int i = 0; i < n; ++i) {
        }
    }
    for (int i = l; i < r; ++i)
        dp2[l][r][m] = min(dp2[l][r][m], query2(l, i, m) + query2(i + 1, r, m));
    for (int i = 1; i <= k; ++i)
        if (i != m) dp2[l][r][m] = min(dp2[l][r][m], query1(l, r, i));
    return dp2[l][r][m];
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    while(T--)
    {
       cin >> n >> k;
       a.resize(n);
       for (int i = 0; i < n; ++i) cin >> a[i];

       for (int c = 1; c <= k; ++c) {
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == c) last = i;
            prv[i][c] = last;
        }
        last = n;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == c) last = i;
            nxt[i][c] = last;
        }
    }
    int ans = inf;
    for (int i = 1; i <= k; ++i)
        ans = min(ans, query1(0, n - 1, i));
    for(int i=0;i<n;i++)
    for(int j = 0;j<n;j++)
     for(int s=0;s<=k;s++) dp1[i][j][s]=dp2[i][j][s]=-1,nxt[i][s]=
     prv[i][s]=0;
    cout << ans << endl;   
    }
}