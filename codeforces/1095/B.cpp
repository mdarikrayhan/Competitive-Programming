// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <stdint.h>
 #include <climits>
using namespace std;


int main() {
    // Write C++ code here
    
    int n;
    cin>>n;
    
    int arr[n];
    
    for(int i=0; i<n; i++)cin>>arr[i];
    
    sort(arr, arr + n);
    
    int ans = INT_MAX;
    
    if(n <= 2)ans = 0;
    else{
        ans = min(arr[n-1] - arr[1], arr[n-2] - arr[0]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}