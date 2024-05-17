#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) x.begin(), x.end()
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define s second
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fast   \
  cin.tie(0);  \
  cout.tie(0); \
  ios::sync_with_stdio(0);
using namespace __gnu_pbds;
using namespace std;
ll t, n, m , k ;
int main()
{
  fast;
  cin >> t;
  while (t--)
  {
    cin >> n >> m >> k ;
    vector<ll> v(k+1,0),a(k+1);
    for(int i = 1 ; i<= k ; i++)
    {
      cin >> v[i] ; 
    } 
    sort(all(v)) ;
    a=v;
    ll ans1 = 0 , ans2 = 0 ;
    ll nn = n , mm = m ; 
    bool f=0;
    if((n%2&&m*3<=v[k])||n%2==0)
    {
      if(n%2) v[k]-=(m*3) , n-=3 ;
      for(int i = 1 ; i<=k ;i++)
      {
        if(v[i]/m>=2) ans1+= (v[i]/m); 
      }
      if(ans1>=n) f=1;
    }
    if((mm%2&&nn*3<=a[k])||mm%2==0)
    {
      if(mm%2) a[k]-=(nn*3) , mm-=3 ;
      
      for(int i = 1 ; i<=k ;i++)
      {
        if(v[i]/nn>=2) ans2+= (a[i]/nn) ; 
      }
      if(ans2>=mm) f=1;
    }
    if(f) yes else no ; 
  }
}