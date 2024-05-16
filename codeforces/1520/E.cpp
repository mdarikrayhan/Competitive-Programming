/*                      ________________________
                       /      #
                      /     #   #
                     /        #
                    /
                   /       #   #
                  /      #        #
                 /                 #
                /                  #
               /                   #
              /                   #
             /                   #
\           /                   #
 \         /                  #
  \       /                 #
   \     /                 #
    \   /                 #       #
     \ /                    #   #
*/
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
#include <complex>
using namespace std;
const long double PI = 3.1415926535897932384626;
typedef long long ll;
typedef vector<ll> vli;
typedef pair<ll, ll> pii;
#define f first
// #define s second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define mod 1000000007
#define clr(x) memset(x, 0, sizeof(x))
#define gcd __gcd
#define middle(x) ceil2(x, 2) - 1
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define reverseall(x) reverse(all(x))
inline ll ceil2(ll a, ll b)
{
    return (a + b - 1) / b;
} // BE CAREFUL FOR NEGATIVES
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// DEBUG
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x);
template <typename T>
void __print(const vector<T> &x);
template <typename T>
void __print(const T &x);

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cout << '{';
    __print(x.first);
    cout << ',';
    __print(x.second);
    cout << "}";
}
template <typename T, typename V, typename U>
void __print(const tuple<T, V, U> &x)
{
    cout << '{';
    __print(get<0>(x));
    cout << ',';
    __print(get<1>(x));
    cout << ',' << get<2>(x);
    cout << "}";
}
template <typename T>
void __print(const vector<T> &x)
{
    cout << "{";
    for (int u69 = 0; u69 < x.size(); u69++)
    {
        __print(x[u69]);
        cout << (u69 + 1 == x.size() ? "" : ",");
    };
    cout << "}";
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cout << '{';
    for (auto &i : x)
        cout << (f++ ? "," : ""), __print(i);
    cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cout << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cout << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
//

// void fuck()
//{
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
// }

/*
------>do anything but don't stop..don't procastinate...
------>make test cases for n=1,n=0...baoundary cases..
*/

////bool get_ans(ll aux)
////{
////
////}
bool collinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (y1 - y2) * (x1 - x3) != (y1 - y3) * (x1 - x2);
}
bool isInt(float num)
{
    return (num == (int)num);
}
// returns the minimum of two numbers
// ll min(ll x, ll y)
//{
//     return y ^ ((x ^ y) & -(x < y));
// }
////returns the maximum of two numbers
// ll max(ll x, ll y)
//{
//     return x ^ ((x ^ y) & -(x < y));
// }
// addition of two integers
// int add(int a, int b)
//{
//     if (b == 0)
//         return a;
//     int sum = a ^ b;
//     int carry = (a & b) << 1;
//     return add(sum, carry);
// }
// iterative addition of two integers
// int Add(int a, int b)
//{
//     while (b != 0)
//     {
//         int sum = a ^ b;
//         int carry = (a & b) << 1;
//         a = sum;
//         b = carry;
//     }
//     return a;
// }
// recursive subtraction of two integers
// int subtract(int a, int b)
//{
//     if (b == 0)
//         return a;
//     return subtract((a ^ b), ((~a) & b) << 1);
// }
// iterative subtraction of two integers
// int Subtract(int x, int y)
//{
//     while (y != 0)
//     {
//         int borrow = (~x) & y;
//         x = x ^ y;
//         y = borrow << 1;
//     }
//     return x;
// }
//  Russian Peasant using bitwise operator
// multiplication function without using "*"
// int multiply(int a, int b)
//{
//     int res = 0;
//     while (b)
//     {
//         if (b & 1)
//         {
//             res = res + a;
//         }
//         a = a << 1;
//         b = b >> 1;
//     }
//     return res;
// }
// divide
// int divide(int a, int b)
//{
//     int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;
//     a = abs(a);
//     b = abs(b);
//     int q = 0, tmp = 0;
//     for (int i = 31; i >= 0; --i)
//     {
//         if (tmp + (b << i) <= a)
//         {
//             tmp += (b << i);
//             q |= (1LL << i);
//         }
//     }
//     return sign * q;
// }
// O(sqrt(n)) for below
// ll phi(ll n)
//{
//     ll res = n;
//     for (ll i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             res = res / i;
//             res = res * (i - 1);
//         }
//         while (n % i == 0)
//         {
//             n = n / i;
//         }
//     }
//
//     if (n > 1)
//     {
//         res = res * (n - 1);
//         res = res / n;
//     }
//     return res;
// }

// o(nlog(logn)) for below
// ll phi[1000006];
// void PHI()
//{
//     rep(i, 0, 1000006)
//     {
//         phi[i] = i;
//     }
//     rep(i, 2, 1000006)
//     {
//         if (phi[i] == i)
//         {
//             for (int j = i; j < 1000006; j = j + i)
//             {
//                 phi[j] = phi[j] * (i - 1);
//                 phi[j] = phi[j] / i;
//             }
//         }
//     }
// }
//  prefix function in better way
// vector<int> prefix_func(string s)
//{
//     ll n=s.length();
//     vector<int> prefix(n,0);
//     prefix[0]=0;
//     int j=0;
//     for(int i=1;i<n;i++)
//     {
//         j=prefix[i-1];
//         while(j>0 && s[i]!=s[j])
//         {
//             j--;
//         }
//         if(s[i]==s[j])
//         {
//             j++;
//         }
//         prefix[i]=j;
//     }
//
// return prefix;
// }
// int kmp(string s,string pat)
//{
//     //string s="abaaba";
//     vector<int> prefix=prefix_func(s);
//     //for(auto i:prefix)
//     //{
//     //    cout<<i<<"   ";
//     //}
//     //cout<<endl;
//     //string pat="aa";
//     ll n=s.size();
//     ll j=0;
//     ll pos=0;
//     for(int i=0;i<n;i++)
//     {
//         if(s[i]==pat[j])
//         {
//             i+=1;
//             j+=1;
//         }
//         else
//         {
//             if(j>0)
//             {
//                 j=prefix[j-1];
//             }
//             else
//             {
//                 i++;
//             }
//         }
//         if(j==pat.size())
//         {
//             //cout<<i<<endl;
//             pos=i-pat.size();
//             break;
//         }
//     }
//     //cout<<pos<<endl;
//     return pos;
// }
// vector<int> get_z(string s)
//{
//     /*
//     isme kya hota h ki z array k kisi v index pr jo value hoti h wo ye btati h ki
//     uss index se utne length(uss index ki value) ki prefix exist krti h string me...
//     example-
//             string str=" a b c d s j v j a b c h j"
//                      Z=                  3
//                      yha jo 3 h wo bta rha h ki abc 3 length ki as a prefix exist krti h...
//     */
///*
//        jo isme [l,r] hai wo ye bta rha h ki "l" to "r" ki jo substring hai prefix k
//        barabar ho chuki h...
//
//        */
//    int n=s.length();
//    //int z[n];
//    vector<int> z(n,0);
//    //for(int i=0;i<n;i++)
//    //{
//    //    cout<<z[i]<<"  ";
//    //}
//    //memset(z,0,n);
//    int l=0,r=0;
//    for(int i=0;i<n;i++)
//    {
//        if(i>r)
//        {
//            l=r=i;
//            while(r<n && s[r-l]==s[r])
//            {
//                r=r+1;
//            }
//            z[i]=r-l;
//            r--;
//        }
//        else
//        {
//            int idx=i-l;
//            if(z[idx]+i<=r)
//            {
//                z[i]=z[idx];
//            }
//            else
//            {
//                l=i;
//                while(r<n && s[r-l]==s[r])
//                {
//                    r++;
//                }
//                z[i]=r-l;
//                r--;
//            }
//        }
//    }
//    return z;
//}
// to get better results in decimal places..
// use double for better precision in decimal places
// cout<<fixed<<setprecision(10)<<ans<<endl;
// we get double/float as return in sqrt(blah_blah) function
// find euclidean distance
double euclid_dist(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt(abs(x1 - x2) * abs(x1 - x2) * 1.000 + abs(y1 - y2) * abs(y1 - y2) * 1.000);
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll binpow_mod(ll a, ll b, ll MOD)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = ((res % MOD) * (a % MOD)) % MOD;
        }
        b = b >> 1;
        a = ((a % MOD) * (a % MOD)) % MOD;
    }
    return res;
}

//***function to check whether a str2 is a substring of str1 or not.....
// bool check_substring(string str1,string str2)
//{
//    ll pos=0;
//    for(ll i=0;i<str1.size();i++)
//    {
//        if(str1[i]==str2[pos])
//        {
//            pos++;
//        }
//        if(pos==str2.size())
//        {
//            break;
//        }
//    }
//    if(pos==str2.size())
//    {
//        return true;
//    }
//    return false;
//}
// function to count the occurence of a character in string
// ll count_occurence(string str,char search)
//{
//    ll ans=0;
//    for(int i=0;i<str.size();i++)
//    {
//        if(search==str[i])
//        {
//            ans=ans+1;
//        }
//    }
//    return ans;
//}
// vector<ll> get_factors(ll n)
//{
//    vector<ll> v;
//    for (int i = 1; i <= sqrt(n); i++)
//    {
//        if (n % i == 0)
//        {
//            if (n / i == i)
//            {
//                v.push_back(i);
//            }
//            else
//            {
//                v.push_back(i);
//                v.push_back((n / i));
//            }
//        }
//    }
//    return v;
//}
//----convert a number(as string) to any base
// int convert(string s,int base)
//{
//    int pw=1;
//    int n=0;
//    for(int i=n-1;i>=0;i--)
//    {
//        if(val(s[i])>base)
//        {
//            return INT_MAX;
//        }
//        n=n+(val[s[i]])*base;
//        pw=pw*base;
//    }
//    return n;
//}

// GRAPH DFS---------------GRAPH ALGOS BELOW THIS-------
// vector<int> graph[(int)102];
// bool visited[105];
// bool flag = false;
// void dfs(int start, int finish)
//{
//     visited[start] = true;
//     if (start == finish)
//     {
//         flag = true;
//         return;
//     }
//     for (auto i : graph[start])
//     {
//         if (!(visited[i]))
//         {
//             dfs(i, finish);
//         }
//     }
// }
// class DisjSet
//{
//    // complexity 4*alpha...most optimised version
//    int *rank, *parent, n;
//    int *size;
//
// public:
//    DisjSet(int n)
//    {
//        size = new int[n];
//        parent = new int[n];
//        this->n = n;
//        makeSet();
//    }
//    void makeSet()
//    {
//        for (int i = 0; i < n; i++)
//        {
//            parent[i] = i;
//            size[i] = 1;
//        }
//    }
//    int find(int i)
//    {
//        if (i == parent[i])
//        {
//            return parent[i];
//        }
//        return parent[i] = find(parent[i]);
//    }
//    void Union(int u, int v)
//    {
//        int paru = find(u);
//        int parv = find(v);
//        if (paru ^ parv)
//        {
//            if (size[parv] > size[paru])
//            {
//                // bade me chote ko add krenge
//                size[parv] += size[paru];
//                parent[paru] = parv;
//            }
//            else
//            {
//                size[paru] += size[parv];
//                parent[parv] = paru;
//            }
//        }
//    }
//};
// ll binary_search(vector<ll> &vec, ll val)
//{
//     ll left = 0, right = vec.size() - 1;
//     while (left <= right)
//     {
//         ll mid = (left + right) / 2;
//         if (vec[mid] == val)
//         {
//             return mid;
//         }
//         else if (vec[mid] < val)
//         {
//             left = mid + 1;
//         }
//         else
//         {
//             right = mid - 1;
//         }
//     }
//     return right; //this will return a number jus less than 'val'
// }

string convert_binary(ll n)
{
    string str = "";
    while (n)
    {
        if (n & 1)
        {
            str.push_back('1');
        }
        else
        {
            str.push_back('0');
        }
        n = n / 2;
    }
    reverse(str.begin(), str.end());
    return str;
}
// vector<ll> ans, bag(2, 0);

// 2-d dfs waha tk chlana h jb tk feasible hp movement mtlb hm return tb hi honge jb out
//  of bound ki condition aayegi
// int cnates[1000][2];
// bool visi[1000];
// vector<ll> adj[105];
// void dfs(ll src)
//{
//     visi[src] = true;
//     for (auto i : adj[src])
//     {
//         if (!visi[i])
//         {
//             dfs(i);
//         }
//     }
// }
//----------------------------------------------
// const int N = 1e6 + 3;
// bool prime[N];
// vector<ll> det(N, 0);
// void seive(int n)
//{
//     memset(prime, true, sizeof(prime));
//     prime[0] = false;
//     prime[1] = false;
//     for (int i = 2; i <= n; i++)
//     {
//         if (prime[i])
//         {
//             for (int j = 2 * i; j <= n; j += i)
//             {
//                 prime[j] = false;
//             }
//         }
//     }
//     for (int i = 1; i < N; i++)
//     {
//         if (prime[i])
//         {
//             det[i] = det[i - 1];
//         }
//         else
//         {
//             det[i] = 1 + det[i - 1];
//         }
//     }
// }
/////////=-------------------------TARJAN's algorithm=-------------------O(V+E)////////
// vector<int> adj[100010];
// ll mini = INT_MAX;
// ll cnt, tot,ans;
// ll cst[100005];
// void dfs_for_tarjan(int u, vector<int> &disc, vector<int> &low, vector<bool> &instack, stack<int> &mystk)
//{
//     static int time = 0;
//     disc[u] = low[u] = time;
//    // cout<<time<<endl;
//     time = time + 1;
//     mystk.push(u);
//     instack[u] = true;
//     for (auto v : adj[u])
//     {
//         if (disc[v] == -1) //If nodes are not discovered yet
//         {
//             dfs_for_tarjan(v, disc, low, instack, mystk);
//             low[u] = min(low[u], low[v]);
//         }
//         else if (instack[v]) //it will be true when there will be a case of back edge
//         {
//             low[u] = min(low[u], disc[v]);
//         }
//     }
//     mini=INT_MAX;
//     if (disc[u] == low[u]) //IF u is head node of SCC
//     {
//         cnt=0;
//         //cout << "THE SCC IS:\n";
//         while (mystk.top() != u)
//         {
//             //  cout << mystk.top() << "  ";
//             if (cst[mystk.top()] < mini)
//             {
//                 mini = cst[mystk.top()];
//                 cnt = 0;
//             }
//             if (mini == cst[mystk.top()])
//             {
//                 cnt = cnt + 1;
//             }
//             instack[mystk.top()] = false;
//             mystk.pop();
//         }
//         //cout << mystk.top() << "\n";
//         //cout<<ans<<" "<<tot<<endl;
//         if (cst[mystk.top()] < mini)
//         {
//             mini = cst[mystk.top()];
//             cnt = 0;
//         }
//         if (mini == cst[mystk.top()])
//         {
//             cnt = cnt + 1;
//         }
//         //cout<<cnt<<endl;
//         instack[mystk.top()] = false;
//         mystk.pop();
//         ans=ans+mini;
//         tot=((tot%mod)*(cnt%mod))%mod;
//         //cout<<ans<<" "<<tot<<endl;
//     }
// }
// void get_SCC_tarjan(int V)
//{
//     vector<int> disc(V+1, -1), low(V+1, -1);
//     vector<bool> instack(V+1, false);
//     stack<int> mystk;
//     for (int i = 1; i <= V; i++)
//     {
//         if (disc[i] == -1)
//         {
//             dfs_for_tarjan(i, disc, low, instack, mystk);
//         }
//     }
// }
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//-----------------------------DFS FOR TREE------------------------------------------
//-----------------------------------------------------------------------------------
// const int maxn = 100005;
// vector<ll> adj[maxn];
// vector<bool> visited(maxn, 0);
// ll dp[maxn];
// ll ok;  //
// ll ans; //
// ll a[maxn];
// void dfs(int curr, int par, int cnt)
//{
//     if (visited[curr])
//     {
//         return;
//     }
//     visited[curr] = true;
//
//     //if (par != -1)
//     //{
//     //    dp[curr] = dp[par] + 1;
//     //}
//     for (ll i = 0; i < adj[curr].size(); i++)
//     {
//         ll next = adj[curr][i];
//         if (par != next)
//         {
//             if (a[next] == 1 && a[curr] == 1)
//             {
//                 dfs(next, curr, cnt + 1);
//             }
//             else
//             {
//                 dfs(next, curr,a[next]);
//             }
//         }
//     }
// }
//----------------------------------------------------------------------------------
//------------------------------------BFS----------------------------------------------
// const int maxn = 20000;
// vector<ll> adj[maxn];
// ll ans[100000];
// vector<bool> visited(100000, 0);
// bool flag=false;
// void bfs(int i, int j)
//{
//     queue<ll> q;
//     q.push(i);
//     ans[i]=0;
//     while (!(q.empty()))
//     {
//         ll src = q.front();
//         q.pop();
//        //cout<<src<<" ";
//         for (auto ii : adj[src])
//         {
//             if (!(visited[ii]))
//             {
//                 visited[ii]=true;
//                 ans[ii]=ans[src]+1;
//                 q.push(ii);
//                 if (ii == j)
//                 {
//                     flag = true;
//                     break;
//                 }
//             }
//         }
//         if(flag)
//         {
//             break;
//         }
//     }
//     //cout<<"\n";
//     return;
// }
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//--------------------------------LCS------------------------------------------------
// ll dp[5005][5005];
// ll lcs(string s1,string s2)
//{
//     for(int i=0;i<s1.size();i++)
//     {
//         dp[0][i]=0;
//     }
//     for(int i=0;i<s2.size();i++)
//     {
//         dp[i][0]=0;
//     }
//     for(int i=1;i<=s1.size();i++)
//     {
//         for(int j=1;j<=s2.size();j++)
//         {
//             if(s1[i-1]==s2[j-1])
//             {
//                 dp[i][j]=dp[i-1][j-1]+1;
//             }
//             else
//             {
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//
//     //printing of lcs
//     string ans;
//     int i=s1.size();
//     int j=s2.size();
//     while(i>0 && j>0)
//     {
//         if(s1[i-1]==s2[j-1])
//         {
//             ans.push_back(s1[i-1]);
//             i--,j--;
//         }
//         else if(dp[i-1][j]>dp[i][j-1])
//         {
//             i--;
//         }
//         else
//         {
//             j--;
//         }
//     }
//     reverse(ans.begin(),ans.end());
//     cout<<ans<<"\n";
//     return dp[s1.size()][s2.size()];
// }
// vector<pair<int, int>> adj[100005];
// vector<int> v[100005];
// ll findshortest(int src, int n)
//{
//     ll dist[n + 1];
//     for (int i = 0; i <= n; i++)
//     {
//         dist[i] = INT_MAX;
//     }
//     dist[src] = 0;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     pq.push({0, src});
//     while (!pq.empty())
//     {
//         auto node = pq.top().second;
//         auto dis = pq.top().first;
//         pq.pop();
//         //cout<<node<<"\n";
//         if(v[node].size())
//         {
//             while(binary_search(v[node].begin(),v[node].end(),dis))
//             {
//                 dis++;
//             }
//         }
//         //cout<<"11\n";
//         for (auto it : adj[node])
//         {
//          //   cout<<it.first<<"  "<<it.second<<"\n";
//             if ((dis + it.second) < dist[it.first])
//             {
//                 dist[it.first] = dis + it.second;
//                 pq.push({dist[it.first], it.first});
//             }
//         }
//        // cout<<"123\n";
//     }
//     return dist[n];
// }
// vector<int> adj[200009];
// vector<int> height(200009, 0);
// vector<int> det_lev[200009];
// vector<int> out_degree(200009, -1);
// vector<int> parent(200009, 0);
// void dfs(int curr, int par, int level)
//{
//     parent[curr] = par;
//     height[curr] = level;
//     det_lev[level].push_back(curr);
//     out_degree[curr] = adj[curr].size() - 1;
//     for (auto it : adj[curr])
//     {
//         if (it != par)
//         {
//             dfs(it, curr, level + 1);
//         }
//     }
//     return;
// }
// bool mycomp(const pair<ll, ll> &a, const pair<ll, ll> &a)
//{
//     return a.first < b.second;
// }
// int reflec[10]={0,1,5,-1,-1,2,-1,-1,8,-1};//reflection of numbers in mirror
// const int INF = 1e9 + 7;
// const int maxn = 5e6 + 1;
// vector<int> prime_divisors_till(maxn, 0);
// void get_no_of_prime_divisors(vector<int> &prime_divisors_till, int maxn)
//{
//     vector<int> seive(maxn, 0);
//     vector<int> no_of_prime_divisors(maxn, 0);
//     for (int i = 2; i < maxn; i++)
//     {
//         if (seive[i] == 0)
//         {
//             for (int j = i; j < maxn; j = j + i)
//             {
//                 seive[j] = i;
//             }
//         }
//         int p = seive[i];
//         no_of_prime_divisors[i] = 1 + no_of_prime_divisors[i / p];
//         prime_divisors_till[i] += no_of_prime_divisors[i] + prime_divisors_till[i - 1];
//     }
// }
// ll n;
// ll dp[2005][2005];
// bool fun(vector<ll> &subset,ll i,ll sum)
//{
//     if(i==0)
//     {
//         if(sum==0)
//         {
//             return true;
//         }
//         return false;
//     }
//     if(dp[i][sum]!=-1)
//     {
//         return dp[i][sum];
//     }
//     bool ans=false;
//     if(sum-subset[i-1]>=0)
//     {
//         ans|=fun(subset,i-1,sum-subset[i-1]);
//     }
//     ans|=fun(subset,i-1,sum);
//     return dp[i][sum]=ans;
// }
/*
ll check(string str1, string str2)
{
    if (str2.find(str1) != string::npos)
    {
        return 1;
    }
    return 0;
}
*/
ll findMex(vli arr, ll n)
{
    sort(arr.begin(), arr.end());
    if (arr[0] != 0)
        return 0;
    rep(i, 1, n - 1)
    {
        if (arr[i] - arr[i - 1] <= 1)
            continue;
        return arr[i - 1] + 1;
    }
    return arr[n - 1] + 1;
}
const int maxn = 2e5 + 5;

vector<int> convert_string(ll a)
{
    vector<int> ans;
    ll b = a;
    while (b)
    {
        ans.push_back(b % 10);
        b /= 10;
    }
    return ans;
}

// vector<int> level(200005, 0);
// ll parent[200005][22];
// ll n, q;
// void dfs(int curr, int par, int h)
//{
//     level[curr] = h;
//     if (par != -1)
//     {
//         parent[curr][0] = par;
//     }
//     for (auto it : adj[curr])
//     {
//         if (it != par)
//         {
//             dfs(it, curr, h + 1);
//         }
//     }
// }
// void preprocess_lca()
//{
//     dfs(1, -1, 1);
//
//     for (int j = 1; j <= 21; j++)
//     {
//         //cout<<parent[i][0]<<" ";
//         for (int i = 1; i <= n; i++)
//         {
//             parent[i][j] = parent[parent[i][j - 1]][j - 1];
//             //  cout<<parent[i][j]<<" ";
//         }
//         //cout<<"\n";
//     }
// }
//
// void query(ll x, ll k)
//{
//     int cnt = 0;
//     while (k)
//     {
//         if (k & 1)
//         {
//             x = parent[x][cnt];
//         }
//         cnt += 1;
//         k = k >> 1;
//     }
//     if (x != 0)
//     {
//         cout << x << "\n";
//     }
//     else
////    {
////        cout << "-1\n";
////    }
////    return;
////}
vector<bool> prime;
// void seive(int n)
//{
//     prime[0] = false;
//     prime[1] = false;
//     prime[2] = true;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (prime[i])
//         {
//             for (int j = 2 * i; j <= n; j += i)
//             {
//                 prime[j] = false;
//             }
//         }
//     }
// }

// int diameter = 0;
// vector<int> adj[200005];
// vector<int> dp1(200005, 0); //stores the value of max of l,r
// vector<int> dp2(200005, 0); //stores the value of 1+l+r
// void dfs_for_diameter(int curr, int par)
//{
//     vector<int> fvalues;
//     bool leaf = true;
//     for (auto it : adj[curr])
//     {
//         if (it == par)
//         {
//             continue;
//         }
//         leaf = false;
//         dfs_for_diameter(it, curr);
//         fvalues.push_back(dp1[it]);
//     }
//     if (leaf)
//     {
//         dp1[curr] = 0;
//         return;
//     }
//     sort(fvalues.begin(), fvalues.end());
//     dp1[curr] = 1;
//     if (!fvalues.empty())
//     {
//         dp1[curr] += fvalues.back();
//     }
//     if (fvalues.size() >= 2)
//     {
//         dp2[curr] = 2 + fvalues.back() + fvalues[fvalues.size() - 2];
//     }
//     diameter = max(diameter, max(dp1[curr], dp2[curr]));
// }
/*
int freq[26] = {0};
ll n, k;
string str;
ll even, odd;
bool check_bsa(int mid)
{
    ll ev = even, od = odd;
    for (int i = 0; i < k; i++)
    {
        if ((mid % 2) == 1)
        {
            if (od > 0)
            {
                od--;
                ev -= (mid - 1);
            }
            else
            {
                ev -= (mid + 1);
                od++;
            }
        }
        else
        {
            ev -= mid;
        }
    }
    if (ev < 0)
    {
        return false;
    }
    return true;
}
vector<int> convert_to_vec(string str)
{
    vector<int> v;
    for (auto it : str)
    {
        v.push_back(it - '0');
    }
    return v;
}


int vis[100005];
int dist[100005];
vector<pair<int,int>> adj[100005];
struct node
{
    int zero;
    int one;
};
*/
// ll sm;
// ll n,m,k;
// ll recur(ll i,ll k_aux,vector<ll> &weight)
//{
//     if(k_aux==k)
//     {
//         if(i==m)
//         {
//             return 1;
//         }
//         return 0;
//     }
//     ll pick=0,unpick=0;
//     for(int idx=i+1;i<n;i++)
//     {
//         pick+=((weight[idx]/sum)%mod)*(recur(idx+1,k_aux+1,weight))%mod)%mod;
//     }
//     pick+=((weight[idx]/sum)%mod)*(recur(idx,k_aux+1,weight))%mod)%mod;
// }

string removeLeadingZeros(string &num)
{
    int i = 0;
    while (num[i] == '0')
        i++;

    return num.substr(i);
}

int compareTwoLargeNumbers(string &str1, string &str2)
{
    // string str1 = removeLeadingZeros(num1);
    // string str2 = removeLeadingZeros(num2);

    int str1_length = str1.size();
    int str2_length = str2.size();

    if (str1_length != str2_length)
        return str1_length < str2_length ? 1 : 2;
    else
    {
        for (int i = 0; i < str1_length; i++)
        {
            if (str1[i] > str2[i])
                return 2;
            else if (str2[i] > str1[i])
                return 1;
        }
    }

    return 3;
}

// in multiset always use pointer ..m_st.begin()..also for erasing
// in multiset use m_st.empty()..rather than for loop

vector<ll> get_diff(vector<ll> v)
{
    vector<ll> ans;
    for (int i = 0; i < (v.size()) - 1; i++)
    {
        ans.push_back(v[i + 1] - v[i]);
    }

    return ans;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(vli v, int n)
{
    ll ans = v[0];

    for (int i = 1; i < n; i++)
        ans = (((v[i] * ans)) /
               (gcd(v[i], ans)));

    return ans;
}

// void dfs(ll src, ll par, ll level, vector<ll> &parent, vector<vli> &adj)
//{
//     debug(src);
//     parent[src] = par;
//     if (mini_lev < level and ((int)adj[src].size() == 1))
//     {
//         mini_lev = level;
//         mini_leaf = src;
//     }
//     for (auto it : adj[src])
//     {
//         if (it != par)
//         {
//             dfs(it, src, level + 1, parent, adj);
//         }
//     }
// }

bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}

string findDiff(string str1, string str2)
{
    if (isSmaller(str1, str2))
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    for (int i = 0; i < n2; i++)
    {

        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());

    return str;
}

ll ans = 0;

ll dfs(int src, vector<vector<int>> &v, vector<vector<int>> &adj)
{
    ll sum = 0;

    for (auto it : adj[src])
    {
        sum += (dfs(it, v, adj));
    }

    if (sum < (ll)v[src][0])
    {
        ans++;
        return v[src][1] * 1ll;
    }

    return min(v[src][1] * 1ll, sum);
}

/*
vector<int> subtree;
bool visi[100005];
void dfs(int src, vector<vector<ll>> &adj)
{
    visi[src] = 1;
    // debug(src);
    for (auto it : adj[src])
    {
        // debug(it);
        if (!visi[it])
        {
            dfs(it, adj);
            subtree[src] += subtree[it];
            // debug(subtree);
        }
    }

    if ((int)adj[src].size() == 0)
    {
        // debug(subtree);
        subtree[src] = 1;
    }
}
*/
void update(vector<ll> &fenwick, ll i, ll val)
{
    while (i < (int)fenwick.size())
    {
        fenwick[i] += val;
        i += (i & (-i));
    }
}
ll sum(vector<ll> &fenwick, ll i)
{
    ll sm = 0;
    while (i > 0)
    {
        sm += (fenwick[i]);
        i -= (i & (-i));
    }
    return sm;
}
ll count_primes(ll a)
{
    ll cnt = 0;
    ll n = a;
    while ((a % 2) == 0)
    {
        cnt += 1;
        a /= 2;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        while ((a % i) == 0)
        {
            a /= i;
            cnt += 1;
        }
    }
    if (a > 1)
    {
        cnt += 1;
    }
    return cnt;
}
ll high_prime_factor(ll n)
{
    ll ans = 1;
    for (ll i = 1; i * i <= n; i += 1)
    {
        if (prime[i])
        {
            if (n % i == 0)
            {
                ans = max({ans, i, n / i});
            }
        }
    }

    return ans;
}
// class segment_tree
//{
// public:
//     // lo,hi-->arrray ka hota h
//     vli arr, segtree;
//     segment_tree(vli &v)
//     {
//         int n = v.size();
//         arr.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             arr[i] = v[i];
//         }
//         segtree.resize(4 * n);
//         for (int i = 0; i < 4 * n; i++)
//         {
//             segtree[i] = 0;
//         }
//         build(0, 0, n - 1);
//     }
//     void build(int indx, int lo, int hi)
//     {
//         if (lo == hi)
//         {
//             segtree[indx] = arr[lo];
//             return;
//         }
//
//         int mid = lo + (hi - lo) / 2;
//
//         build(2 * indx + 1, lo, mid);
//         build(2 * indx + 2, mid + 1, hi);
//
//         segtree[indx] = max(segtree[2 * indx + 1], segtree[2 * indx + 2]);
//     }
//     void update(int indx, int lo, int hi, int i, int val)
//     {
//         if (lo == hi)
//         {
//             arr[i] = val;
//             segtree[indx] = val;
//         }
//         int mid = lo + (hi - lo) / 2;
//         if (i <= mid)
//         {
//             update(2 * indx + 1, lo, mid, i, val);
//         }
//         else
//         {
//             update(2 * indx + 2, mid + 1, hi, i, val);
//         }
//
//         segtree[indx] = max(segtree[2 * indx + 1], segtree[2 * indx + 2]);
//     }
//     int range(int indx, int lo, int hi, int l, int r)
//     {
//         if (lo >= l and hi <= r)
//         {
//             return segtree[indx];
//         }
//         if (l > hi or r < lo)
//         {
//             return INT_MIN;
//         }
//         int mid = lo + (hi - lo) / 2;
//
//         int left = range(2 * indx + 1, lo, mid, l, r);
//         int right = range(2 * indx + 2, mid + 1, hi, l, r);
//
//         return max(left, right);
//     }
// };

//vector<vector<int>> dir = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

bool is_sorted(vli &v)
{
    ll n=v.size();
    for(int i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
            return false;
        }
    }

    return true;
}
//try to get the glimpse of wuestion from reading and try to find answer
//if still not ,get through example,u might get observation from there
//if not getting any single idea,try to go for reversing the operation
//if failing ,try to copy the operation to the inner elements of array
//instead of just the boundaries

// void dfs(int src,int par)
// {
//     for(auto it:adj[src])
//     {
//         if(src!=par)
//         {
//             dfs(it.src);
//         }
//     }
// }
void solve()
{
    ll n;
    cin>>n;

    string str;
    cin>>str;
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='*')
        {
            cnt++;
        }
    }
    debug(cnt);
    ll mid=-1;
    ll curr=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='*')
        {
            curr++;
            if(curr==((cnt+1)/2))
            {
                mid=i;
                break;
            }
        }
    }

    curr=mid-((cnt+1)/2);
    curr+=1;
    debug(curr);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='*')
        {
            ans+=abs(curr-i);
            curr++;
        }
    }
    cout<<ans<<"\n";
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout.precision(12);
    // FIO
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // get_no_of_prime_divisors(prime_divisors_till, maxn);
    //ios::sync_with_stdio(false);
    //cin.tie(NULL); // Remove in problems with online queries!
    ll t;
    // scanf("%lld", &t);
    //t = 1;
    cin >> t;
    // vector<ll> val((int)1e6+7,0);
    // prime.resize(1000005, true);
    // seive(1000005);
    //cout<<1<<"\n";
    //debug(t);
    
    for (int i = 1; i <= t; i++)
    {
        //cout<<"1\n";
        solve();
    }

    return 0;
}
// std::fill(vec.begin(),vec.end(),1)
// dp me chote se bda leke jana h..
// An array d is a subarray of an array c if d can be obtained from c by deletion of
// several (possibly, zero or all)
// elements from the beginning and several (possibly, zero or all) elements from the end.