#include<bits/stdc++.h>
#define int long long
#define ll long long
#define dl double
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sp " "
#define fi "\n"
#define ld long double
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int ncr(int n,int r)
{
    int res=1;
    int rf=1;
    for(int i=r+1;i<=n;i++)
    {
        res*=i;
        res/=rf;
        rf++;
    }
    return res;
}
int npr(int n,int r)
{
    int res=1;
    for(int i=n-r+1;i<=n;i++)
    {
        res*=i;
    }
    return res;
}
void file()
{
    //freopen("limited.in", "r", stdin);
    //freopen("output.in", "w", stdout);
}
void solve()
{
   string s,t;cin>>s>>t;
   bool x=0,y=1;
   int a=0,b=0;
   while(a<s.size())
    {
        if(b<t.size() && s[a]==t[b])
        {
            b++;
        }
        a++;
    }
    if(b==t.size())
        x=1;
    map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }
    for(int i=0;i<t.size();i++)
    {
        mp[t[i]]--;
        if(mp[t[i]]<0)
            y=0;
    }
    if(x || y)
    {
        if(x)
            cout<<"automaton";
        else if(t.size()==s.size())
            cout<<"array";
        else cout<<"both";
    }
    else cout<<"need tree";
}
signed main()
{
    file();
    fast();
    int off=1;
    //cin>>off;
    while(off--)
    {
        solve();
    }
}