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
        int n, s, r;
        cin >> n >> s >> r;
        cout << s - r << " ";
        vector<int> vi;
        int sum=r;
        for (int i = 0; i < (n - 1); i++)
        {
            vi.push_back(r / (n - 1));
            sum=sum-(r / (n - 1));
        }
        while (sum>0)
        {
            sort(vi.begin(), vi.end());
            vi[0]++;
            sum--;
        }
        for(auto i:vi){
            cout<<i<<" ";
        }
        cout << nl;
    }
    return 0;
}