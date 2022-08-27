#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     int T;
     cin>>T;
     while(T--)
    {
        string ______, _______________;
        cin >> ______ >> _______________;
        set<char> f;
        for (int i = 0; i < ______.size(); i++)
        {
            f.insert(______[i]);
        }
        for (int i = 0; i < _______________.size(); i++)
        {
            f.insert(_______________[i]);
        }
        cout<<f.size()-1<<nl;
    }
    return 0;
}