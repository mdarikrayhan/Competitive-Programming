#include <iostream>
using namespace std;
int main()
{
    int count, pos = 1;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[i] == s[j])
            {
                count++;
            }
        }
        if (count == 0)
        {
            pos++;
        }
        count = 0;
    }

    if (pos % 2 == 0)
    {
        cout << "IGNORE HIM!";
    }
    else
    {
        cout << "CHAT WITH HER!";
    }
}