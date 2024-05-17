#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <map>
#include <unordered_map>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

using namespace std;

#define ll long long
#define llu long long unsigned
#define f(i, n) for (int i = 0; i < n; i++)
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fe(i, n) for (int i = 0; i <=  n; i++)
#define fie(i, a, n) for (int i = a; i <= n; i++)
#define fii(i, n, a) for (int i = n; i > a; i--)
#define fcin(n, arr)            \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> arr[i];          \
    }

#define ve vector
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define vpi vector<pii>
#define vpl ve<pll>
#define vl vector<loc>
#define vvb ve<vb>
#define vvl ve<vll>
#define vvi ve<vi> 
#define ev(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define stg string

using namespace std;

#define p 101
// ll modd=998244353ll;
ll mod=1e9+7ll;
// ll mod=modd;
void printl(int a, int b, int c, int d)
{
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
}
void print(vector<int> &a)
{
    f(i, a.size())
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void printb(vb &a)
{
    f(i, a.size())
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void printl(vll &a)
{
    f(i, a.size())
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
class DSU
{
public:
    vi rank, parent, size;
    int diff;
    DSU(int n)
    {
        rank = vi(n, 0);
        f(i, n)
        {
            parent.pb(i);
        }
        size = vi(n, 1);
        diff = n;
    }
    int find(int u)
    {
        int par = parent[u];
        if (par == u)
        {
            return u;
        }
        return parent[u] = find(par);
    }
    void uni_rank(int u, int v)
    {
        int par1 = find(u);
        int par2 = find(v);
        if (par1 == par2)
        {
            return;
        }
        int r1 = rank[par1];
        int r2 = rank[par2];
        if (r1 < r2)
        {
            parent[par1] = par2;
        }
        else if (r1 > r2)
        {
            parent[par2] = par1;
        }
        else
        {
            parent[par1] = par2;
            rank[par2]++;
        }
        diff--;
    }
    void uni_size(int u, int v)
    {
        int par1 = find(u);
        int par2 = find(v);
        if (par1 == par2)
        {
            return;
        }
        int r1 = size[par1];
        int r2 = size[par2];
        if (r1 < r2)
        {
            parent[par1] = par2;
            size[par2] += r1;
        }
        else
        {
            parent[par2] = par1;
            size[par1] += r2;
        }
    }
};

class loc
{
public:
    int redp,bluep;
    bool is_redg,is_blueg;
    loc(char a)
    {
        
    }
    loc(){
        is_redg=false;
        is_blueg=false;
        redp=0;
        bluep=0;
    }
};
ll power(ll a, ll m)
{
    if(m==0ll){
        return 1ll;
    }
    if (m == 1ll)
    {
        return (a * m) % mod;
    }
    ll halv = (power(a, m >> 1));
    if (m & 1ll)
    {
        return ((((halv % mod) * (halv % mod)) % mod) * a) % mod;
    }
    return (halv * halv) % mod;
}
ll inv(ll a)
{
    return power(a, mod - 2ll);
}
void yay(bool c)
{
    if (c)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

// void bfs(vi &dist, int nd, ve<vi> &tree)
// {
//     queue<int> q;
//     dist[nd] = 0;
//     q.push(0);
//     while (!q.empty())
//     {
//         int p = q.front();
//         q.pop();
//         int m = tree[p].size();
//         f(i, m)
//         {
//             nd=tree[p][i];
//             if (dist[nd]<0)
//             {
//                 dist[nd] = dist[p] + 1;
//                 q.push(nd);
//             }
//         }
//     }
// }


// void maxd(ve<vi> &tree, vi &dist0, vi &dist1, vi &dist2, vi &dist)
// {
//     int n = tree.size();
//     bfs(dist0, 0, tree);
//     int max1 = 0, max2 = 0;
//     f(i, n)
//     {
//         if (dist0[i] > dist0[max1])
//         {
//             max1 = i;
//         }
//     }
//     bfs(dist1, max1, tree);
//     f(i, n)
//     {
//         if (dist1[i] > dist1[max2])
//         {
//             max2 = i;
//         }
//     }
//     bfs(dist2, max2, tree);
//     f(i, n)
//     {
//         dist[max(dist1[i], dist2[i])]++;
//     }
// }
// void build(ve<vi> &child, ve<vi> &par, int i, int j)
// {
//     if (j == par.size())
//     {
//         return;
//     }
//     if (par[j][i - 1] != -1)
//     {
//         par[j][i] = par[par[j][i - 1]][i - 1];
//     }
//     int n = child[j].size();
//     f(k, n)
//     {
//         build(child, par, i, child[j][k]);
//     }
// }
// int get(int x,int k,ve<vi>& par){
//     int j = 0;
//     while (k > 0)
//     {
//         if (k & 1)
//         {
//             x = par[x][j];
//         }
//         j++;
//         k >>= 1;
//     }
//     return x;
// }
// int fin(int a,int b,ve<vi>& par,vi& lev,int maxx){
//     if(a==b){
//         return b;
//     }
//     while(maxx>=0){
//         if(par[a][maxx]!=par[b][maxx]){
//             a=par[a][maxx];
//             b=par[b][maxx];
//         }
//         maxx--;
//     }
//     return par[a][0];
// }

 
// A function to check if a string str is palindrome
// in the range L to R

void rev(ve<loc>& v){
    int n=v.size();
    f(i,(n/2)){
        swap(v[i],v[n-1-i]);
    }
}

ll ans(ve<vi>& adj,int curr,int par,ll& maxx){
    int n=adj[curr].size();
    ll ok=adj.size();
    ll sz=1ll;
    f(i,n){
        if(adj[curr][i]!=par){
            ll siz=ans(adj,adj[curr][i],curr,maxx);
            cout<<curr<<" "<<par<<" "<<siz<<endl;
            sz+=siz;
            maxx=min(maxx,siz*siz+(ok-siz)*(ok-siz));
        }
    }
    maxx=min(maxx,sz*sz+(ok-sz)*(ok-sz));
    return sz;
}
void move(int& x,int& y,char c){
    if(c=='L'){
        y--;
    }
    else if(c=='D'){
        x++;
    }
    else if(c=='R'){
        y++;
    }
    else{
        x--;
    }
}
ll calc(vvl& dp,int ind,int last,vll& satis,int toton,ve<vll>& rules,int& n,int& m){
    if(toton==0){
        return 0ll;
    }
    if(dp[ind][last+1]!=-1ll){
        return dp[ind][last+1];
    }
    f(i,n){
        if((ind&(1<<i))){
            int newind=ind-(1<<i);
            dp[ind][last+1]=max(calc(dp,newind,i,satis,toton-1,rules,n,m)+rules[i+1][last+1]+satis[i+1],dp[ind][last+1]);
        }
    }
    return dp[ind][last+1];
}
int gcd(int a,int b){
    if(a==0 || b==0){
        return a^b;
    }
    if(a>=b){
        return gcd(b,a%b);
    }
    return gcd(a,b%a);
}


 
int comp(vvi& dp,int n,int m,string& s1,string& s2){
    if(n<0 || m<0){
        return m+n+2;
    }
    if(dp[n][m]!=1e6){
        return dp[n][m];
    }
    if(s1[n]==s2[m]){
        return dp[n][m]=comp(dp,n-1,m-1,s1,s2);
    }
    return dp[n][m]=min(min(comp(dp,n-1,m,s1,s2),comp(dp,n,m-1,s1,s2)),comp(dp,n-1,m-1,s1,s2))+1;
}
int main()
{
    int t;
    int n, x, y,m;
    int q, l, r, d;
    int a, b, time;
    int k;
    string inp, str;
    char c,cc, trump;
    cin>>t;
    while(t--){
        cin>>n;
        vi arr(n);
        fcin(n,arr);
        vi count(1e5+1,0);
        f(i,n){
            count[min(arr[i],(int)1e5)]++; 
        }
        int mex=1e5;
        f(i,1e5){
            if(count[i]==0){
                mex=i;
                break;
            }
        }
        cout<<mex<<endl;
        f(i,n+1){
            cin>>y;
            if(y==-1){
                break;
            }
            cout<<y<<endl;
        }
    }
    
 
    
    return 0;
}

