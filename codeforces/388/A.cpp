/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for(int k = 1; k <= n; ++k){
        bool flag = true;
        for(int i = 0; i < n; ++i){
            if(a[i] < i / k){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << k << "\n";
            return 0;
        }
    }

    return 0;
}
