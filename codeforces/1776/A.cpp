#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin>>t;

  while (t--) {
    int n;
    cin>>n;

    int w=0;
    vector<int> a(n+1);
    for (int i=1; i<=n; ++i) {
      cin>>a[i];
      w += (a[i]-a[i-1])/120;
    }
    w += (1440-a[n])/120;

    cout<<(w>=2?"YES":"NO")<<endl;
  }
}