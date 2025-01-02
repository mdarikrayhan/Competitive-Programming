// 3BNABEY
#include <bits/stdc++.h>
#include <iostream>
#define Medo  cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
#define M endl
#define Done return 0;
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
#endif
    Medo;
    ll n , x ;
    cin>>n>>x;
    int kid=0;
    for (int i = 0; i < n; ++i) {
        char s ;
        ll z;
        cin>>s>>z;
        if(s == '+'){
            x += z;
        } else{
            if(x>=z){
                x -= z;
            } else{
                kid++;
            }
        }
    }
    cout<<x<<" "<<kid;
    Done;
}

