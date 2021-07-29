#include <iostream>
using namespace std;
int main()
{
    int i=0, x=0, y=0, z=0, count=0;
    cin >> i;
    while (i)
    {
        cin >> x >> y >> z;
        if ((x + y + z) >= 2)
        {
            count++;
        }
        i--;
    }
    cout<<count;
}