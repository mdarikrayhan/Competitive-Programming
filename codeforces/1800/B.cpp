#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int x = 1; x <= T; x++)
    {
        int n, k, count = 0, lpair = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> uc(26, 0);
        vector<int> lc(26, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                uc[s[i] - 'A']++;
            }
            else
            {
                lc[s[i] - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            int temp = min(uc[i], lc[i]);
            count += temp;
            uc[i] -= temp;
            lc[i] -= temp;
        }
        for (int i = 0; i < 26; i++)
        {
            if (uc[i] >= 2)
            {
                lpair += (uc[i] / 2);
            }
            if (lc[i] >= 2)
            {
                lpair += (lc[i] / 2);
            }
        }

        count += min(lpair, k);
        cout << count << nl;
    }
    return 0;
}