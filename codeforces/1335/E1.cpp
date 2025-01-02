#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int v[N], pre[N][26];
vector<int> ind[27];

int main() 
{
    ios::sync_with_stdio(false), cin.tie(0);

    int cases;

    for(cin >> cases; cases--;)
    {
        int n, res = 0, cnt[27] = {0};
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> v[i];
        for (int i = 1; i <= n; i++) cnt[v[i]]++;
        res = max(res, *max_element(cnt, cnt + 27));
        for (int j = 1; j <= 26; j++)
            ind[j].clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 26; j++)
                pre[i][j] = pre[i - 1][j];
            pre[i][v[i]]++;
            ind[v[i]].push_back(i);
        }
        for (int p = 1; p <= 26; p++) {
            if(ind[p].size() <= 1) continue;
            int ll = 0, rr = ind[p].size() - 1, low, high, T = 2;
            while (ll < rr) {
                low = ind[p][ll], high = ind[p][rr] ;
                for (int i = 1; i <= 26; i++)
                    res = max(res, T + pre[high - 1][i] - pre[low][i]);
                T += 2; ll++, rr--;
            }
        }
        cout << res << '\n';        
    }
}