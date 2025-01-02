#include<bits/stdc++.h>
#define int long long
#define _ ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
using namespace std;
int n, m, i, l, r, x, y, len, pos;  string a, b[10];
signed main()
{
    cin >> a >> m;  n = a.size();
    for (i = 0; i < m; i++) cin >> b[i];
    sort(b,b+m);
    for (l = r = 0; r < n; r++){
        for (i = 0; i < m; i++){
            if (b[i].size() <= r - l + 1){
                for (x = r, y = b[i].size() - 1; y>=0 && a[x] == b[i][y]; x--, y--);
                if (y == -1) l = x + 2;
            }
        }
        if (r - l + 1 > len) len = r - l + 1, pos = l;
    }
    return cout << len << " " << pos, 0;
}
