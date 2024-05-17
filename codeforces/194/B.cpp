#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int t;
    long long int n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        cout << ((n+1)*(4*n) / __gcd(n+1,4*n)) / (n+1) + 1 << endl;
    }
}
