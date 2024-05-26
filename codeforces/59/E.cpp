#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, M, K, X, Y, Z;
    cin >> N >> M >> K;
    set < vector <ll> > no;
    vector <ll> graf[N + 1];
    queue < pair <ll, ll> > q;
    vector < vector <ll> > dist(N + 1, vector <ll> (N + 1, 2e18));
    vector < vector <bool> > pos(N + 1, vector <bool> (N + 1));
    for(int i = 0; i < M; i++)
    {
        cin >> X >> Y;
        graf[X].push_back(Y);
        graf[Y].push_back(X);
    }
    for(int i = 0; i < K; i++)
    {
        cin >> X >> Y >> Z;
        no.insert({X, Y, Z});
    }
    q.push({0, 1});
    dist[0][1] = 0;
    while(q.size())
    {
        ll prev = q.front().first;
        ll now = q.front().second;
        q.pop();
        for(auto next : graf[now])
        {
            if(pos[now][next]) continue;
            if(no.find({prev, now, next}) != no.end()) continue;
            pos[now][next] = true;
            dist[now][next] = min(dist[now][next], dist[prev][now] + 1);
            q.push({now, next});
        }
    }
    ll rez = 2e18;
    for(int i = 1; i <= N; i++) rez = min(rez, dist[i][N]);
    if(rez == 2e18) {cout << -1 << endl; return 0;}
    cout << rez << endl;
    vector <ll> path;
    path.push_back(N);
    ll node = N;
    while(node != 1)
    {
        for(int i = 1; i <= N; i++)
        {
            if(dist[i][node] == rez)
            {
                rez--;
                node = i;
                path.push_back(node);
                break;
            }
        }
    }
    reverse(path.begin(), path.end());
    for(auto node : path) cout << node << " ";
    return 0;
}
