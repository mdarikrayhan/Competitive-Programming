#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, x = 0;
    string ch,xp1("X++"),xp2("++X");
    cin >> n;
    if (n >= 1 && n <= 150)
    {
        while (n)
        {
            cin>>ch;
            
            if (ch.compare(xp1)==0 || ch.compare(xp2)==0 )
            {
                x++;
            }
            else
            {
                x--;
            }

            n--;
        }
    }
    cout<<x;
}