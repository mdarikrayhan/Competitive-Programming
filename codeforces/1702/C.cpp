#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> u(n);
        for (int i = 0; i < n; i++)
        {
            cin >> u[i];
        }
        map<int, int> first;
        map<int, int> last;
        for (int i = 0; i < n; i++)
        {
            if (first.find(u[i]) == first.end())
             /*
             if element is not present than this executes because 
             the find function searchs from begin() to end()
             if the the element is not present
             then first.find() becomes first.end()
             */
            {
                first[u[i]] = i; // saves the index when the number is frist found
            }
            last[u[i]] = i; // saves index of last found number
        }
        while (k--)
        {
            int x, y;
            cin >> x >> y;
            if (first.find(x) == first.end() || last.find(y) == last.end())
            //if both number are not found in map then print no
            {
                cout << "NO" << '\n';
                continue;
            }
            x = first[x];
            y = last[y];
            cout << (x <= y ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
