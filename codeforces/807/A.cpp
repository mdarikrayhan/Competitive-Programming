// Init To Winit
#include <bits/stdc++.h>
using namespace std;
// This Code Works!
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a, b, maxi = INT32_MAX; 
  cin >> n;
  bool maybe = false;
  while (n--){
    int a, b;
    cin >> a >> b;
    if (a != b) return cout << "rated", 0;
    if(a <= maxi) maxi = a; 
    else maybe = true;
  }
  cout << (maybe ? "unrated" : "maybe");
}