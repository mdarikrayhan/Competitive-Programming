#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define filein freopen("input.in", "r", stdin);
#define fileout freopen("output.txt", "w", stdout);
#define ld long double
#define ll long long
#define ull unsigned long long
using namespace std;

const int N = 502;
bool arr[N][N];
int n;
string s;

bool works(int x, int y)
{
    if (x-1+y-1 > n-1) cout << "? 1 1 " << x << ' ' << y << endl;
    else cout << "? " << x << ' ' << y << ' ' << n << ' ' << n << endl;
    cin >> s;
    return s[0] == 'Y';
}

int main()
{fastio
    cin >> n;
    arr[1][1] = arr[n][n] = 1;
    int x = 1, y = 1;
    for (int i = 1; i < n; i++)
    {
        if (works(x, y+1))
        {
            arr[x][y+1] = 1;
            y++;
        }
        else
        {
            arr[x+1][y] = 1;
            x++;
        }
    }
    x = y = n;
    for (int i = 2; i < n; i++)
    {
        if (works(x-1, y))
        {
            arr[x-1][y] = 1;
            x--;
        }
        else
        {
            arr[x][y-1] = 1;
            y--;
        }
    }
    x = y = 1;
    cout << "! ";
    while (x != n || y != n)
    {
        if (arr[x][y+1])
        {
            cout << 'R';
            y++;
        }
        else
        {
            cout << 'D';
            x++;
        }
    }
    cout << endl;
}