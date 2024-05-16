/*

*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n;

void solve()
{
    lt d=9;
    string c;
    //while (n>9||(n!=1&&n<9&&n>=d))
    while (n>=d&&n!=1)
    {
        c+=d+'0';
        n-=d;
        d-=1;
    }
    if (n) c+=n+'0';
    reverse(begin(c),end(c));
    printf("%s\n",c.c_str());
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    lt t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        solve();
    }
}
