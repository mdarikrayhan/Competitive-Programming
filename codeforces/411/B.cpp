#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) ((v).begin()), ((v).end())

void FastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    FastIO();
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> instructions(n, vector<int>(m));
    for(auto &i : instructions)
        for(auto &j : i)
            cin >> j;

    vector<int> LockedCores(n, 0);
    vector<int> LockedCells(k + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        vector<int> Count(k + 1, 0);
        for (int j = 0; j < n; j++)
        {
            if (LockedCores[j] == 0)
            {
                int cell = instructions[j][i - 1];
                if (cell > 0)
                {
                    Count[cell]++;
                }
            }
        }

        for (int k = 0; k < n; k++)
        {
            if (LockedCores[k] == 0)
            {
                int cell = instructions[k][i - 1];
                if (cell > 0 && Count[cell] > 1)
                {
                    LockedCores[k] = i;
                    LockedCells[cell] = 1;
                }
            }
        }

        for (int x = 0; x < n; x++)
        {
            if (LockedCores[x] == 0)
            {
                int cell = instructions[x][i - 1];
                if (cell > 0 && LockedCells[cell] == 1)
                {
                    LockedCores[x] = i;
                }
            }
        }
    }
    for (auto i : LockedCores) cout << i << "\n";


    return 0;
}
