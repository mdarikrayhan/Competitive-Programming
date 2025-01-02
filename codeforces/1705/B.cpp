#include <math.h>
#include <stdio.h>
#include <string.h>
#include <set>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>

#include <climits>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#define ll long long int
#define lf long float

#define PI 3.1415926535897932384626433832795
using namespace std;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        ll ans = 0;
        int ptr = 0;
        while (ptr < n && a[ptr] == 0)
            ptr++;
        for (int i = ptr; i < n - 1; ++i)
        {
            ans += a[i];
            if (a[i] == 0)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
