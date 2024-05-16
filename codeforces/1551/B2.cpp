#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> v[200005];
vector<int> f;
int res[200005];
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int a[n + 1];
        for(int i = 1; i <= n; i++)
        {
            res[i] = 0;
            cin>>a[i];
            v[a[i]].push_back(i);
        }
        for(int i = 1; i <= n; i++)
        {
            if(v[i].size() >= k)
            {
                for(int j = 0; j < k; j++)
                {
                    res[v[i][j]] = j + 1;
                }
            }
            else
            {
                if(v[i].size() >= 1)
                {
                    for(int j = 0; j < v[i].size(); j++)
                        f.push_back(v[i][j]);
                }
            }
        }
        int cont = f.size() / k;
        int p = 1, dd =0;
        for(int i = 0; i < f.size(); i++)
        {
            if(dd == cont)
                break;
            res[f[i]] = p;
            if(p == k)
                dd++;
            p++;
            if(p == k + 1)
                p = 1;
        }
        for(int i = 1; i <= n; i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<'\n';
        f.clear();
        for(int i = 0; i <= n; i++)
            v[i].clear();
    }
    return 0;
}
