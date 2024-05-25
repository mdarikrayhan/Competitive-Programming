#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define vv vector<vector<lli>>
#define V vector<lli>
#define no cout<<"NO\n"
#define yes cout<<"YES\n"

lli st,st1;

lli dfs(lli s, V &vis, vv &g, V &prev, V &a1, vector<map<lli,lli>> &m)
{
    m[st1][s]++;
    vis[s] = 1;
    lli z{0};
    for (size_t i = 0; i < g[s].size(); i++)
    {
        if (z)
        {
            return z;
        }
        if (!vis[g[s][i]])
        {
            prev[g[s][i]] = s;
            z = dfs(g[s][i], vis, g, prev, a1, m);
        }
        else if(g[s][i]!=st && m[st1][g[s][i]]==0)
        {
            z = g[s][i];
            a1.push_back(g[s][i]);
            while (s!=st)
            {
                a1.push_back(s);
                s = prev[s];
            }
            a1.push_back(s);
            return z;
        }
        
    }
    return z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    lli n, m, s;
    cin >> n >> m >> s;
    vv g(n+1);
    lli x,y;
    V a;
    for (size_t i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        if (x==s)
        {
            a.push_back(y);
        }
        
    }
    st = s;
    V vis(n+1,0), prev(n+1,-1), a1, a2;
    vis[s] = 1;
    lli z{0};
    vector<map<lli,lli>> v(n+1);
    for (size_t i = 0; i < a.size(); i++)
    {
        if (vis[a[i]])
        {
            a1.push_back(a[i]);
            a1.push_back(s);
            z = a[i];
            while (z!=s)
            {
                a2.push_back(z);
                z = prev[z];
            }
            a2.push_back(z);
            break;
        }
        prev[a[i]] = s;
        st1 = a[i];
        z = dfs(a[i], vis, g, prev, a1, v);
        if (z!=0)
        {
            while (z!=s)
            {
                a2.push_back(z);
                z = prev[z];
            }
            a2.push_back(z);
            break;
        }
        
    }
    if (z)
    {
        cout << "Possible" << endl;
        cout << a1.size() << endl;
        for (lli i = a1.size() - 1; i >= 0; i--)
        {
            cout << a1[i] << " ";
        }
        cout << endl;
        cout << a2.size() << endl;
        for (lli i = a2.size() - 1; i >= 0; i--)
        {
            cout << a2[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    


    return 0;
}