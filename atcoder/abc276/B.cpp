#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> adjlist[10000000];
    int nodes, edge;
    cin >> nodes;
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    for (int i = 1; i <= nodes; i++)
    {

        int sz = adjlist[i].size();
        cout << sz << " ";
        int arr[1000000];
        for (int j = 0; j < sz; j++)
        {
            arr[j] = adjlist[i][j];
        }
        sort(arr, arr + sz);
        for (int j = 0; j < sz; j++)
        {
            cout << arr[j] << " ";
        }
        cout << nl;
    }
    return 0;
}