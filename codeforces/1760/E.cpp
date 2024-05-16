#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int min_zero = -1, max_one = -1;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0 && min_zero == -1)
            {
                min_zero = i;
            }
            if (a[i] == 1 && i > max_one)
            {
                max_one = i;
            }
        }
        ll ans = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                cnt++;
            }
            else
            {
                ans += cnt;
            }
        }
        if (min_zero != -1)
        {
            a[min_zero] = 1;
            cnt = 0;
            ll temp = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == 1)
                {
                    cnt++;
                }
                else
                {
                    temp += cnt;
                }
            }
            ans = max(ans, temp);
            a[min_zero] = 0;
        }
        if (max_one != -1)
        {
            a[max_one] = 0;
            cnt = 0;
            ll temp = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == 1)
                {
                    cnt++;
                }
                else
                {
                    temp += cnt;
                }
            }
            ans = max(ans, temp);
            a[max_one] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}
 			 		 			   	 	 		   	 	   		