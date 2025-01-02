#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

signed main() {
    int t;
    cin >> t;

    while( t-- ) {
        int n , m;
        cin >> n >> m;
        int cnt = 0;
        vector< pair< int, pair<int , vector<int>>  > > v;  // sum , index , vector

        for(int i = 0; i < n; i++ ) {
            vector<int> tmp(m);
            int c = 0;
            for(int j = 0; j < m; j++ ) {
                cin >> tmp[j];
                if( tmp[j] == 1 ) {
                    cnt++;
                    c++;
                }
            }

            // cout << c << endl;
            v.push_back({ c , {i , tmp } });
        }

        // for(int i = 0; i < n; i++ ) {
            // sort(v[i].S.S.begin() , v[i].S.S.end() , greater<int>() ) ;
        // }
        // cout << cnt << endl;
        sort(v.begin() , v.end());

        // for(int i = 0; i < n; i++ ) {
        //     // cout << v[i].F << " " << v[i].S.F + 1 << endl;
        //     for(int j = 0; j < v[i].S.S.size(); j++ ) {
        //         // cout << v[i].S.S[j] << " ";
        //     }
        //     // cout << endl;
        // }

        if( cnt % n != 0 ) cout << -1 << endl;
        else {

            vector<vector<int>> ans;
        
            int i1 = 0 , j1 = n - 1;

            while( i1 < j1 ) {
                int c1 = v[i1].first , c2 = 0;
                // cout << c1 << " " << c2 << endl;
                for(int k1 = 0; k1 < m; k1++ ) {
                    if( v[j1].S.S[k1] ) c2++;
                }
                if( c1 == c2 ) {
                    i1++;
                    j1--;
                    continue;
                }

                int req = cnt/n - c1;
                int exj = c2 - cnt/n;

                // cout << req << " " << exj << endl;

                int jj1 = 0;
                while( req > 0 ) {
                    if( v[i1].S.S[jj1] == 0 && v[j1].S.S[jj1] == 1 ) {
                        v[i1].S.S[jj1] = 1;
                        v[j1].S.S[jj1] = 0;
                        ans.push_back({ v[i1].S.F + 1 , v[j1].S.F + 1 , jj1 + 1 } );
                        req--;
                        exj--;
                    }
                    jj1++;
                    if( jj1 == m || exj == 0 ) {
                        j1--;
                        exj = v[j1].first - cnt/n;
                        jj1 = 0;
                    }
                    // cout << j1 << " " << exj << " " << req << endl;
                }
                i1++;
                    
                // cout << i1 << " " <<j1 << endl;
                // if( i1 == 2 ) break;
            }

            cout << ans.size() << endl;
            for(auto it : ans ) {
                cout << it[0] << " "<< it[1] << " " << it[2] << endl;
            }
           
        }


        //  for(int i = 0; i < n; i++ ) {
        //     cout << v[i].F << " " << v[i].S.F + 1 << endl;
        //     for(int j = 0; j < v[i].S.S.size(); j++ ) {
        //         cout << v[i].S.S[j] << " ";
        //     }
        //     cout << endl;
        // }

    }
}