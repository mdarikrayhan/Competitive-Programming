#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000+6
int a[MAXN];
int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    while(b){
        int r = a % b;
        a = b; b = r;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        // 2*a, b -> 2*b
        if(b > 2 * a){
            cout << b*b;
        }
        else{
            cout << 4*a*a;
        }
        cout << endl;
    }
    return 0;
}