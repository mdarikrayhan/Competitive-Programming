#include <vector>
#include <iostream>
#include <queue>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define INF 100000000000000000
class Compare
{
public:
    bool operator()(const std::vector<int64_t> &a, const std::vector<int64_t> &b) const
    {
        if (a[1] != b[1])
        {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v] = rank[ulp_v] + rank[ulp_u];
        }
        else if (rank[ulp_v] <= rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u] = rank[ulp_v] + rank[ulp_u];
        }
    }
};
struct Node
{
    int data;
    Node *left;
    Node *right;
};

int64_t fact(int64_t n)
{

    int64_t f = 1;
    for (int i = 1; i <= n; i++)
        f = (f * i) % mod;
    return f;
}
vector<int64_t> sieve(int n)
{
    vector<int64_t> ans(n + 1, 1);
    ans[1] = 0;
    for (int64_t i = 2; i * i <= n; i++)
    {
        if (ans[i] == 1)
        {
            for (int64_t j = 2; j * i <= n; j++)
            {
                ans[j * i] = 0;
            }
        }
    }

    return ans;
}

int64_t gcd(int64_t a, int64_t b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
int64_t lcm(int64_t a, int64_t b)
{
    return (a / gcd(a, b)) * b;
}

int isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int GcdOfArray(vector<int> &arr, int idx)
{
    if (idx == arr.size() - 1)
    {
        return arr[idx];
    }
    int a = arr[idx];
    int b = GcdOfArray(arr, idx + 1);
    return gcd(
        a, b);
}

int bs(vector<vector<int64_t>> &vp, int num, int l, int h)
{

    int ans = -1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (vp[mid][1] < num)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return ans;
}

void dfs(int src, vector<vector<int>> &adj, double &paths, int64_t &sum, vector<int> &visited, int length)
{

    visited[src] = 1;

    if (adj[src].size() == 1 && visited[adj[src][0]] == 1)
    {
        sum = sum + length;
        paths++;
        return;
    }

    for (int i = 0; i < adj[src].size(); i++)
    {

        if (visited[adj[src][i]] == 0)
        {
            dfs(adj[src][i], adj, paths, sum, visited, length + 1);
        }
    }
}

bool isneed(string s)
{
    string s1 = s;
    reverse(s.begin(), s.end());
    if (s < s1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int64_t binpow(int64_t a, int64_t b)
{
    a %= mod;
    int64_t res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<int> palindromes;

int helper(int n, int i, vector<vector<int>> &dp)
{

    if (n == 0)
    {
        return 1;
    }

    if (dp[n][i] != -1)
    {
        return dp[n][i];
    }

    if (n >= palindromes[i])
    {
        return dp[n][i] = (helper(n - palindromes[i], i, dp) + helper(n, i + 1, dp)) % mod;
    }
    return dp[n][i] = 0;
}

void addnum(int num, vector<int> &agg)
{

    string s = to_string(num);
    for (int i = 0; i < s.size(); i++)
    {
        agg.push_back(s[i] - '0');
    }
}

int64_t helper(int64_t sum, int state, vector<vector<int64_t>> &dp, int k, int d)
{
    if (sum == 0 && state == 1)
    {
        return 1;
    }

    else if (sum == 0 && state == 0)
    {
        return 0;
    }

    if (dp[sum][state] != -1)
    {
        return dp[sum][state];
    }
    int64_t ans = 0;

    for (int j = 1; j <= k; j++)
    {
        if (sum >= j)
        {

            if (state == 1)
            {
                ans = (ans + helper(sum - j, 1, dp, k, d)) % mod;
            }
            else
            {

                if (j >= d)
                {
                    ans = (ans + helper(sum - j, 1, dp, k, d)) % mod;
                }
                else
                {
                    ans = (ans + helper(sum - j, 0, dp, k, d)) % mod;
                }
            }
        }
    }

    return dp[sum][state] = ans;
}

void helper(vector<int> &arr, int i, int sum, vector<vector<int>> &dp, set<int> &st)
{

    // cout<<"here"<<endl;
    if (i == arr.size())
    {
        if (sum != 0)
        {
            st.insert(sum);
        }

        return;
    }

    if (dp[i][sum] != -1)
    {
        return;
    }

    if (sum != 0)
    {
        st.insert(sum);
    }
    dp[i][sum] = 1;

    helper(arr, i + 1, sum + arr[i], dp, st);
    helper(arr, i + 1, sum, dp, st);
}

int64_t helper(vector<int> &arr, vector<vector<vector<int64_t>>> &dp, int i, int flag, int count)
{
    if (i >= arr.size())
    {
        if (count % 2 == 0)
        {

            return 0;
        }
        else
        {
            return INT64_MIN;
        }
    }

    if (dp[i][flag][count % 2] != -1)
    {
        return dp[i][flag][count % 2];
    }

    if (flag == 0)
    {

        int64_t first = 0;
        int64_t second = 0;

        first = arr[i] + helper(arr, dp, i + 2, 0, 0);

        int64_t num = helper(arr, dp, i + 1, 1, 0);

        if (num != INT64_MIN)
        {
            second = arr[i] + num;
        }
        else
        {
            second = num;
        }

        return dp[i][flag][count % 2] = max(first, second);
    }
    else if (flag == 1)
    {
        int64_t first = 0;
        int64_t second = 0;

        count = count + 1;
        int64_t num1 = helper(arr, dp, i + 1, 1, count);

        if (count % 2 == 0)
        {
            cout << i << " " << count << endl;
            if (i % 2 == 0)
            {

                int64_t num2 = helper(arr, dp, i + 2, 2, count);
                // if(num1!=INT64_MIN){
                //     num1=arr[i]+num1;
                // }

                return dp[i][flag][count % 2] = max(num1, num2);
            }
            else
            {
                int64_t num2 = helper(arr, dp, i + 1, 2, count);
                if (num1 != INT64_MIN)
                {
                    num1 = arr[i] + num1;
                }

                return dp[i][flag][count % 2] = max(num1, num2);
            }
        }
        else
        {
            return dp[i][flag][count % 2] = num1;
        }
    }
    else
    {
        return dp[i][flag][count % 2] = arr[i] + helper(arr, dp, i + 2, 2, count);
    }
}

bool search(string &s, char c)
{

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] != c)
        {
            return true;
        }
    }

    return false;
}

void solve()
{
    
    int64_t n,p,k;
    cin>>n>>p>>k;

    vector<int64_t> arr;
    int64_t num;

    for(int i=0;i<n;i++){

        cin>>num;
        arr.push_back(num);
    }

    sort(arr.begin(),arr.end());


    vector<int64_t> dp(n);


    for(int i=0;i<k-1;i++){
        if(i==0){
            dp[i]=arr[i];
        }
        else{
            dp[i]=dp[i-1]+arr[i];
        }

    }

    for(int i=k-1;i<n;i++){

        if(i==k-1){
            dp[i]=arr[i];

        }
        else{
            dp[i]=dp[i-k]+arr[i];
        }

    }

    int ans=0;
    for(int i=0;i<n;i++){

        if(dp[i]<=p){
            ans=i+1;
        }
    }

    cout<<ans<<endl;





}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
}