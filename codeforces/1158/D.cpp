#include<bits/stdc++.h>
#define int long long
using namespace std;
int ccw(pair<int, int> A, pair<int, int> B, pair<int, int> C)
{
    pair<int, int> AB = make_pair(B.first - A.first, B.second - A.second);
    pair<int, int> AC = make_pair(C.first - A.first, C.second - A.second);
    int val = AB.first * AC.second - AB.second * AC.first;
    if(val > 0) return 1;
    else if(val == 0) return 0;
    else return -1;
}
vector<int> ans;
pair<int, int> p[2001];
bool visited[2001];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>p[i].first>>p[i].second;
    int cur = 0;
    for(int i = 1; i <= n; i++) if(cur == 0 || p[i].first < p[cur].first) cur = i;
    ans.push_back(cur); visited[cur] = 1;
    string s; cin>>s;
    for(int i = 0; i < n-2; i++){
        int v = 0;
        for(int j = 1; j <= n; j++) if(visited[j] == 0 && (v == 0 || (ccw(p[cur], p[v], p[j]) == (int)(s[i] == 'R')*2-1))) v = j;
        cur = v; ans.push_back(cur); visited[cur] = 1;
    }
    for(int i = 1; i <= n; i++) if(visited[i] == 0) ans.push_back(i);
    for(int i : ans) cout<<i<<" ";
}

