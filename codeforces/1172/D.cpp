// LUOGU_RID: 158952087
//
// Problem: Nauuo and Portals
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1172D
// Memory Limit: 250 MB
// Time Limit: 2000 ms

#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1010;
int p[ MAXN ], q[ MAXN ];
struct Node
{
    int x1, y1, x2, y2;
};
vector< Node > ans;
int main()
{
    int n;
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> p[ i ];
    }
    for ( int i = 1; i <= n; i++ )
    {
        cin >> q[ i ];
    }
    for ( int i = 1; i <= n; i++ )
    {
        if ( p[ i ] == i and q[ i ] == i )
        {
            continue;
        }
        int ip, iq;
        for ( int j = 1; j <= n; j++ )
        {
            if ( p[ j ] == i )
            {
                ip = j;
            }
        }
        for ( int j = 1; j <= n; j++ )
        {
            if ( q[ j ] == i )
            {
                iq = j;
            }
        }
        ans.emplace_back( ( Node ){ i, iq, ip, i } );
        swap( p[ i ], p[ ip ] );
        swap( q[ i ], q[ iq ] );
    }
    cout << ans.size() << endl;
    for ( auto i : ans )
    {
        cout << i.x1 << ' ' << i.y1 << ' ' << i.x2 << ' ' << i.y2 << endl;
    }
}