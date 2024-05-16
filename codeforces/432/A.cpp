////////////////              ANAS IBN BELAL            /////////////////
//                      Test Case Less Template                       ||
//                                                                    ||
//                                                                    ||
//      BANGLADESH  UNIVERSITY OF BUSINESS AND TECHNOLOGY             ||
//                          INTAKE 52                                 ||
//                      DEPARTMENT OF CSE                             ||
//                                                                    ||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void Fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Fast_io();
    ll n, a;
    cin >> n >> a;
    vector<ll> mm(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> mm[i];
    }
    sort(mm.begin(), mm.end());
    ll team = 0;
    for (int i = 0; i < n; i++)
    {
        if (5 - mm[i] >= a)
        {
            team++;
        }
    }
    // ll temp = ceil(team / 3);
    cout << (team / 3) << endl;
    return 0;
}