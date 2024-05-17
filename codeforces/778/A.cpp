






/*Fir Aa Gya Tu Code Dekhne*/









#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define pb push_back
#define pp pop_back
#define f(i,a,n) for(ll i = a; i < n ; i++)
#define in(a,n) for (ll i = 0; i < n; i++) cin >> a[i]
#define out(a,n) for (ll i = 0; i < n; i++) cout << a[i] << 

#define vin(v,n) f(i,0,n){ll a;cin >> a;a--;v.pb(a);}
#define lb(a)  lower_bound(v.begin(),v.end(),a)
#define ub(a)  upper_bound(v.begin(),v.end(),a)
#define fi first
#define se second
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define trav(v) for (auto it = v.begin(); it != v.end(); it++)
bool issubsequence(string& p, string& s)
{
    ll n = p.length(), m = s.length();
    ll i = 0, j = 0;
    while (i < n && j < m) {
        if (p[i] == s[j])
        {
            i++;
        }
        j++;
    }

    return i == n;
}
bool solve(ll mid, vll v, vector<pair<char,ll>> s, string p)
{
    string t;
    unordered_set<ll> check;
    f(i,0,mid)
    {
        check.insert(v[i]);
    }
    f(i,0,s.size())
    {
        if (check.find(s[i].se) == check.end())
        {
            t.pb(s[i].fi);
        }
        
    }
    if (issubsequence(p,t))
    {
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        string s1;
        string p;
        cin >> s1>> p;
        vector<pair<char,ll>> s;
        f(i,0,s1.size())
        {
            s.pb({s1[i],i});
        }  
        vll v;
        vin(v, s.size());
        ll l = 0;
        ll r = s.size();
        ll mid;
        while (r - l > 1)
        {
            mid = l + (r - l) / 2;
            if (solve(mid, v, s, p))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        cout << l;
    }
    return 0;
}