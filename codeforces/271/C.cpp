#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define ld long double
using namespace std;
const int M = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,k;cin >> n >> k;
    if(n/k<3)cout << "-1\n";
    else{
        ll rmd=n-k;
        for (ll i = 1; i <= k; i++)for (ll j = 0; j < rmd/k; j++)cout << i << " ";
        for (ll i = 0; i < rmd%k; i++)cout << k << " ";
        for (ll i = 1; i <= k; i++)cout << i << " ";
    }
}