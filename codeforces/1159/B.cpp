// AUTHOR: JAMES PHILIP GRIMARD
// GITHUB: github.com/jamesgrimard/codeforces
// PROBLEM: https://codeforces.com/problemset/problem/1159/B
// ----------------------------------------------------------------------------
// SOLUTION
// ----------------------------------------------------------------------------
#include <bits/stdc++.h>
 
using namespace std;  
                          
void solve() {        
                    
  int n; cin >> n;

  int a[n];
  for (int i=0;i<n;i++) cin >> a[i];                    

  int mn = -1, k;
  for (int i=0;i<n;i++) {
    (i < n/2) ? k = n-1 : k = 0;
    if (a[i] <= a[k]) {
      if (mn == -1) mn = a[i]/abs(k-i);
      mn = min(a[i]/abs(k-i) , mn);
    }
  }

  cout << mn << '\n';




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