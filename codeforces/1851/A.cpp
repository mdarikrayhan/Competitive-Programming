#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <ctime>
#include <numeric>
#include<stdint.h>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <bitset>
#include <deque>
#include <queue>

#define int long long
#define ull unsigned long long  

using namespace std;

ull BS(vector<ull>& a, ull x)
{
    ull l = 0, r = a.size() - 1;
    while (l <= r)
    {
        ull mid = l + (r - l) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else if (a[mid] > x) {
            r = mid - 1;
        }
    }
    return -1;
}
ull BS_UB(vector<ull>& a, ull x)
{
    ull l = 0, r = a.size() - 1;
    ull ans = -1;
    while (l <= r)
    {
        ull mid = l + (r - l) / 2;
        // if (a[mid] == x)
        // {
        //     return mid;
        // }
        if (a[mid] <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (a[mid] > x) {
            r = mid - 1;
        }
    }
    return ans;
}
ull BS_LB(vector<ull>& a, ull x)
{
    ull l = 0, r = a.size() - 1;
    ull ans = -1;
    while (l <= r)
    {
        ull mid = l + (r - l) / 2;
        // if (a[mid] == x)
        // {
        //     return mid;
        // }
        if (a[mid] < x)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (a[mid] >= x) {
            r = mid - 1;
        }
    }
    return ans;
}
// const ll N = 1e11;
// ll a[N];
bool checkWin(char board[3][3], char player)
{
    // Check rows, columns, and diagonals 
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player
            && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player
            && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player
        && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player
        && board[2][0] == player)
        return true;
    return false;
}
void solve()
{
    int n, m, k, h; cin >> n >> m >> k >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    vector<int> high(m);
    for (int i = 0; i < m; i++)
    {
        high[i] = (i + 1) * k;
    }
    // high.pop_back();
    for (int i = 0; i < n; i++)
    {
        int temp = abs(a[i] - h);
        //cout << "temp " << temp << '\n';
        if (temp % k == 0) {
            //cout << "HIghs" << '\n';
            for (int j = 0; j < m - 1;j++) {
                //cout << "high J " << high[j] << '\n';
                if (temp == high[j]) {
                    // puts("here");
                    ans++;
                    //break;
                }

            }
        }
    }

    cout << ans << '\n';



}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
