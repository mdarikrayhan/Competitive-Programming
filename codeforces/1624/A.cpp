#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define FIFO ios_base::sync_with_stdio(false) , cin.tie(nullptr), cout.tie(nullptr)

using namespace std;



void solve(int n)
{
    ll maxi = -1e18, mini = 1e18;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        if(x > maxi) maxi = x;
        if(x < mini) mini = x;
    }

    cout << maxi - mini << endl;
}

int main()
{
    FIFO;

    int tt; cin >> tt;

    while(tt--){
       int n; cin >> n;
       solve(n);
    }


    return 0;
}

