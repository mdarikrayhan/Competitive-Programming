#include<bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define debug(x...)
#define testcase(tc)
#else
#include "/Users/mohdali/Documents/algo/debug.h"
#endif

#define int int64_t
#define pr(x) cout << x << endl
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2002010;

void dxt(){
  int n,k;
  cin >> n >> k;
  vector<int> pref(n + 1), ar(n + 1);
  for(int i = n - k + 1; i <= n; i++){
  	cin >> pref[i];
  }
  if(k == 1){
  	cout << "YES\n";
  	return;
  }
  for(int i = n - k + 2; i <= n; i++){
  	ar[i] = pref[i] - pref[i - 1];
  }
  //debug(pref, ar);
  if(!is_sorted(ar.begin() + n - k + 2, ar.end())){
  	cout << "NO\n";
  	return;
  }
  
  if(pref[n - k + 1] > ar[n - k + 2] * (n - k + 1)){
  	cout << "NO\n";
  	return;
  }
  cout << "YES\n";
  
}
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int test_cases = 1;
  cin >> test_cases;
  for(int i = 1; i <= test_cases; i++){
    dxt();
  }
  return 0;
}