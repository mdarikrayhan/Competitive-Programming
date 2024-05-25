#include <bits/stdc++.h>
// #include <assert.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// template<typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<typename Q> using priority_queue_r = priority_queue<Q, vector<Q>, greater<Q>>;
using ll = long long;using ld = long double;
#define el '\n'
#define S  second
#define sz(v) (ll)(v).size()
#define F  first
#define ZOON ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define FILE freopen("inputf.txt", "r", stdin); freopen("outputf.txt", "w", stdout);
// #define PI 3.14159265
// int dx[]={1, -1, 0, 0, 1, 1, -1, -1}, dy[]={0, 0, 1, -1, 1, -1, -1, 1};
const ll MOD =   1e9+7, N = 2e5+5;

ll n, a, b, l, t, m;

ll calculateBlocks(ll l, ll r)
{
    l--;
    return ((r*(r-1)/2) - (l*(l-1))/2)*b + (r-l)*a;
}

bool check(ll r)
{
    ll totBlocks = calculateBlocks(l, r);
    ll mxBlock = calculateBlocks(r, r);

    return mxBlock <= t && totBlocks <= m*t;
    // ll segs = (totBlocks+m-1) /m;

    // int st=l, en=r, lastInd=l;
    // while(st<=en)
    // {
    //     int mid = (st+en)>>1;

    //     if(calculateBlocks(mid, r)*m >= totBlocks)
    //         lastInd = mid, st=mid+1;
    //     else en=mid-1;
    // }

    // ll worstCaseBlocks = calculateBlocks(lastInd, r);

    // return worstCaseBlocks <= t;
}

void SOLVE(int test)
{
    cin>>a>>b>>n;

    while(n--)
    {
        cin>>l>>t>>m;

        int st = l, en = 1e6, ans = -1;
        while(st <= en)
        {
            int mid = (st + en) >> 1;

            if(check(mid))
                st=mid+1, ans=mid;
            else en=mid-1;
        }

        cout << ans << el;
    }
}



int main()
{
    ZOON

    int test_cases = 1;
    // cin>>test_cases;
    for(int i = 1;i<=test_cases;i++)
    {
        SOLVE(i);
    }

//*/ 
    return 0;
}