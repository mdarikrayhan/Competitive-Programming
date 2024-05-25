#include <bits/stdc++.h>
using namespace std;

int n, p[100000], d[100000], m, k0, k1, h[100000], p0, p1;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int c0 = 0; c0 < n; c0++)
    cin >> p[c0];
    
  d[0] = m = 1;
  for (int c0 = 1; c0 < n; c0++){
    if (p[c0] > p[c0 - 1])
      d[c0] = d[c0 - 1] + 1;
    else
      d[c0] = 1;
      
    m = max(m, d[c0]);
  }
  
  h[n - 1] = 1;
  for (int c0 = n - 2; c0 >= 0; c0--){
    if (p[c0] > p[c0 + 1])
      h[c0] = h[c0 + 1] + 1;
    else
      h[c0] = 1;
    
    m = max(m, h[c0]);
  }
  
  k0 = k1 = 0;
  for (int c0 = 0; c0 < n; c0++){
    if (d[c0] == m){
      k0++;
      p0 = c0;
    }
    
    if (h[c0] == m){
      k1++;
      p1 = c0;
    }
  }
  
  if (k0 != 1 || k1 != 1 || p0 != p1 || m % 2 == 0){
    cout << "0\n";
    return 0;
  }
  
  cout << "1\n";
}