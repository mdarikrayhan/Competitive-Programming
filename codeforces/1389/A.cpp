#include <bits/stdc++.h>
#include<numeric>

using namespace std;
const char nl = '\n';
void solve()
{
 
        long long int l,r;
        cin>>l>>r;
        if(r%2==0)
        {
            if(r/2>=l)
                cout<<r/2<<' '<<r;
            else
                cout<<-1<<' '<<-1;
        }
        else
        {
            if(r/2>=l)
                cout<<r/2<<' '<<r-1;
            else
                cout<<-1<<' '<<-1;
        }
 
        cout<<'\n';
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
    return 0;
}