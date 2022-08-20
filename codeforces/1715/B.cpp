#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long nnnnnnnnnnnnnnnnn, kkkkkkkkkkkk, bbbbbbbbbb, ________;
        cin >> nnnnnnnnnnnnnnnnn >> kkkkkkkkkkkk >> bbbbbbbbbb >> ________;
        vector<long long> a(nnnnnnnnnnnnnnnnn);
        if (________ < kkkkkkkkkkkk*bbbbbbbbbb || ________ > nnnnnnnnnnnnnnnnn * (kkkkkkkkkkkk - 1) + kkkkkkkkkkkk * bbbbbbbbbb)
        {
            cout << -1 << endl;
        }
        else
        {
            a[nnnnnnnnnnnnnnnnn-1] = kkkkkkkkkkkk * bbbbbbbbbb;
            ________ -= kkkkkkkkkkkk * bbbbbbbbbb;
            for (int i = nnnnnnnnnnnnnnnnn - 1; i >= 0 && ________ > 0; i--)
            {
                a[i] +=min(kkkkkkkkkkkk - 1, ________);
                ________ -= min(kkkkkkkkkkkk - 1, ________);
            }
            for (int i=0; i < nnnnnnnnnnnnnnnnn; i++)
            {
                cout << a[i] << " ";
                
            }
            cout << endl;
        }
        
    }
    return 0;
}