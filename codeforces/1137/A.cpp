#include <iostream>
#include <vector>
#include <algorithm>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
// using namespace __gnu_pbds;
using namespace std;

// typedef tree<ll, 
//     null_type, 
//     less<ll>, 
//     rb_tree_tag, 
//     tree_order_statistics_node_update>

//     order_statistic_tree_less;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> rows(n);
    vector<vector<int>> columns(m);
    vector<vector<int>> arr(n);
    for(int i=0; i<n; i++)
    {
        arr[i] = vector<int>(m);
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
            // arr[i][j] = i*j + 1;
            rows[i].push_back(arr[i][j]);
            columns[j].push_back(arr[i][j]);
        }
        sort(rows[i].begin(), rows[i].end());
        int size = unique(rows[i].begin(), rows[i].end()) - rows[i].begin();
        // cout<<"size = "<<size<<"\n";
        rows[i].resize(size);
    }
    for(int i=0; i<m; i++)
    {
        sort(columns[i].begin(), columns[i].end());
        columns[i].resize(unique(columns[i].begin(), columns[i].end()) - columns[i].begin());
    }
    // cout<<"rows = \n";
    // for(int i=0; i<n; i++)
    // {
    //     for(int e: rows[i])
    //     {
    //         cout<<e<<" ";
    //     }
    //     cout<<"\n";
    // }
    // int result[n][m];
    for(int i=0; i<n; i++)
    {
        int rows_size = rows[i].size();
        // cout<<"rows_size = "<<rows_size<<"\n";
        for(int j=0; j<m; j++)
        {
            int columns_size = columns[j].size();
            int key = arr[i][j];
            int Lr = lower_bound(rows[i].begin(), rows[i].end(), key) - rows[i].begin();
            int Lc = lower_bound(columns[j].begin(), columns[j].end(), key) - columns[j].begin();
            int Gr = rows_size - Lr - 1;
            int Gc = columns_size - Lc - 1;
            // cout<<i<<" "<<j<<" "<<Lr<<" "<<Gr<<" "<<Lc<<" "<<Gc<<"\n\n";
            int result = max(Lr, Lc) + 1 + max(Gr, Gc);
            cout<<result<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
