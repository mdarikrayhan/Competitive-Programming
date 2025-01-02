#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n][2];
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                cin >> a[i][j] ;
            }
        }
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
                if(a[i][0]>=a[0][0])
                v.push_back({a[i][0],a[i][1]});
        }
        int count =0;  
        for(int i=0;i<v.size();i++){
            if(v[i][1]>=a[0][1])
            count++;
        }
        if(count == 1)
        cout << a[0][0] << endl;
        else
        cout << -1 << endl;
        
    }
}