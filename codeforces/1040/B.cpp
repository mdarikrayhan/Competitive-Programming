// AUTHOR: JAMES PHILIP GRIMARD
// GITHUB: github.com/jamesgrimard/codeforces
// PROBLEM: https://codeforces.com/problemset/problem/1040/B
// ----------------------------------------------------------------------------
// SOLUTION
// ----------------------------------------------------------------------------
#include <bits/stdc++.h>
 
using namespace std;  
                          
void solve() {        

  int n , k; cin >> n >> k;

  vector<int> v;

  int p = n % (k * 2 + 1) ;
  (p > k || !p) ? p = 0 : p = k + 1 - p;
    
  for (int i=(k+1)-p;i<=n;i+=(2*k+1)) {
    v.push_back(min(n,i));
  }

  if (v.empty()) v.push_back(n);

  cout << v.size() << '\n';
  for (auto &i : v) cout << i << " ";

          
    

    

                                                                  
}
    
int main() {
  ios::sync_with_stdio(false);cin.tie(0);cout.tie();
  
  solve();
  
  return 0;
}
// ----------------------------------------------------------------------------
// NOTES
// ----------------------------------------------------------------------------
/*
 
*/