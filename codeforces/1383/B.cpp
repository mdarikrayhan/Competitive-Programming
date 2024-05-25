#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// #define MAXN 10000001
const int mod = 1e9 + 7;

int binpow(int a, int b, int m)
{
  int res = 1;
  a = a % m;
  while (b != 0)
  {
    if (b & 1)
    {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}



void solve()
{

  int n;
 cin>>n;

  vector<int> cnt(32,0);

  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    for(int j=0;j<32;j++){
      cnt[j]+= ((x>>j)&1);
    }
  }

  for(int i=31;i>=0;i--){
    if(cnt[i]%2){
      int one = cnt[i],zero = n - cnt[i];
      if((one%4)==3 && (zero%2)==0){
          cout<<"LOSE";
          cout<<endl;
          return;
      }
      else if((one%4)==2){
          cout<<"DRAW";
          cout<<endl;
          return;
      }
      else{
        cout<<"WIN";
        cout<<endl;
        return;
      }

    }
  }

  cout<<"DRAW"<<endl;
  return;
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;

  while (t-- != 0)
  {

    solve();
  }
  return 0;
}