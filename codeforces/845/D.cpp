#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define sz(x) x.size()

using namespace std;

int n;

vector<pii> vt_1;
vector<int> vt_2;

int solve_1(vector<pii> vt)
{
     int ans = 0, res;
     stack<int> st;
     st.push(INT_MAX);
     for (pii it : vt)
     {
          if (it.first == 1)
          {
               res = it.second;
               while (res > st.top())
               {
                    ans++;
                    st.pop();
               }
          } else if (it.first == 3)
          {
               if (res > it.second)
                    ans ++;
               else st.push(it.second);
          } else
          {
               while (sz(st) > 1)
                    st.pop();
          }
     }



     return ans;

}

int solve_2(vector<int> vt)
{
     vt.push_back(4);
     int freq[sz(vt) + 7];
     int pos = 0, ans = 0;


     freq[sz(vt)] = 0;
     for (int i = sz(vt) - 1; i >= 0; --i)
     {
          freq[i] = (vt[i] == 2) + freq[i + 1];
          if (vt[i] == 4)
               pos = i;
          else if (vt[i] == 6)
          {
               if (freq[i] - freq[pos] > 0)
                    ans++;
          }
     }
     return ans;
}

void solve()
{
     cin >> n;
     for (int i = 1; i <= n; ++i)
     {
          int t;    cin >> t;
          if (t % 2)
          {
               int s = 0;
               if (t == 1 || t == 3)
                    cin >> s;
               vt_1.push_back({t, s});
          } else
               vt_2.push_back(t);
     }

     int ans = solve_1(vt_1);
     ans += solve_2(vt_2);
     cout << ans;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     int t = 1;//     cin >> t;
     while (t--)
          solve();
}