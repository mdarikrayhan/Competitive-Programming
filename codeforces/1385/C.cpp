#include<bits/stdc++.h>
using namespace std;

#define nline     "\n"
#define all(x)       (x).begin(), (x).end()
#define input(v)  for (auto &i : v) cin >> i;
#define print(v)  for (auto &j : v) cout << j<<" ";
#define FAST()       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

void solve(int);
void precal();

int32_t main()
{
   FAST();
   cout << fixed;
   cout << setprecision(15);
   precal();
   int t = 1;
   cin>>t;
   for (int i = 1; i <= t; i++)
   {
      solve(i);
      cout << nline;
   }
}

void precal()
{
  
}

ll nxt() 
{
    ll x;
    cin >> x;
    return x;
}

void solve(int kase)
{
  ll n=nxt(),i1=0,i2=0;
  vector<ll> v(n);
  input(v);
  for(int i=n-1;i>0;i--)
  {
    if(v[i]>v[i-1])
    {
        i2=i-1;
        break;
    }
  }
  if(i2==0)
  {
    cout<<0;
  }
  else
  {
    for(int i=0;i<i2;i++)
    {
        if(v[i]>v[i+1])
        {
            i1=i+1;
        }
    }
    cout<<i1;
  }
}