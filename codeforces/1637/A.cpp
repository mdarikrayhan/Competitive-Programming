#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int a;
    cin >> a;
    vector<int> vec1;
    vector<int> vec2;
    for (int i = 0; i < a; i++)
    {
        int p;cin>>p;
        vec1.push_back(p);
        vec2.push_back(p);
    }
    sort(vec2.begin(),vec2.end());
    if(vec1==vec2){
        cout<<"NO"<<nl;
    }
    else{
        cout<<"YES"<<nl;
    }
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