#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int cases;
    cin >> cases;

    while (cases--)
    {
        long long int n, a, b; 
        cin >> n >> a >> b;
        long double ans = static_cast<long double>(n) / a;
        long double fractionalPart = ans - static_cast<long long>(ans); 

        if (a > b)
        {
            cout << "1"<<endl; 
        }
        else
        {
            if (fractionalPart > 0)
            {
                cout << static_cast<long long>(ceil(ans)) << endl;
            }
            else
            {
                cout << static_cast<long long>(ans) << endl;
            }
        }
    }

    return 0;
}
