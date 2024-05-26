#include <bits/stdc++.h>
#define GO cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
using namespace std;
const long long INF=1e16;
const ll N = 1e5 +7;
ll mod= 1e9+7;

int main()
{
    //GO
    ll tt = 1;
    cin >> tt;
    while (tt--)
    {
        ll n,m,x,y; cin>>n>>m>>x>>y;
        vector<pair<ll,ll>> vp;

        vector<ll> mn[123], pos[123];

        for(ll i=0;i<x;i++){
            ll f, s; cin>>f>>s;
            vp.push_back({f, s});
        }

        for(ll i=0;i<y;i++){
            char c; ll s; cin>>c>>s;
            pos[c].push_back(s);
            mn[c].push_back(i);
        }

        for(ll i=1;i<pos['U'].size();i++) pos['U'][i] += pos['U'][i-1];
        for(ll i=1;i<pos['D'].size();i++) pos['D'][i] += pos['D'][i-1];
        for(ll i=1;i<pos['L'].size();i++) pos['L'][i] += pos['L'][i-1];
        for(ll i=1;i<pos['R'].size();i++) pos['R'][i] += pos['R'][i-1];

        ll al = 0, bo = 0;

        for(ll i=0;i<x;i++){
            ll xx = vp[i].first, yy = vp[i].second;

            ll mini = 1e18;

            ll comp = 1e18;
            ll idx = lower_bound(pos['U'].begin(), pos['U'].end(), xx) - pos['U'].begin();
            if(idx < pos['U'].size()) comp = mn['U'][idx];
            mini = min(mini, comp);

            comp = 1e18;
            idx = lower_bound(pos['L'].begin(), pos['L'].end(), yy) - pos['L'].begin();
            if(idx < pos['L'].size()) comp = mn['L'][idx];
            mini = min(mini, comp);

            comp = 1e18;
            idx = lower_bound(pos['D'].begin(), pos['D'].end(), n+1-xx) - pos['D'].begin();
            if(idx < pos['D'].size()) comp = mn['D'][idx];
            mini = min(mini, comp);

            comp = 1e18;
            idx = lower_bound(pos['R'].begin(), pos['R'].end(), m+1-yy) - pos['R'].begin();
            if(idx < pos['R'].size()) comp = mn['R'][idx];
            mini = min(mini, comp);

            if(mini == 1e18) continue;
            if(mini%2 == 0) al++;
            else bo++;
        }

        cout<<al<<' '<<bo<<endl;


    }
}
