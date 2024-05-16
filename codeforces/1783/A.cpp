#include <bits/stdc++.h>

using namespace std;



int main() {

  int t;
  cin >> t;
  while(t--) {
       int n;
       cin >> n;
       int arr[n];
       for (int i = 0; i < n; i++) {
           cin >> arr[i];
       }
       if (arr[0] != arr[n-1]) {
           swap(arr[0], arr[n-1]);
           swap(arr[1], arr[n-1]);
           
           cout << "YES" << endl;
           for (int i = 0; i < n; i++) {
               cout << arr[i] << " ";
           }
           cout << endl;
       }
       else {
           cout << "NO" << endl;
       }
       
       
       
    }
 
    
    
   

    
}