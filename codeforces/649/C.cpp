#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k2, k;
    cin >> n >> k2 >> k;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int wa=n;
    for(int i=0; i<n; i++){
        if(k2*2 < a[i]-k){
            wa=i;
            break;
        }
        if(!k) k2 -= (a[i]+1)/2;
        else {
            int d = min(k2, a[i]/2);
            k2 -= d, k -= a[i] - d*2;
        }
    }
    cout << wa;
    return 0;
}