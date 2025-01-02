#include <bits/stdc++.h>
using namespace std;
#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void mySoln()
{
    int n,p;
    cin >> n >> p;
    vector<pair<ll,ll>> ar(n);
    
    for(int i = 0 ; i < n ; i++)
    {
        cin >> ar[i].second;
    }

    for(int i = 0 ; i < n ; i++)
    {
        cin >> ar[i].first;
    }

    sort(ar.begin(),ar.end());
    ll cnt = 1;
    ll ans = p;
    for(int i = 0 ; i < n and ar[i].first < p ; i++)
    {
        ans += ar[i].first*min(n-cnt,ar[i].second);
        cnt += min(n-cnt,ar[i].second);
    }
    ans += p*(n-cnt);
    cout<<ans<<"\n";
}

int main()
{
    UNSYNC
    int t;
    cin >> t;
    while(t--)
    {
        mySoln();
    }
    
    return 0;
    
}