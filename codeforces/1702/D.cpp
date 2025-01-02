#include <bits/stdc++.h>
using namespace std;

auto solve(){
    string s;cin >> s;
    int p;cin >> p;
    map< char , int > freq;
    int cost = 0;

    for(auto &it : s) freq[ it ]++ , cost = cost + ( it - 'a' + 1 );

    for (char i = 'z'; i >= 'a' ; --i) {
        if( cost <= p )
            goto jump;
        while( freq[ i ] > 0 ){
            cost = cost - ( i - 'a' + 1 );
            freq[ i ] --;
            if( cost <= p )
                goto jump;
        }

    }
    jump:;


    for (int i = 0; s[ i ] ; ++i) {

        if( freq[ s[ i ] ] ){
            cout << s[ i ];
            freq[ s[ i ] ] --;
        }

    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int tt = 1;cin >> tt ;
    while ( tt-- ) solve();
}