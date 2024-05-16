#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define ss second
#define ff first
#define inf 0x3f3f3f3f
const int N = 1e5 + 10;
const int M = 1e9 + 7;
bool compareInterval(pair<int, int> x, pair<int, int> y) { return (x.ff > y.ff); }

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

void solve()
{
 int n;
 cin>>n;
 int a[n+1];
 set<int>s;
 int tot=0;
 map<int,int>mp;
 for(int i=0;i<n;i++){
    cin>>a[i+1];
    s.insert(a[i+1]);
    tot+=a[i+1];
   mp[a[i+1]]++;
 }
 vector<int>ans;
 for(int i=0;i<n;i++){
    int x=a[i+1];
    int new_tot=tot-x;
    if(new_tot%2==0 and s.find(new_tot/2)!=s.end()){
        if(new_tot/2==a[i+1] and mp[a[i+1]]==1)continue;
      ans.push_back(i+1);
    }
 }
 cout<<ans.size()<<endl;
 for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
 
 
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