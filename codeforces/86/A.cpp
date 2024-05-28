#include <bits/stdc++.h>
#define ll long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
using namespace std;
ll x, y;
string a, b; 
int main()
{
    cin >> a >> b;
    if (a.size() == b.size())
    {
        if (b[0] < '5')
        {
            for (auto i : b)
            {
                i -= '0';
                x = x * 10 + i;
                y = y * 10 + (9 - i);
            }
            cout << x * y << endl;
        }
        else if (a[0] >= '5')
        {
            for (auto i : a)
            {
                i -= '0';
                x = x * 10 + i;
                y = y * 10 + (9 - i);
            }
            cout << x * y << endl;
        }
        else
        {
            x = 5;
            rep(i, 2, b.size()) x *= 10;
            cout << (x - 1) * x << endl;
        }
    }
    else
    {
        if (b[0] > '4')
        {
            x = 5;
            rep(i, 2, b.size()) x *= 10;
            cout << (x - 1) * x << endl;
        }
        else
        {
            for (auto i : b)
            {
                i -= '0';
                x = x * 10 + i;
                y = y * 10 + (9 - i);
            }
            cout << x * y << endl;
        }
    }
    return 0;
}
 		 			  	  			 			    	 	 	 	