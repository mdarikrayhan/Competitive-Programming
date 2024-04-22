 #include<bits/stdc++.h>
using namespace std;

using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        ll n , f , a , b; cin >> n >> f >> a >> b;
        bool ch = true;
        ll pre = 0;
        for(int i = 0; i < n; i++){
            ll val; cin >> val;
            if(!ch) continue;
            f -= min((val - pre ) * 1LL * a , b);
            if(f <= 0){
                ch = false;
            }
            pre = val;
        }
        if(ch) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}