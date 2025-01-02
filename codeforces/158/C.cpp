#include <bits/stdc++.h>
using namespace std;
#define ll long long
void Naruto()
{
  int q;
  cin >> q;
  vector<string> st, ans;
  string cur = "";
  while(q--){
    string s;
    cin >> s;
    if(s == "pwd"){
      for(int i = 0; i < ans.size(); i++)
        cout << '/' << ans[i];
      cout << "/" << '\n';
    }
    else{
      string t;
      cin >> t;
      if(t[0] == '/')
        ans.clear();
      string temp;
      for(int i = 0; i < t.size(); i++){
        if(t[i] == '/' && !temp.empty()){
          if(temp == "..")
            ans.pop_back();
          else
            ans.push_back(temp);
          temp.clear();
        }
        else if(t[i] != '/')
          temp.push_back(t[i]);
      }
      if(!temp.empty()){
        if(temp == "..")
          ans.pop_back();
        else
          ans.push_back(temp);
        temp.clear();
      }
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int tt = 1; // cin >> tt;
  while (tt--) Naruto();
}
