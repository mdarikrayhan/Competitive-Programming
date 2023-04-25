#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t; cin >> t; while (t--) {    
    int n; cin >> n;
    vector<int> A(n);
    for (auto &a: A) cin >> a;
    auto f = [&A](int i) {return max(1+max(A[i+1],A[i-1])-A[i], 0);};
    auto c {0ll}; for (int i {n-2}; i>0; i-=2) c+=f(i);
    auto a {c};
    for (int i {2}; i<n; i+=2) a = min(a, c+=f(i-1)-f(i-n%2));
    cout << a << '\n';
  }
}