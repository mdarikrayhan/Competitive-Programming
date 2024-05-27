#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define vi vector<int>
#define pb push_back
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;
#define endl '\n'
#define yes  cout << "YES" << endl;
#define no  cout << "NO" << endl;
#define inf 1e18
const int mod = 1e9 + 7;
#define all(x) (x).begin(), (x).end()
/*
  -------------    JAY SHREE KRISHNA  -------------------
*/
vector<int> to;
vector<int> r;
vector<int> q1,q2;
vector<int> f;
int dfs(int x){
   f[x]=1;
   if(f[to[x]]==0){
    return f[x]=dfs(to[x]);
   }
   else return f[x]=x;
}
void solve() {
 int n;
 cin>>n;
 to.resize(n+1);
 r.resize(n+1);
 q1.resize(100006);
 q2.resize(100006);
 f.assign(100006,0);
 for(int i=1;i<=n;i++){
    cin>>to[i];
    r[to[i]]++;
 }
 int s=0;
 for(int i=1;i<=n;i++){
    if(!r[i]){
      q1[s]=dfs(i);
      q2[s++]=i;
    }
 }
 int t=0;
 t=s;
 for(int i=1;i<=n;i++){
    if(!f[i]){
      q1[s]=dfs(i);
      q2[s++]=i;
    }
 }
 if(s==1 && t==0){
    cout<<"0"<<endl;
    return;
 }
 cout<<s<<endl;
 for(int i=0;i<s;i++){
    cout<<q1[i]<<" "<<q2[(i+1)%s]<<endl;
 }



}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif
*/
    //int t; cin >> t; while (t--)
   solve();
    return 0;
}


/*


ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
bool cmp(pll a, pll b) {
    return a.second > b.second;
}
ll power( ll b, ll e)
{
    if (e == 0) return 1;
    if (e & 1) return b * power(b * b, e / 2);
    return power(b * b, e / 2);
}

ll power(ll b, ll e, ll m)
{
    if (e == 0) return 1;
    if (e & 1) return b * power(b * b % m, e / 2, m) % m;
    return power(b * b % m, e / 2, m);
}

ll modinv(ll a, ll m)
{
    return power(a, m - 2, m);
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string ds = "RLDU";


bool possible(int x, int y) {


    return (x < n && x >= 0 && y < m && y >= 0);
}
*/
/*

class UnionFind
{
    private: vector<int> p, rank;
    public:

        UnionFind(int n)
        {
            rank.assign(n,0); p.assign(n,0);
            iota(p.begin(),p.end(),0);
        }

        int findSet(int i){ return (p[i] == i) ? i : p[i] = findSet(p[i]);}

        bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}

        void unionSet(int i, int j)
        {
            if(!isSameSet(i,j))
            {
                int x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]) p[y] = x;
                else
                {
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};
*/
/*
class cmp{
   public:
   bool operator()(string& a,string& b){
     return b+a < a+b;
   }
};
*/

/*
long long mod(long long x)
{
    return ((x % MOD + MOD) % MOD);
}
long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}
*/

/*
bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

bool isPalindrome(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
*/