#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    int coins;

    cin >> coins;

    int odds = 0, evens = 0;

    for(int i = 0; i < coins; i++)
    {
        int temp;
        cin >> temp;
        if(temp % 2 == 1)
            odds++;
        else evens++;
    }
    cout << min(odds, evens) << endl;
}