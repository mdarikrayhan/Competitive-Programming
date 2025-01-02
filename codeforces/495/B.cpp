#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <algorithm>

using namespace std;
typedef int64_t T;
#define ll long long 
#define pb push_back
const int M = 1e9+7;

const int N = 2e5+10;


int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
    
}


void solve(){
    // cout<<"THE"<<endl;
    ll a,b;

    cin>>a>>b;
    ll n = abs(a-b);

    if(n == 0){
        cout<<"infinity"<<endl;
        return;
    }

    vector<long long> factors;

    for(long long i=1; i*i <= n; i++){
        if(n%i == 0){
            factors.push_back(i);
            if(n/i != i){
                factors.push_back(n/i);
            }
        }
    }

    ll ct = 0;
    for(int i=0;i<factors.size();i++){
        if(factors[i]>b){
            ct++;
        }
    }

    cout<<ct<<endl;
}


int main() {
    

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
          
    }
    return 0;
}

/*


*/