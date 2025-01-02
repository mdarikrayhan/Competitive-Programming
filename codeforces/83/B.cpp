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


void solve()
{
    ll n,k;
    cin>>n>>k;

    ll sum = 0;

    ll arr[n];

    loop(i,0,n)
    {
        cin>>arr[i];
        sum += arr[i];
    }

    if(k > sum)
    {
        cout<<-1<<nl;
        return;
    }
    else if(k == sum)
    {
        cout<<endl;
        return;
    }

    ll l = 0;
    ll r = k - 1;
    ll temp = 0;

    while(l<=r)
    {
        ll mid = (l+r)/2;

        ll tsum = 0;

        loop(i,0,n) tsum += min(mid,arr[i]);

        if(tsum<=k)
        {
            temp = max(temp,mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }

    loop(i,0,n)
    {
         k -= min(arr[i],temp);
    }

    int ans[n];
    int idx = 0;

    loop(i,0,n)
    {
        if(arr[i] > temp) ans[idx++] = i;
    }

    loop(i,k,idx) cout<<ans[i]+1<<" ";
    loop(i,0,k)
    {
        if(arr[ans[i]] - temp - 1 > 0) cout<<ans[i]+1<<" ";
    }
    cout<<nl;
}


///         Beware of Long Long

///-----------------------------------------------------------------------------------------------------------------------

int main(){
    std::cout<<std::setprecision(10)<<std::fixed;
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
