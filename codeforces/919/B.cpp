using namespace std;
#include <bits/stdc++.h>

//---MACROS--//

//                                                  -| BANKAI |-
#define ll long long
#define loop(i,m,n) for(long long int i=m;i<n;i++)
#define rloop(i,m,n) for(long long int i=m;i>=n;i--)
#define pb push_back
#define F first
#define S second
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define all(v) v.begin(),v.end()
#define test cout<<"B A N K A I"<<endl
#define Fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl "\n"
#define MP make_pair

vector<int> factors(int n) {
    // Takes sqrt(n) time. Go for Sieve till sqrt(n) if time Squeezes (sqrt(n)/log(n)).
    vector<int> f;
    for (int x = 2; x*x <= n; x++){
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

///------------------------------------------------------------------------------------------------------------------

string a;
ll len;

ll dp[20][2][11];

ll rec(ll idx,ll hi,ll sum)
{
    if(sum > 10) return 0;
    if(idx == len)
    {
        if(sum == 10) return 1;
        else return 0;
    }

    if(dp[idx][hi][sum] == -1)
    {
        ll ans = 0;

        ll lolim = 0;
        ll hilim = 9;

        if(hi) hilim = a[idx] - '0';

        loop(i,lolim,hilim+1)
        {
            int nhi = hi;
            if(i<hilim) nhi = 0;

            ans += rec(idx+1,nhi,sum+i);
        }
        dp[idx][hi][sum] = ans;
    }
    return dp[idx][hi][sum];
}


void solve()
{
    int k;
    cin>>k;

    ll l = 0;
    ll r = 1e18;

    ll ans;

    while(l<=r)
    {
        ll mid = (l+r)/2;

        a = to_string(mid);
        len = a.size();

        memset(dp,-1,sizeof dp);

        ll tot = rec(0,1,0);

        //cout<<tot<<" "<<l<<" "<<mid<<" "<<r<<nl;

        if(tot >= k)
        {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }

    cout<<ans<<nl;
}


///         Beware of Long Long

///-----------------------------------------------------------------------------------------------------------------------

int main(){
    //std::cout<<std::setprecision(10)<<std::fixed;
    Fast
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int t = 1;
    //cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
