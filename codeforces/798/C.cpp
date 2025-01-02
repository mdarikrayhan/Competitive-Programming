# include <bits/stdc++.h>
# define ll long long
# define nl '\n'

using namespace std;

const int MX = 100000;
int n;
vector<int> a;
int mem[MX + 5][2];

int dp(int i, int j)
{
    if(i == n)
    {
        if(j == 0) return 0;
        return 2*MX;
    }

    int &x = mem[i][j];
    if(x != -1) return x;

    x = 2*MX;

    if(a[i]%2 == 0 && j == 0) x = min(x, dp(i+1, 0));
    else if(a[i]%2 == 0 && j == 1) x = min(x, 2 + dp(i+1, 0));
    else if(a[i]%2 == 1 && j == 0) x = min({x, 2 + dp(i+1, 0), dp(i+1, 1)});
    else x = min(x, 1 + dp(i+1, 0));

    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    //freopen("prueba.txt", "r", stdin);

    cin>>n;
    a.resize(n);
    for(int i=0;i<n;++i) cin>>a[i];

    int gcd = a[0];
    for(auto &e:a) gcd = __gcd(e, gcd);

    cout << "YES" << nl;

    if(gcd > 1)
    {
        cout << 0 << nl;
        return 0;
    }

    memset(mem, -1, sizeof(mem));

    int res = dp(1, a[0]%2);
    cout << res << nl;

    return 0;
}
