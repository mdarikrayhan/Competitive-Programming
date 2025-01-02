#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SQ(a) (a) * (a)

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = true;

    if (n == 1)
    {
        if (s == "1")
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
    {
        if(s[0]==s[1] && s[0]=='0')
        {
            cout << "No" << endl;
            flag = false;
        }
        else if(s[n-1]==s[n-2] && s[n-1]=='0')
        {
            cout << "No" << endl;
            flag = false;
        }

        for (int i = 0; (i < s.length() - 1) && flag; i++)
        {
            if (s[i] == s[i + 1] && s[i]=='1')
            {
                cout << "No" << endl;
                flag = false;
                break;
            }
        }

        for (int i = 0; (i < s.length() - 2) && flag; i++)
        {
            if (s[i] == s[i + 1] && s[i]=='0' && s[i] == s[i+2])
            {
                cout << "No" << endl;
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Yes" << endl;
    }

    return 0;
}