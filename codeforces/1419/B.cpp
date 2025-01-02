#include<iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define endl "\n"
#define f(i, x, n) for(long long i=x; i<n; ++i)
#define ll long long
#define vll vector<long long>
#define vlp vector<pair<ll, ll>>
#define vvll vector<vector<long long>>
#define all(a) (a).begin(), (a).end()
ll binary_to_decimal(string s1){
    int d=0;
    for(int i = 0; i < s1.size(); i++){
        d = ((d * 2) % ((long long) 1e9 + 7)) % ((long long) 1e9 + 7);
        d = d + (s1[i] - 48);
    }
}

void solve(){
ll n;
cin>>n;
ll ans=0;
ll count=0;
ll i=1;
while(ans<=n){
    ans=ans+(((i)*(i+1))/2);
    i=2*i+1;
    count++;
}
cout<<count-1<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}//
// Created by Harsh Chanchlani on 15/05/24.
//
