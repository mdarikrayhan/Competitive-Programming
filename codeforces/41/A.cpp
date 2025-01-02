#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size()!=s2.size()){
        cout<<"NO"<<endl;
        return;
    }
    int n=s1.size();
    for(int i=0;i<n;i++){
        if(s2[i]!=s1[n-1-i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}

// g++ -std=c++11 -O2 -Wall code.cpp -o code
