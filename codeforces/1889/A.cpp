#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n % 2 != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> v;
            int count = 0;
            int i = 0, j = n - 1;
            while (i < j)
            {
                if (s[i] == s[j] && s[i] == '0')
                {
                    count++;
                    if (count > 300)
                        break;
                    v.push_back(j + 1);
                    s.insert(j + 1, "01");
                    i++;
                    j++;
                }
                else if (s[i] == s[j] && s[i] == '1')
                {
                    count++;
                    if (count > 300)
                        break;
                    v.push_back(i);
                    s.insert(i, "01");
                    i++;
                    j++;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            if (count > 300)
            {
                cout << -1 << endl;
            }
            else if (count == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << count << endl;
                int x = v.size();
                for (int i = 0; i < x; i++)
                {
                    cout << v[i] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}