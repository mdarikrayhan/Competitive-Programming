#include <bits/stdc++.h>
using namespace std ;
#define read freopen("input.txt", "r", stdin);
#define write freopen("s1.txt", "w", stdout);
#define ll long long
#define ld long double
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  test  ll t; cin>>t; while(t--)
#define yen(f) if(f) {cout<<"YES"<<'\n';} else {cout<<"NO"<<'\n';}
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (abs((a*b))/ gcd(a,b)); }
#define Num_of_Digits(n) ((int)log10(n) + 1)
const unsigned ll N = 2e6 + 5;
bool cmb( pair<ll,ll>s1,pair<ll,ll>s2)
{
    if(s1.second==s2.second)
    {
        if(s1.first>s2.first)
        {

            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(s1.second<s2.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

ll QuadraticFormula(ll a,ll b,ll c)
{

    ll x1=-((b- sqrt((b*b)-(4*a*c)))/(2*a));
    ll x2=-((b+ sqrt((b*b)-(4*a*c)))/(2*a));
    return max(x1,x2);
}
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
char di[] = {'D', 'L', 'U', 'R'};

vector<ll>adj[N];
vector<bool>vis(N, false);
vector<bool>mark(N, false);


vector<ll> solve(vector<ll>& nums)
{
    vector<ll>pr(nums.size(),0),sf(nums.size(),0),ans;
    pr[0]=nums[0];
    sf[nums.size()-1]=nums.back();
    for(int i=1;i<nums.size();i++)
    {
        pr[i]=gcd(pr[i-1],nums[i]);
    }
    for(int i=nums.size()-2;i>=0;i--)
    {
        sf[i]=gcd(sf[i+1],nums[i]);
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if(!i)
        {
            ans.push_back(sf[1]);
        }
        else if(i==nums.size()-1)
        {
            ans.push_back(pr[pr.size()-2]);
        }
        else
        {
            ans.push_back(gcd(pr[i-1],sf[i+1]));
        }
    }

    return ans;


}
ll M=1e9+7;
ll mul(ll a,ll b,ll m)
{
    return ((a%m)*(b%m))%m;
}
ll modularExponentiation(ll x,ll n,ll m)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1){result=mul(result,x,m);}
        x=mul(x,x,m);
        n=n/2;
    }
    return result;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fast
    ll n,mn=INT_MAX;
    cin>>n;
    vector<ll>arr(n),pr(n,0),sf(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    if(arr[0]>=0)
    {
        pr[0]=1;
    }
    if(arr[n-1]<=0)
    {
        sf[n-1]=1;
    }
    for (int i = 1; i <n ; ++i)
    {
        pr[i]=pr[i-1]+(arr[i]>=0);
    }
    for (int i = n-2; i >=0 ; i--)
    {
        sf[i]=sf[i+1]+(arr[i]<=0);
    }
    for (int i = 0; i < n-1; ++i)
    {
        mn=min(mn,pr[i]+sf[i+1]);
    }

    cout<<mn<<'\n';

    return 0;
}