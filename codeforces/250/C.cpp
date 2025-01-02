#include <iostream>

using namespace std;

const int dim = 200001;
int v[ dim ], stres[ dim ], i, j, k, n, x, y;

int main()
{
    cin >> n;
    cin >> k;

    j = 0;

    for ( i = 1; i <= n; i++ )
    {
        cin >> x;
        if ( x != v[ j ] )
        {
            j++;
            v[ j ] = x;
        }
    }

    for ( i = 1; i <= j; i++ )
    {
        if ( v[ i - 1 ] == v[ i + 1 ] )
        {
            stres[ v[ i ] ] += 2;
        } else {
            stres[ v[ i ] ]++;
        }
    }

    x = 0;
    y = 0;

    for ( i = 1; i <= k; i++ )
    {
        if ( stres[ i ] > y )
        {
            x = i;
            y = stres[ i ];
        }
    }

    cout << x;

    return 0;
}