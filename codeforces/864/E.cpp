#include <bits/stdc++.h>

using namespace std;

#define ll         long long

void zrebeooo()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
}

const int N = (int)5e1 + 5;

struct item
{
    int t , d , idx , val;
};

int n;
int dp[100][2001];
item a[100];
vector<int> ans;

bool cmp(item x , item y)
{
    return(x.d < y.d || (x.d == y.d && x.val > y.val));
}

int mx(int i , int T)
{
   if(i == n) return 0;

   int& ret = dp[i][T];
   if(ret) return ret;

   int ch1 = mx(i+1 , T) , ch2 = -1;
   if(T + a[i].t < a[i].d) ch2 = a[i].val + mx(i+1 , T + a[i].t);

   return ret = max(ch1 , ch2);
}

void bmx(int i , int T)
{
    if(i == n)
    {
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        return;
    }

   int ch1 = dp[i+1][T] , ch2 = -1;
   if(T + a[i].t < a[i].d) ch2 = a[i].val + dp[i+1][T + a[i].t];

   if(ch2 >= ch1) ans.push_back(a[i].idx) , bmx(i+1 , T + a[i].t);
   else bmx(i+1 , T);
}

void solve()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].t >> a[i].d >> a[i].val , a[i].idx = i+1;
    sort(a , a+n , cmp);

    cout << mx(0 , 0) << "\n";
    bmx(0 , 0);
}

int main ()
{
    zrebeooo();
                                 //////هنليسها///////
    int t = 1;
    //cin >> t;
    for(int testcase = 1 ; testcase <= t ; testcase++)
    {
        //cout << "Case #" << testcase << "\n";
        solve();
        if(testcase != t) cout << "\n";
    }
    return 0;
}
