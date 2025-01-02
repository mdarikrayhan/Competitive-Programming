#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, i, cnt=1, ops=0;
        cin >> n;
        string binary;
        cin >> binary;
        binary[n] = 'b';

        for(i=0; i<n; )
        {
            if(binary[i]==binary[i+1])
            {
                cnt++;
                i++;
            }
            else
            {
                if(cnt%2)
                {
                    (binary[i]=='0') ? binary[i]='1' : binary[i]='0';
                    ops++;
                }
                else
                {
                    i++;
                }
                cnt = 1;
            }
        }

        cout << ops << '\n';
    }

    return 0;
}
