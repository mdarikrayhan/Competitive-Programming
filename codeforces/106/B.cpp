#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long int ll;

int outdated(int a[][4], int x, int y)
{

    for (int i = 0; i < 4; i++)
    {
        if (a[x][i] > a[y][i] || a[x][i] == a[y][i] )
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    int a[n][4];
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {

        int flag = 0;

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (outdated(a, i, j) == 1)
                {
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            v.push_back(i);
        }
    }

    int min = a[v[0]][3];
    int ans = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (a[v[i]][3] < min)
        {
            min = a[v[i]][3];
            ans = v[i];
        }
    }

    cout << ans + 1 << endl;

    return 0;
}
