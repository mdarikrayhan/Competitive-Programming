#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int MAXN = 1e5 + 3;

int n, k, a[MAXN];
int ans = 0;
set<LL> st;

int main(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; i++){
    if(st.find(a[i]) == st.end()){
      st.insert(1ll * a[i] * k);
      ans++;
    }
  }
  cout << ans;
  return 0;
}

  	    						  	  		  			