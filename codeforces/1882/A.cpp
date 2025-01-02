#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            int x=b[i-1]+1;
            if(x==a[i]) x++;
            b[i]=x;
        }
        cout<<b[n]<<endl;
    }
    return 0;
}