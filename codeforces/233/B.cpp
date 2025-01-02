#include <cmath>
#include <iostream>

using namespace std;

__int128 q_sum(__int128 x)
{
    __int128 ans = 0;

    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

__int128 s(__int128 x)
{
    return x * (q_sum(x) + x);
}

// 用于打印 __int128 类型的数
void print128(__int128 n)
{
    if (n == 0)
    {
        cout << "0";
        return;
    }
    if (n < 0)
    {
        cout << "-";
        n = -n;
    }
    char buffer[40];
    int i = 39;
    buffer[i] = '\0';
    while (n != 0 && i > 0)
    {
        buffer[--i] = '0' + n % 10;
        n /= 10;
    }
    cout << &buffer[i];
}

int main()
{
    __int128 n;
    long long input;
    cin >> input;
    n = input;
    // print128(n);
    __int128 x0 = sqrt((long double)n);
    // print128(x0);
    // cout<<"s(x0): "<<endl;
    // print128(s(x0));
    if (s(x0) == n)
    {
        print128(x0);
        cout << endl;
        return 0;
    } else
    {
        if (s(x0) < n)
        {
            exit(0);
        } else
        {
            __int128 l = 0, r = x0 - 1;

            while (l < r)
            {
                if(r-l<1e4)
                {
                    int flag=0;

                    for( __int128 i=l;i<=r;i++)
                    {
                        if(s(i)==n)
                        {
                            print128(i);
                            cout<<endl;
                            return 0;
                        }
                    }
                    cout<<"-1"<<endl;
                    return 0;

                }
                // cout << "l: ";
                // print128(l);
                // cout << endl;
                // cout << "r: ";
                // print128(r);
                // cout << endl;
                __int128 mid = (l + r + 1) / 2;
                // cout << "mid: ";
                // print128(mid);
                // cout << endl;
                // cout << "s(mid): ";
                // print128(s(mid));
                // cout << endl;
                if (s(mid) <= n)
                {
                    l = mid;
                } else
                {
                    r = mid - 1;
                }
            }
            // cout << "l: ";
            // print128(l);
            // cout << endl;
            // cout << "r: ";
            // print128(r);
            // cout << endl;
            // cout << "asdfasdf: ";
            // print128(s(99999999));

            // if(s(99999999)>s(100000010))

            // {
            //     cout<<"cao"<<endl;
            // }
            // cout << endl;
            if (s(r) == n)
            {
                print128(l);
                cout << endl;
            } else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
