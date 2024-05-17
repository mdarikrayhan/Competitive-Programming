#include <bits/stdc++.h>
using namespace std;
#define ll long long
void Naruto()
{
  string s, ans = "";
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == ans.back())
      ans.pop_back();
    else
      ans.push_back(s[i]);
  }
  cout << ans;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int tt = 1; // cin >> tt;
  while (tt--) Naruto();
}
