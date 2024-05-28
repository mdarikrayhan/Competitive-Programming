/**
 * @author      : Davi Guimarães
 * @problem     : 172D
 * @created     : 20/04/2024
 */

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 10000000;
int a, n;
long long ans[N + 1];

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> a >> n;
  for(long long i = 1; i * i <= N; i++){
    for(long long j = i * i; j <= N; j += i * i){
      if(ans[j] == 0) ans[j] = j / (i * i);
      else ans[j] = min(ans[j], j / (i * i));
    }
  }
  cout << accumulate(ans+a, ans+a+n, 0ll) << endl;
  return 0;
}

