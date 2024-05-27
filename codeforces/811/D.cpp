#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// #define endl '\n' //comment for interactive
#define PI acos(-1.0)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<vector<ll>> vvll;
typedef pair<ll,ll> pll;

const ll mod=(ll)1000000007;

// My custom power function
ll powr(ll a,ll n)
{
    if(n==0)return 1LL;
    if(n%2==0)return powr(a*a%mod,n/2LL);
    else return a*powr(a,n-1LL)%mod;
}
ll inv(ll a,ll mod)
{
    return (powr(a,mod-2))%mod;
}

// Gets prime numbers upto sqrt(N)
void sieve(vector<ll>&answer,int n)
{
    n=sqrtl(n)+2;
    vector<bool>prime(n + 1,true);
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<n+1;i++)
    {
        if(prime[i])
        {
            answer.push_back(i);
        }
    } 
}
ll n,m,z;
string ans;
bool valid(ll x,ll y)
{
    return (x>=0&&x<n&&y>=0&&y<m);
}
void dfs(ll x,ll y,vector<vector<char>>&v,vector<vector<ll>>&vis)
{
    if(vis[x][y])
    return;
    vis[x][y]=1;
    if(v[x][y]=='F')
    {
        z=1;
        return;
    }
    else if(v[x][y]=='*')
    {
        return;
    }
    if(valid(x+1,y))
    {
        ans.push_back('D');
        dfs(x+1,y,v,vis);
        if(z==1)
        return;
        ans.pop_back();
    }
    if(valid(x-1,y))
    {
        ans.push_back('U');
        dfs(x-1,y,v,vis);
        if(z==1)
        return;
        ans.pop_back();
    }
    if(valid(x,y+1))
    {
        ans.push_back('R');
        dfs(x,y+1,v,vis);
        if(z==1)
        return;
        ans.pop_back();
    }
    if(valid(x,y-1))
    {
        ans.push_back('L');
        dfs(x,y-1,v,vis);
        if(z==1)
        return;
        ans.pop_back();
    }
}
void solve()
{
    z=0;
    cin >> n >> m;
    vector<vector<char>>v(n,vector<char>(m));
    for(auto&j:v)
    {
        for(auto&i:j)
        {
            cin >> i;
        }
    }
    ans="";
    vector<vector<ll>>vis(n,vector<ll>(m,0));
    dfs(0,0,v,vis);
    char left,right,up,down;
    left='L';
    right='R';
    up='U';
    down='D';
    ll x=1,y=1,a,b,ptr=0;
    char c=ans[0];
    cout << c << endl;
    cin >> a >> b;
    if(ans[0]=='R')
    {
        if(a==1&&b==1)
        {
            swap(left,right);
        }
        else
        {
            ptr++;
            x=a,y=b;
        }
    }
    else if(ans[0]=='D')
    {
        if(a==1&&b==1)
        {
            swap(up,down);
        }
        else
        {
            ptr++;
            x=a,y=b;
        }
    }
    for(;ptr<ans.size();ptr++)
    {
        if(ans[ptr]!=c)
        break;
        else
        {
            if(c=='L')
            cout << left << endl;
            else if(c=='R')
            cout << right << endl;
            else if(c=='U')
            cout << up << endl;
            else
            cout << down << endl;
            cin >> a >> b;
            x=a,y=b;
        }
    }
    if(ptr==ans.size())
    {
        return;
    }
    cout << ans[ptr] << endl;
    cin >> a >> b;
    if(ans[ptr]=='R')
    {
        y++;
        if(x==a&&y==b)
        {
            ptr++;
        }
        else
        {
            swap(left,right);
        }
    }
    else if(ans[ptr]=='D')
    {
        x++;
        if(x==a&&y==b)
        {
            ptr++;
        }
        else
        {
            swap(up,down);
        }
    }
    for(;ptr<ans.size();ptr++)
    {
        c=ans[ptr];
        if(c=='L')
        cout << left << endl;
        else if(c=='R')
        cout << right << endl;
        else if(c=='U')
        cout << up << endl;
        else
        cout << down << endl;
        cin >> a >> b;
        x=a,y=b;
    }
}
void solveTestcases()
{
    ll t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solveTestcases();
    return 0;
}