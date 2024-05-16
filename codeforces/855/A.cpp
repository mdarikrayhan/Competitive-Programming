#include <bits/stdc++.h>
#define int long long int
using namespace std;
int cckk(vector<int> &v, int n, int w)
{
    int sum = 0, ck = 1e18;
    for (int i = 0; i < n; i++)
    {
        int c = (2 * w) + v[i];
        sum += (c * c);
        if (sum > ck)
        {
            return sum;
        }
    }
    return sum;
}
void slv()
{
    map<string, int> mp;
    int m;
    cin >> m;
    while (m--)
    {
        string a;
        cin >> a;
        mp[a]++;
        if (mp[a] <= 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}
int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        slv();
}
	 							 			  	 		  			 	 	  	