#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define ss second
#define ff first
#define inf 0x3f3f3f3f3f3f3f3f
const int N = 2e5 + 10;
const int M = 1e9 + 7;
bool compareInterval(pair<int, int> x, pair<int, int> y)
{
    return x.ss < y.ss;
}

bool cmp2(const string s1, const string s2)
{
    return (s1.size() < s2.size());
}

int power(int a, int n)
{
    int ans = 1;
    while (n > 0)
    {
        int last = (n & 1);
        if (last)
        {
            ans = ((ans % M) * (a % M)) % M;
        }
        a = ((a % M) * (a % M)) % M;
        n = n >> 1;
    }
    return ans % M;
}

int fact(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans = ((ans % M) * (i % M)) % M;
    }
    return ans % M;
}
int ncr(int n, int k)
{
    return fact(n) * 1ll * power(fact(k), M - 2) % M * 1ll * power(fact(n - k), M - 2) % M;
}

#define Priyanshu_Mishra

vector<int>ver[N];
vector<bool>vis(N,false);

  void bfs(int n){
    vis[n]=true;
    queue<int>que;
    que.push(n);
    while(!que.empty()){
        int num=que.front();
        que.pop();
        for(auto it:ver[num]){
            if(!vis[it]){
                vis[it]=true;
                cout<<num+1<<" "<<it+1<<endl;
                que.push(it);
            }
        }
    }
  }

void solve()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    ver[x].push_back(y);
    ver[y].push_back(x);
   }
   int leader,siz=0;
   for(int i=0;i<n;i++){
      int now=ver[i].size();
      if(now>siz){
        siz=now;
        leader=i;
      }
   }
   bfs(leader);
  
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int testcases = 1;
    // std::cin >> testcases;
    while (testcases--)
    {
        solve();
#ifdef Priyanshu_Mishra
        std::cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms\n";
#endif
    }
    return 0;
}
/*
If I'd never met you,
I wouldn't feel the pain

Of losing your sweet love;
I wouldn't feel insane.

But if I'd never met you,
I wouldn't know the pleasure

Of ecstasy's warm gifts
And memories to treasure.

Now moving on with life,
I force a wistful grin,

Questioning what went wrong,
Wondering what might have been.
*/