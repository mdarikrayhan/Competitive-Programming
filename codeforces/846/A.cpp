#include <bits/stdc++.h>
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define int long long int

using namespace std;

int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin>>n; 

    vi nose(n); 
    vi one(n + 1); 
    vi zero(n + 1); 
    for(auto &i: nose) cin>>i; 

    for(int i = 0; i<n; i++) {
        if(nose[i] == 1) {
            one[i + 1] = one[i] + 1; 
            zero[i + 1] = zero[i]; 
        } else {
            zero[i + 1] = zero[i] + 1; 
            one[i + 1] = one[i]; 
        }
    }
    
    int suma = 0;
    for(int i = 0; i<n; i++) {
        suma = max(n - (one[i + 1] - one[0] + zero[n] - zero[i + 1]), suma); 
    }
    suma = max(n - one.back(), suma); 
    suma = max(n - zero.back(), suma); 
    cout<<suma<<endl; 

    return 0;
}