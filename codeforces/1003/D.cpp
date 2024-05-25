#include <bits/stdc++.h>
#define ll long long int
#define lp for (int i = 0; i < n; i++)
#define mod 1e9 + 7
using namespace std;
int main()
{
    int n, d;
    cin >> n >> d;
    map<int, int> mp;
    lp
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (int i = 0; i < d; i++)
    {
        int x;
        cin >> x;
        int count = 0;
        for (auto it = mp.rbegin(); it != mp.rend() && x > 0; it++)
        {
            int need = min(x / it->first, it->second);
            count += need;
            x -= (it->first) * need;
        }
        if (x > 0)
            cout << -1 << endl;
        else
            cout << count << endl;
    }

    return 0;
}
 	 						     	  		  	     				