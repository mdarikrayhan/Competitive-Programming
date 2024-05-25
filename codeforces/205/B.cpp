#include <iostream>
#include <vector>
 
using namespace std;
 
int arr[10000001];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (i && arr[i] < arr[i - 1]) {
		sum += arr[i - 1] - arr[i];
	  }
 
    }
    cout<< sum << endl; 
 
   
    return 0;
}