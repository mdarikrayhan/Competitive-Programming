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
        string s;
        cin >> s;
        int n = s.size();
        if(n % 2){
            cout << "NO\n";
            continue;
        }
        int ok = 1;
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[i + n /2]){
                cout << "NO\n";
                ok = 0;
                break;
            }
        }
        if(ok){
            cout << "YES\n";
        }   
    }
    return 0;
}