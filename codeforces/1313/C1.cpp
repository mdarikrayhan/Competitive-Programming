#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i]; 

    vector<int> dp(n);
    long long sum = 0;
    long long saveSum = 0;
    int ind = -1;  

    for (int i = 0; i < n; i++) 
    {
        sum = 0;
        dp[i] = arr[i];  
        sum += dp[i];

        for (int j = i - 1; j >= 0; j--) 
        {
            dp[j] = min(dp[j + 1], arr[j]); 
            sum += dp[j];
        }

        for (int j = i + 1; j < n; j++) 
        {
            dp[j] = min(dp[j - 1], arr[j]);  
            sum += dp[j];
        }

        if (sum > saveSum) 
        {
            saveSum = sum;
            ind = i;
        }
    }

    dp[ind] = arr[ind];
    for (int j = ind - 1; j >= 0; j--) 
        dp[j] = min(dp[j + 1], arr[j]);
    
    for (int j = ind + 1; j < n; j++) 
        dp[j] = min(dp[j - 1], arr[j]);
    

    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";
}
