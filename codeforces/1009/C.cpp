#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;
int n, m, x, d;
LL sum, maxn, minn;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        maxn += abs(i - 1);
        minn += abs(i - (n + 1) / 2);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, d;
        cin >> x >> d;
        if (d > 0)
            sum += x * n + d * maxn;
        else
            sum += x * n + d * minn;
    }
    cout << fixed << setprecision(15) << (double)sum / n;
}
 	 	   	  		    		 	      	