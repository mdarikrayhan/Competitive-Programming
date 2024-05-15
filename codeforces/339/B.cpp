#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    
#ifdef _DEBUG

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    
    int a = 1;
    ll ans = 0;
    
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        
        if(x >= a){
            ans += x-a;
        }
        else{
            ans += n-a+x;
        }
        a = x;
    }
    
    cout << ans << '\n';
}
