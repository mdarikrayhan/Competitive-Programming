#include <bits/stdc++.h>
// ordered set;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define o_multiset tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update>

#define o_set tree<long long, null_type, greater<long long>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
const ll mod = 1000000007;

// bool cmp(string x, string y)
// {
//     return int(x[0]) < int(y[0]);
// }

// map<ll, vector<ll>> edge;
// ll reached[2][200001] = {0};
// ll ar[2][200001] = {0};
// // ll ar[2][200001] = {0};
// void dfs(ll i, ll j, ll n)
// {
//     if (i < 2 && i > -1 && j < n && j >= 0 && reached[i][j] == 0)
//     {
//         // cout<<i<<" "<<j<<"\n";
//         reached[i][j] = 1;
//         if (i - 1 >= 0)
//         {
//             ////reached[i-1][j] =1;
//             dfs(i - 1, j + ar[i - 1][j], n);
//         }
//         if (i + 1 < 2)
//         {
//             // reached[i+1][j] =1;
//             dfs(i + 1, j + ar[i + 1][j], n);
//         }
//         if (j - 1 >= 0)
//         {
//             ////reached[i][j-1] =1;
//             dfs(i, j - 1 + ar[i][j - 1], n);
//         }
//         if (j + 1 < n)
//         {
//             // reached[i][j+1]=1;
//             dfs(i, j + 1 + ar[i][j + 1], n);
//         }
//     }
// }

// ll check(ll n)
// {
//     ll ans =0;
//     while(n>=0)
//     {
//         ans+=n%2;
//         n/=2;
//     }
//     return ans;
// }
// vector<ll> v;
// ll ar[14] = {1,2,6,24,120,720,720*7,720*7*8,720*7*8*9,720*7*8*9*10,720*7*8*9*10*11,720*7*8*9*10*11*12,720*7*8*9*10*11*12*13,720*7*8*9*10*11*12*13*14};
// void subsetSums(ll arr[], ll l, ll r, ll sum )
// {
//     // Print current subset
//     if (l > r) {
//         v.push_back(sum);
//         return;
//     }

//     // Subset including arr[l]
//     subsetSums(arr, l + 1, r, sum + arr[l]);

//     // Subset excluding arr[l]
//     subsetSums(arr, l + 1, r, sum);
// }

// ll factmod(ll x,ll p)
// {
//     if(x==0)
//     {
//         return 1%p;
//     }
//     ll ans = 1;
//     while(x>0)
//     {

//         ans*=(x%p);
//         ans%=p;
//         x--;
//     }

//     return ans%p;
// }

// ll power(ll a, ll b,ll m) {
//    a %= m;
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }

// ll modinv(ll a,ll m) {
//   return power(a,m-2,m);
// }

void solve(ll t)
{
    ll k,a,b;
    cin>>k>>a>>b;
    if(a<=0&&b>=0)
    {
        cout<<(-a)/k+b/k+1<<"\n";
        return;
    }

    if(a<0&&b<0)
    {
        a = -a;
        b = -b;
    }

    cout<<max(a,b)/k-(min(a,b)-1)/k<<"\n";


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    //cin >> t;
    t = 1;

    // vector<ll> sieve(1000002,0);
    //  for(int i =2;i<=sqrt(1000002);i++)
    //  {
    //      if(sieve[i]==0)
    //      {
    //          for(int j =i*i;j<1000002;j+=i)
    //          {
    //              sieve[j] =i;
    //          }
    //      }

    //  }
    for (int re = 0; re < t; re++)
    {
        solve(re);
    }
}

