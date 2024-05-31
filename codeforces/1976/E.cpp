#include <bits/stdc++.h>

using namespace std;

#define int long long

int modulo = 998244353;

int n,q;
int l[300005],r[300005];

int fs[600005],fd[600005],value[600005],who[600005];

vector<int> sir;
bool insir[300005];

void dfs(int nod)
{
    if (fs[nod] == 0)
        sir.push_back(value[nod]),insir[value[nod]] = true;
    else
    {
        dfs(fs[nod]);
        dfs(fd[nod]);
    }
}

vector<int> v;

int idk(int x)
{
    int st = -1,pas = 1 << 18;
    while (pas != 0)
    {
        if (st + pas < v.size() and v[st + pas] <= x)
            st += pas;
        pas /= 2;
    }
    return st + 1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
        cin >> l[i];
    for (int i = 1; i <= q; i++)
        cin >> r[i];
    who[n] = 1;
    int cur = 1;
    for (int i = 1; i <= q; i++)
    {
        int nod = who[max(l[i],r[i])];
        fs[nod] = ++cur;
        who[l[i]] = cur;
        value[cur] = l[i];
        fd[nod] = ++cur;
        who[r[i]] = cur;
        value[cur] = r[i];
    }
    dfs(1);
    int nrr = sir.size();
    for (int i = 0; i + 1 < sir.size(); i++)
        v.push_back(max(sir[i],sir[i + 1]));
    v.push_back(sir[0]);
    v.push_back(sir.back());
    sort(v.begin(),v.end());
    int ans = 1;
    for (int i = n; i >= 1; i--)
    {
        if (!insir[i])
        {
            nrr++;
            ans = (ans * (nrr - idk(i))) % modulo;
        }
    }
    cout << ans;
    return 0;
}
