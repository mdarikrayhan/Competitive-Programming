#include <bits/stdc++.h>
using namespace std;
main() { 
  int t, n, x, m, r, i;
  cin >> t;
  while(t--){cin>>n;m=r=0;for(i=1;i<=n;i++){cin>>x;m=max(m, x);if(m==i)r++;}cout<<r<<'\n';}
}