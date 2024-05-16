#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int idex = 1;
    int ok = 0;
    for (int i = 1; i < n;i++)
    {
      if(s[i]<s[i-1])
        ok = 1;
      if(s[i]>s[i-1])
      {
        break;
      }
      if(s[i]==s[i-1])
      {
        if(!ok)
          break;
      }
      idex++;
    }
    //if(idex&&s[idex]<s[idex-1])
    //  idex++;
    string t(s.begin(), s.begin() + idex);
    cout << t;
    reverse(t.begin(), t.end());
    cout << t << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}