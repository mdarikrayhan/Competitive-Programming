#include <iostream>
using namespace std;

#define ll long long

int main()
{
    ll n, h, k, second = 0, remainder = 0;
    cin >> n >> h >> k;

    for (int i = 0; i < n; i++)
    {
        int pot; cin >> pot;
        if (pot + remainder > h)
        {
            ++second;
            remainder = 0;
        }
        remainder += pot;
        second += remainder/k;
        remainder %= k;
    }

    cout << (remainder != 0 ? ++second:second);
    return 0;
}