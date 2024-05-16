#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
// #define int long long
#define all(x)      x.begin(),x.end()
#define allr(x)     x.rbegin(),x.rend()
#define CheckBit(x,k)   (x & (1LL << k))
#define SetBit(x,k)     (x |= (1LL << k))
#define ClearBit(x,k)   (x &= ~(1LL << k))
#define LSB(mask)       __builtin_ctzll(mask)
#define MSB(mask)       63-__builtin_clzll(mask) 
#define print(x)    cout << #x << " : " << x << endl
#define error1(x)   cerr << #x << " = " << (x) <<endl
#define coutall(v)  for(auto &it: v) cout<<it<<' '; cout<<endl
#define Abid_52     ios::sync_with_stdio(false);cin.tie(0),cin.tie(0)
#define error2(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n"
#define UNIQUE(x)   sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
template <typename T, typename U> T ceil(T x, U y) {return (x > 0 ? (x + y - 1) / y : x / y);}
template <typename T, typename U> T floor(T x, U y) {return (x > 0 ? x / y : (x - y + 1) / y);}

const int N = 2e5 + 10;

void solve()
{
    int n, m;
    cin >> n;
    vector<int> v(n);
    multiset<int>st;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        st.insert(v[i]);
    }
    sort(all(v));
    int mx=2*v[n-1];
    int ans=INT_MIN;
    for(int i=2;i<=mx;i++)//100
    {
        multiset<int>temp=st;//282
        int cnt=0;
        for(int j=0;j<n;j++)//50
        {
            auto it1=temp.find(v[j]);//282
            if(it1==temp.end())continue;
            temp.erase(it1);//282
            int love=i-v[j];
            auto it=temp.find(love);//282
            if(it!=temp.end())
            {
                cnt++;
                temp.erase(it);//282
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    Abid_52;
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
}