#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int ll
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
typedef pair<int, int> pii;
const int inf=INT_MAX;
const int maxn=3e5+10;
const int maxl=19;

int n, q;
int a[maxn];
vector<int> vq[maxn]; // queries pra cada cara
int id[maxl][maxn]; // id meu no path, 0 se eu não to no path
int pega[maxl][maxn]; // para todo cara e path, maior id no path que eu alcanço
// path de tamanho t tem ids t, t-1, ..., 2, 1, onde t é o cara mais acima

vector<int> path[maxl];

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
    #endif
    ios::sync_with_stdio(0);cin.tie(0);

    cin>> n>> q;
    for(int i=1; i<=n; i++)
        cin>> a[i];
    for(int b=0; b<maxl; b++)
    {
        for(int i=n; i>=1; i--)
            if(a[i]&(1<<b))
                path[b].pb(i);
        for(int i=0; i<path[b].size(); i++)
            id[b][path[b][i]] = i+1;
    }
    for(int i=n; i>=1; i--)
    {
        for(int b=0; b<maxl; b++)
        {
            if(id[b][i])
            {
                pega[b][i] = id[b][i];
                if(id[b][i] > 1)
                {
                    int j = path[b][id[b][i] - 2];
                    for(int c=0; c<maxl; c++)
                        pega[c][i] = max(pega[c][i], pega[c][j]);
                }
            }
        }
    }
    while(q--)
    {
        int x, y; cin>> x>> y;
        bool found = false;
        for(int b=0; b<maxl; b++)
        {
            if(id[b][y])
            {
                if(pega[b][x] >= id[b][y])
                    found = true;
            }
        }
        cout<< (found ? "Shi\n" : "Fou\n");
    }

    return 0;
}