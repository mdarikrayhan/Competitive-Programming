#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long

template <class T>
using oset = tree<T, null_type, /*less->set less_equal-> multiset*/ less_equal<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;

bool isPrime(int n)
{
  for (int i = 2; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}
int mod = 1e9 + 7;
int power(int x, int y)
{
  int z = 1;

  x = x % mod;
  while (y > 0)
  {
    if (y & 1)
      z = (z * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return z;
}
int lcm(int a, int b)
{
  return (a * b) / __gcd(a, b);
}

bool so1(const pair<int, int> &a,
         const pair<int, int> &b)
{
  if (a.first != b.first)
    return (a.first > b.first);
  else
    return (a.second < b.second);
}

bool so2(const pair<int, int> &a,
         const pair<int, int> &b)
{
  if (a.first != b.first)
    return (a.first < b.first);
  else
    return (a.second > b.second);
}
int f(int n)
{
  int x=1;
  while(2*x<=n){
    x=2*x;
  }
  return x;
}

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--)
{
int n,k;
cin>>n>>k;
string s;
cin>>s;
if(k%2==1){
  for(int i=0;i<n;i++){
    if(s[i]=='0'){
      s[i]='1';
    }
    else{
      s[i]='0';
    }
  }
  int cnt=k;
  vector<int>v(n,0);
for(int i=0;i<n;i++){
if(s[i]=='0' && cnt>0){
  s[i]='1';
  cnt--;
  v[i]++;
}
  }
  v[n-1]+=cnt;
  if(cnt%2==1){
  if(s[n-1]=='0'){
   s[n-1]='1';
  }
  else{
    s[n-1]='0';
  }
  }
//   if(cnt==0){
//   cout<<s<<endl;
//   for(auto x:v){
//     cout<<x<<" ";
//   }
//   cout<<endl;
// }
// else{
  // if(v[n-1]==1){
  //   v[n-1]=cnt+1;
  // }
  // else{
  //   v[n-1]=cnt;
  // }
  // v[n-1]=cnt;
  // if(k%2==0){
    // v[n-1]++;
  // if(s[n-1]=='0'){
  //  s[n-1]='1';
  // }
  // else{
  //   s[n-1]='0';
  // }
// }
// else{
//   s[n-1]='1';
// }
cout<<s<<endl;
 for(auto x:v){
    cout<<x<<" ";
  }
  cout<<endl;
// }
}
else{
  int cnt=k;
  vector<int>v(n,0);
for(int i=0;i<n;i++){
if(s[i]=='0' && cnt>0){
  s[i]='1';
  cnt--;
  v[i]++;
}
// else if(s[i]=='1'){
//  continue;
// }
// else if(s[i]=='0' && cnt<=0){
//   s[i]='0';
// }
  }
  v[n-1]+=cnt;
  if(cnt%2==1){
    if(s[n-1]=='0'){
      s[n-1]='1';
    }
    else{
      s[n-1]='0';
    }
  }
//   if(cnt==0){
//   cout<<s<<endl;
//   for(auto x:v){
//     cout<<x<<" ";
//   }
//   cout<<endl;
// }
// else{
  //   if(v[n-1]==1){
  //   v[n-1]=cnt+1;
  // }
  // else{
  //   v[n-1]=cnt;
  // }
  // if(s[n-1]=='1'){
  //   s[n-1]='0';
  // }
  // else{
  //   s[n-1]='1';
  // }
  // v[n-1]=cnt;
//   if(v[n-1]%2==0){
//     // v[n-1]++;
//   if(s[n-1]='0'){
//    s[n-1]='1';
//   }
//   else{
//     s[n-1]='0';
//   }
// }
cout<<s<<endl;
 for(auto x:v){
    cout<<x<<" ";
  }
  cout<<endl;
// }
}
}
}




