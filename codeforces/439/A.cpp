#include <bits/stdc++.h>
using namespace std;
 int main () {
     int n, d;
     cin >> n >> d;
     int arr[n];
     int count = 0;
     for (int i=0;i<n;i++) {
         cin >> arr[i];
         count = count + arr[i];
     }
     int t = 10*(n-1) + count;
     if (d < t) {
         cout << -1 << endl;
     }
     else {
         cout << 2*(n-1) + (d-(t))/5 << endl;
     }
 }