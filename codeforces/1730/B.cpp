#include<bits/stdc++.h>
#include <cmath>

#define endl "\n"
#define ll long long

using namespace std;

/*=================================== CODE BEGIN =) ===================================*/

vector <pair <ll, ll>> v;

ll T, t[100001], n, i, j, kol, ans, x[100001];
ll l, r, mid, x0, mn, mx, l1[100001], r1[100001];

bool flag;

    bool func(ll d)
    {
        ll i;
        mx = -1e12;
        mn = 1e12;
        for(i = 1; i <= n; i++){
            if(d < t[i]) return false;
            l1[i] = x[i] - (d - t[i]);
            r1[i] = x[i] + (d - t[i]);
            mx = max(l1[i], mx);
            mn = min(mn, r1[i]);
        }
        if(mx <= mn) {
            x0 = mx;
            return true;
        }
        return false;
    }

    void solve()
    {
        cin >> n;

        for(i = 1; i <= n; i++) {cin >> x[i]; x[i] *= 2;}
        for(i = 1; i <= n; i++) {cin >> t[i]; t[i] *= 2;}

        l = 0;
        r = 1e9;

        while(l <= r) {
            mid = (l + r) / 2;

            if(func(mid))
                r = mid - 1;
            else l = mid + 1;
        }

        cout << setprecision(1) << fixed << x0 / 2. << endl;
    }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--)
       solve();

	return 0;
}

/*
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
*/
