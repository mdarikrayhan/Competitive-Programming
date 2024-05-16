#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <bits/stdc++.h>
using namespace std;
#define int int64_t




int_fast32_t main(){
int test;
cin >> test;
while(test--) {
    int n,k;
    cin >> n>>k;
    vector<int> b(n);
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> b[i];
        a[i]=pow(10,b[i]);
    }

    int ans = 0,spend=0;
    for(int i=0;i<n-1;i++) {
        spend=min(k,a[i+1]/a[i]-1);
        ans+=spend*a[i];
        k-=spend;
        if(k==0&&spend!=a[i+1]/a[i]-1) {
            ans+=a[i];
            break;
        }
        else if(k==0) {
            ans+=a[i+1];
            break;
        }
    }
    if(k>0) {
        ans+=a[n-1]*(k+1);
    }

    cout << ans << endl;

}
    return 0;
}