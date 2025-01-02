//  /\_/\
// ( o.o ) -> kucenk
//  > ^ <
#include "bits/stdc++.h" 

using ll = long long;

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);		
  int tt;
  for (cin >> tt;tt;tt--) {
    string s;
    cin >> s;

    if(s[0]=='a'||s[1]=='b'||s[2]=='c'){
      cout << "YES" << '\n';
    }
    else{
      cout << "NO" << '\n';
    }
  }
  return 0;
}	