#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false),cin.tie(NULL));

using namespace std;

int main()
{
    fastread();

    ll testCases;
    cin >> testCases;

    while (testCases--)
    {
        ll divisor, remainder, limit;
        cin >> divisor >> remainder >> limit;

        ll result = 0;
        result = limit - limit % divisor + remainder;

        if (result <= limit)
        {
            cout << result << endl;
        }
        else
        {
            cout << (limit - limit % divisor - (divisor - remainder)) << endl;
        }
    }

    return 0;
}
