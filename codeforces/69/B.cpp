#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , m ; cin >> n >> m;
    vector<int> l(m),r(m) ,t(m) , c(m) ;

    for(int i=0;i<m;i++)
    {
        cin >> l[i] >> r[i] >> t[i] >> c[i] ;
    }

    vector<int> profit(n+1, 0);
    vector<int> time(n+1, INT_MAX);

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = l[i]; j <= r[i]; j++)
        {
            if(t[i] < time[j])
            {
                time[j] = t[i];
                profit[j] = c[i];
            }
        }
    }

    int ans = accumulate(profit.begin(), profit.end(), 0);

    cout << ans ;

    return 0;
}
