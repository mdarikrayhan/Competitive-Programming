#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000+6
int check(int a){
    while(a){
        int r = a % 10;
        if(r != 1 && r != 0){
            return 0;
        }
        a/=10;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int c = 0, s = 0;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            s += x;
            if(x == 2){
                c++;
            }
        }
        if(s % 2){
            cout << "NO\n";
            continue;
        }
        if(c % 2 == 0){
            cout << "YES\n";
        }
        else{
            if(n - c >= 2){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}