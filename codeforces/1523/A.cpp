#include <bits/stdc++.h>
using namespace std;
int main(){
 int tt;
 cin >> tt;
 while (tt--){
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for (int i = 0; i < min(n, m); i++){
   auto t = s;
   for (int j = 0; j < n; j++){
    if (s[j] == '0'){
     int cnt = 0;
     if (j > 0)
      cnt += s[j - 1] - '0';
     if (j < n - 1)
      cnt += s[j + 1] - '0';
     if (cnt == 1)
      t[j] = '1';
    }
   }
   swap(s, t);
  }
  cout << s << "\n";
 }
}