#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define int long long
#define ld long double
#define endl "\n"
#define FOCUS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void Go() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main() {
    Go();
    ll n;
    cin>>n;
    vector<pair<ll,ll>>v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
        if(v[i].first>v[i].second)swap(v[i].first,v[i].second);
    }
    sort(v.begin(),v.end());
    vector<ll>ans;
    ll start=-2e9;
    for(int i=0;i<n;i++)
    {
        if(v[i].first>start)
        {
            if(start!=-2e9)
            ans.push_back(start);
            start=v[i].second;
        }
        else
        {
            start=min(v[i].second,start);
        }
    }
    ans.push_back(start);
    cout<<ans.size()<<endl;
    for(auto it:ans)
        cout<<it<<" ";

    return 0;
}