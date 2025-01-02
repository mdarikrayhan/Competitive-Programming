// LUOGU_RID: 160137552
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N = 100005;

int n,m,u[N],v[N],w[N],in[N],num[N],pos,ans[N];
vector<int> g[N];

bool check(int mid)
{
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        in[i] = 0;
        g[i].clear();
    }

    for(int i=1;i<=m;i++)
        if(w[i] > mid)
        {
            g[u[i]].push_back(v[i]);
            in[v[i]]++;
        }

    queue<int> q;
    for(int i=1;i<=n;i++)
        if(in[i] == 0)q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        num[u] = ++cnt;
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v = g[u][i];
            in[v]--;
            if(in[v] == 0) q.push(v);
        }
    }
    if(cnt != n) return false;

    memset(ans,0,sizeof(ans));
    pos = 0;

    for(int i=1;i<=m;i++)
        if(w[i] <= mid && num[u[i]] > num[v[i]]) ans[++pos] = i;
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
        cin >> u[i] >> v[i] >> w[i];

    int l = 0, r = 2e9, k;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
        {
            k = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << k << " " << pos << endl;
    for(int i=1;i<=pos;i++)
        cout << ans[i] << " ";
    return 0;
}
