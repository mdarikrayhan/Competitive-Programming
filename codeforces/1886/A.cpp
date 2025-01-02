// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define spe " "
using namespace std;
int main() {
    // Write C++ code her
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n < 7 || n == 9) cout<<"NO\n";
        else{
            cout<<"YES\n";
            if(n % 3 == 0) {
                cout<<1<<spe<<4<<spe<<n-5<<endl;
            }
            else cout<<1<<spe<<2<<spe<<n-3<<endl;
        }
    }
}