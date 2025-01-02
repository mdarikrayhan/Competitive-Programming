#include<bits/stdc++.h>
#define t int t;cin>>t;while (t--)
#define ll long long
#define all(x) begin(x),end(x)
#define endl "\n"
using namespace std;
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    cin>>a;
    vector<ll> b(n);
    cin>>b;
    ll m;
    cin>>m;
    vector<ll> d(m);
    cin>>d;
    // std::vector<ll>::iterator it;
    vector<pair<ll,ll>> dif;
    for (ll i = 0; i < n; i++)
    {
        if (a[i]!=b[i])
        {
            dif.push_back(make_pair(a[i],b[i]));
        }
    }
    if (m<dif.size())
    {
        cout<<"NO"<<endl;
        return;
    }
    vector<ll> f(dif.size());
    for (ll i = 0; i < dif.size(); i++)
    {
        f[i]=dif[i].second;
    }
    // cout<<f<<endl;
    // for (ll i = 0; i < b.size(); i++)
    // {
    //     it = std::find(b.begin(),b.end(),d[m-1]);
    //     if (it==b.end())
    //     {
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }
    // for (ll i = 0; i < f.size(); i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         if (f[i]==d[j])
    //         {
    //             d[j]=-1;
    //             break;
    //         }
    //     }
        
    // }
    // int con=0;
    // for (ll i = 0; i < m; i++)
    // {
    //     if (d[i]==-1)
    //     {
    //         con++;
    //     }
    // }
    // if (con!=f.size())
    // {
    //     cout<<"NO"<<endl;
    //     return;
    // }
    // else cout<<"YES"<<endl;
    map<ll,ll> J;
    for (ll i = 0; i < f.size(); i++)
    {
        if (J.find(f[i])==J.end())
        {
            J[f[i]]=1;
        }
        else
        J[f[i]]+=1;
    }
    map<ll,ll> P;
    for (ll i = 0; i < m; i++)
    {
        if (P.find(d[i])==P.end())
        {
            P[d[i]]=1;
        }
        else
        P[d[i]]++;
    }
    map<ll,ll> S;
    for (ll i = 0; i < n; i++)
    {
        if (S.find(b[i])==S.end())
        {
            S[b[i]]=1;
        }
        else
        S[b[i]]++;
    }
    if (S.find(d[m-1])==S.end())
    {
        cout<<"NO"<<endl;
        return;
    }
    for(auto& it:J)
    {
        if (J[it.first]>P[it.first])
        {
            cout<<"NO"<<endl;
            return;
        }
        
    }
    cout<<"YES"<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    t
    {
     solve();
    }
 return 0;
}
