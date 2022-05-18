#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int a=0,b=0,c=0;
void solve()
{
    int x,y,z;
    cin >> x >> y >> z;
    a+=x;
    b+=y;
    c+=z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    if(a==0&&b==0&&c==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}