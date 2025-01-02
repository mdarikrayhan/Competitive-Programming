#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  if(n==2)
  {
    cout<<1<<endl;
    return;
  }
  vector<int>ans(n-1);
  ans[0]=1;
  for (int i = 1; i < n-1; i++)
  {
    if(s[i]==s[i-1])
    {
       ans[i]=ans[i-1];
    }
    else ans[i]=i+1;
  }

  for(auto x:ans)
  {
    cout<<x<<" ";
  }
  cout<<endl;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}