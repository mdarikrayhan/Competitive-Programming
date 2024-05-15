#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define p(a) cout << a << "\n";
#define p2(a, b) cout << a << " " << b << "\n";
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define pb push_back
#define pf push_front
 
void solve()
{
  int k;
  cin>>k;
  string s;
  cin>>s;
  string s1="";
  map<char,int>mpp;

  for(int i=0;i<s.size();i++){
    mpp[s[i]]++;
  }

  for(auto it : mpp){
  if(it.second%k!=0){
    cout<<-1;
    return;
  }

  }
  for(auto it: mpp){
  for(int i=0;i<it.second/k;i++){
    s1.push_back(it.first);
  }
   }

  for(int i=0;i<k;i++){
    cout<<s1;
  }

}
 
int main(void)
{
//   fastio;
//   ll t;
//   cin >> t;
//   while (t--)
//   {
    solve();
//   }
  return 0;
}