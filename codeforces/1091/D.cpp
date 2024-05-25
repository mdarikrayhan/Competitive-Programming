#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hayai                       \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"

int32_t main()
{
  hayai;
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int mod  = 998244353;
    if(n==1){
      cout << 1 << "\n";
      continue;
    }
    int k = n-1;
    int ans=0;
    int i =1;
    while(k){
      if(k!=1)
      ans= (ans+(( ((n%mod)*((k-1)%mod))%mod)*(i%mod))%mod)%mod;
      else
      ans= (ans+ ((n%mod)*((k)%mod))%mod)%mod;
      i++;
      n=((n)%mod*(k)%mod)%mod;
      k--;
    }
    cout << ans << "\n";
  }
}