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
    for (int i = 1; i <= T; i++)
    {
        int n, ans = INT_MIN;
        cin >> n;
        string s;
        cin >> s;
        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq1[s[i] - 'a']++;
        }
        for (int i = n - 1; i > 0; i--)
        {
            freq2[s[i] - 'a']++;
            freq1[s[i] - 'a']--;
            int temp1 = 0, temp2 = 0;
            for (int j = 0; j < 26; j++)
            {
                if(freq1[j]){
                    temp1++;
                }
                if(freq2[j]){
                    temp2++;
                }
            }

            ans = max(ans, temp1 + temp2);
        }
        cout << ans << nl;
    }
    return 0;
}