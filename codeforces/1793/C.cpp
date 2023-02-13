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
        int n, flag = 0;
        cin >> n;
        vector<int> array(n);
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        int mn = 1, mx = n;
        int left = 0, right = n - 1;
        int tempi, tempj;

        while (left < right)
        {
            tempi = left;
            tempj = right;
            if (array[left] == mn)
            {
                left++;
                mn++;
            }
            else if (array[left] == mx)
            {
                left++;
                mx--;
            }
            if (array[right] == mn)
            {

                right--;
                mn++;
            }
            else if (array[right] == mx)
            {

                right--;
                mx--;
            }
            if (tempi == left and tempj == right)
            {

                cout << left + 1 << " " << right + 1 << '\n';
                flag = 1;
                break;
            }
        }
        sort(array.begin(), array.end());
        if (flag == 0)
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}