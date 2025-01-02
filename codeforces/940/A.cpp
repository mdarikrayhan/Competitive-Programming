#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = -1;
    for(int i = 0 ; i < n; i++)
    {
        int count = 0;
        for(int j = i; j < n; j++)
        {
            if(v[j] - v[i] <= d)
            {
                count++;
            }
        }
        ans = max(count, ans);
    }
    cout << n - ans << endl;
}
int main()
{
    int t;
    //cin >> t;
    //while(t--)
        solve();
}


	 					 	 			    		 		 				 	 	