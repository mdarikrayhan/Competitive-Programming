#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--){
    int n;
    cin >> n;
    vector<int> a(n);
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cur = cur/a[i] + 1;
        cur *= a[i];
    }
    cout << cur << endl;
    }

    return 0;
}