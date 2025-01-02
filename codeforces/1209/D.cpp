#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb  push_back
#define mp  make_pair
#define IO_FAST                 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define testcase                int t; cin >> t; while(t--)
#define inputvec(v1, n)         for(int i=0; i<n; i++) {int x; cin >> x; v1.pb(x);}
#define inputvecp(v1, n)        for(int i=0; i<n; i++) {int x, y; cin >> x >> y; v1.pb(mp(x,y));}
#define sort(v1)                sort(v1.begin(), v1.end())
#define reverse(v1)             reverse(v1.begin(), v1.end())
#define deb(x)                  cout << #x << ' ' <<  '=' << ' ' << x << endl;
#define print(x)                cout << #x << endl;
#define tolower(s1)             transform(s1.begin(), s1.end(), s1.begin(), ::tolower)
#define toupper(s1)             transform(s1.begin(), s1.end(), s1.begin(), ::toupper)
#define upperbound(v1, k)       upper_bound(v1.begin(), v1.end(), k)
#define lowerbound(v1, k)       lower_bound(v1.begin(), v1.end(), k)
#define auto1(v1)               for(auto &num1:v1) {cout << num1 << ' ';} cout << endl;
#define auto2(vp1)              for(auto &num1:vp1) {cout << num1.first << ' ' <<num1.second << endl;}
#define auto3(vv1)				for(auto &num1:vv1) {for(auto &num2:num1){cout << num2 <<' ';}cout<<endl;}
int gcd(int a,int b)            {if (b==0) return a; return gcd(b, a%b);} // take a=0;
int lcm(int a,int b)            {return a/gcd(a,b)*b;}  // take a = v[0];
const int N = 1e5+10;
const int mod = 1e9+7;
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
//======================================================================================================//
void dfs(int vertex, int &cnt, vector<int> &vis, vector<vector<int>> &graph)
{
    cnt++;
    vis[vertex] = 1;

    for(auto &value : graph[vertex])
    {
        if(vis[value]==-1)
        {
            dfs(value, cnt, vis, graph);
        }
    }
}
signed main()
{
    IO_FAST
    int n, k;
    cin >> n >> k;

    vector<vector<int>> graph(n+1);
    vector<int> vis(n+1, -1);

    for(int i=0; i<k; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int count=0;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==-1 && graph[i].size()>0)
        {
            int cnt = 0;
            dfs(i, cnt, vis, graph);
            count += (cnt-1);
        }
    }

    cout << k-count << endl;
}