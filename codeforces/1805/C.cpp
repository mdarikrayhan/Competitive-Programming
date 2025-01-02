#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol(){
    int r,p;
    cin >> r >> p;
    vector<ll> rec(r);
    for (int i = 0 ; i < r ; i++){
        cin >> rec[i];
    }
    sort(rec.begin(),rec.end());
    while (p--){
        ll a,b,c;
        cin >> a >> b >> c;
        auto dis = [&](ll x) -> ll {
            return b*b + rec[x]*rec[x] - 2*b*rec[x] - 4*a*c;
        };
        int h = lower_bound(rec.begin(),rec.end()-1,b) - rec.begin();

        if (dis(h) < 0) {
            cout << "YES\n" ;
            cout << rec[h] << '\n';
        }else if (h >= 1 && dis(h-1) < 0) {
            cout << "YES\n" ;
            cout << rec[h-1] << '\n';
        }else {
            cout << "NO\n";
        }
    }
    cout << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t ;
    while(t--){
        sol();
    }

    return 0;
}
