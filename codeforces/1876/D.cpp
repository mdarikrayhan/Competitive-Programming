#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

ll N = 998244353;

ll mpow(ll a, ll n)
{
    if(n<0) return 0;
    if(n==0) return 1;

    ll x = mpow(a, n/2);
    x *= x;
    x %= N;

    if(n%2==0) return x;
    else return (x * a) % N;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	set<int> c;
	for(int i=0; i<n; i++) c.insert(a[i]);

	vector<vector<int>> adj(200001);
	vector<int> cnt(200001, 0);
	int x = 0;

	bool ok = true;
	queue<int> Q;

	for(int i=0; i<n; i++)
    {
        cnt[a[i]]++;

        if(cnt[a[i]] % 2 == 0)
        {
            if(Q.front()!=a[i]) ok = false;
            Q.pop();
            x--;
        }
        else
        {
            Q.push(a[i]);
            x++;
        }

        if(x!=0 && i != n-1)
        {
            adj[a[i]].pb(a[i+1]);
            adj[a[i+1]].pb(a[i]);
        }
    }

    int cc = 0;
    vector<bool> visited(200001, false);
    for(int i=0; i<=200000; i++)
    {
        if(!visited[i])
        {
            cc++;
            queue<int> Q;
            Q.push(i);
            visited[i] = true;

            while(!Q.empty())
            {
                int p = Q.front();
                Q.pop();

                for(int c: adj[p])
                {
                    if(!visited[c])
                    {
                        visited[c] = true;
                        Q.push(c);
                    }
                }
            }
        }
    }

    //cout << c.size() << " " << cc - 200001 + c.size() << "\n";
    if(x==0 && ok) cout << (N + mpow(2, c.size() - 1) - mpow(2, cc - 200002 + c.size())) % N;
    else cout << mpow(2, c.size() - 1);
}
