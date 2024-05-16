/*
  _____     _           _
 |  ___|_ _(_)___  __ _| |
 | |_ / _` | / __|/ _` | |
 |  _| (_| | \__ \ (_| | |
 |_|  \__,_|_|___/\__,_|_|
  _   _
 | | | | ___   __ _ _   _  ___
 | |_| |/ _ \ / _` | | | |/ _ \
 |  _  | (_) | (_| | |_| |  __/
 |_| |_|\___/ \__, |\__,_|\___|
                 |_|
  ____  _  __       _
 |  _ \(_)/ _| __ _| |_
 | |_) | | |_ / _` | __|
 |  _ <| |  _| (_| | |_
 |_| \_\_|_|  \__,_|\__|

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long



/*int lcm(int x,int y)
{
    return (x * 1LL * y) / __gcd(x,y);
}*/

void solve()
{
        int n; 
        cin >> n;
        vector<int>arr(n);
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
        }
        int cnt1 = count(arr.begin(), arr.end(), 1);
        int cnt2 = count(arr.begin(), arr.end(), 2);
       if(cnt1 == 0)
        {
            for(int i = 0; i<n; i++)
            {
                cout<<2<<" ";
            }
            cout<<endl;
        }
        else if(cnt2 == 0)
        {
            for(int i = 0; i<n; i++)
            {
                cout<<1<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<2<<" "<<1<<" ";
            for(int i = 1; i<cnt2; i++)
            {
                cout<<2<<" ";
            }
            for(int i = 1; i<cnt1; i++)
            {
                cout<<1<<" ";
            }
            cout<<endl;
        }
}
int main()
{
    int test = 1;
    //cin >> test;
    while (test--)
    {
        solve();
    }

    return 0;
}