#include<bits/stdc++.h>
using ll = long long;
using namespace std;

void work(){
    int n;
    cin >> n;

    vector< int > d( n + 2 );
    vector< pair < int, int > > ans;

    for ( int i = 1; i <= n; i++ ) cin >> d [ i ];

    int idx = 1;
    int l = 1, r = n;

    while( l <= r ) {
        int x = d [ l ], y = d [ r ];

        for ( int i = idx; i <= idx + x - 1; i++ ){
            for ( int j = i + 1; j <= idx + y; j++){
                ans.push_back( { i, j } );
            }
        }

        idx += x;
        for ( int i = l + 1; i < r; i++ ) d[i] -= x;

        l++;
        r--;
    }

    cout << ans.size() << '\n';
    for ( auto [ u, v ] : ans ){
        cout << u << " " << v << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1; //cin >> T;
    while(T--) work();

    return 0;
}