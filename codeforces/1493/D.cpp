/*______________________________________________Bismillahir Rahmanir Rahim____________________________________________


            .----------------.  .----------------.  .----------------.  .----------------.  .----------------.
|            | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |    |
|            | |    _______   | || |      __      | || |   ______     | || |     ____     | || |     _____    | |    |
|            | |   /  ___  |  | || |     /  \     | || |  |_   _ \    | || |   .'    `.   | || |    |_   _|   | |    |
|            | |  |  (__ \_|  | || |    / /\ \    | || |    | |_) |   | || |  /  .--.  \  | || |      | |     | |    |
|            | |   '.___`-.   | || |   / ____ \   | || |    |  __'.   | || |  | |    | |  | || |   _  | |     | |    |
|            | |  |`\____) |  | || | _/ /    \ \_ | || |   _| |__) |  | || |  \  `--'  /  | || |  | |_' |     | |    |
|            | |  |_______.'  | || ||____|  |____|| || |  |_______/   | || |   `.____.'   | || |  `.___.'     | |    |
|            | |              | || |              | || |              | || |              | || |              | |    |
|            | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |    |
|            |'----------------'  '----------------'  '----------------'  '----------------'  '----------------'|    |
|                                                                                                                    |
|                                              Ahsanul Anam Saboj
|                                              Department of CSE
|                                              Comilla University                                                    |
|                                              Email : <a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="86e7eef5e7e8f3eae7e8e7ebf5e7e4e9ecb7bfbfbfc6e1ebe7efeaa8e5e9eb">[email&#160;protected]</a>                                |
|                         _____________________Something is going to be happened ___________________                   |
|___________________________________________________________________________________________________________________*/
#include<bits/stdc++.h>
using namespace std;
#define Start_by_the_grace_of_allah        int main()
#define next_Time_INsha_ALLAH               return 0;
#define ll                      long long int
#define ld                      long double
#define mod                     1000000007
#define test                    int tt;cin>>tt;while(tt--)
#define YES                     cout<<"YES"<<endl
#define NO                      cout<<"NO"<<endl
#define olta(a)                 reverse(a.begin(),a.end())
#define F                       first
#define S                       second
#define pb(x)                   push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define vin                    vector<int>
#define vll                    vector<long long>
#define vp                      vector<pair<ll, ll> >
#define v_min(a)                *min_element(a.begin(),a.end())
#define v_max(a)                *max_element(a.begin(),a.end())
#define v_mini(v)               min_element(v.begin(),v.end()) - v.begin();
#define v_maxi(v)               max_element(v.begin(),v.end()) - v.begin();
#define v_sum(a)                accumulate(a.begin(),a.end(),0)
#define un(a)                   a.erase(unique(a.begin(),a.end()),a.end())
#define delete(a)               a.erase(a.begin(),a.end())
#define Sort(a)                 sort(a.begin(),a.end())
#define is(a)                   is_sorted(a.begin(),a.end())
#define Saboj4632               ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define pi                      3.141592653589793
#define md                      1000000050
#define ull                     unsigned ll
#define coutv(v)                for(auto it:v){cout<<it<<' ';}cout<<endl;
#define cinv(v)                 for(auto &it:v)cin>>it;
#define fr(in,out)              for(ll i=in;i<out;i++)
#define nl                      '\n'
const int N                     = (int)1e10;
#define INF                     1e11
vector<ll>prime;
bool mark[200005];
ll di[200005];
void sieve(ll n)
{
    ll i,j;
    mark[1]=1;
    di[1] = 1;
    di[2] = 2;
    for(i=4; i<=n; i+=2)
    {
        mark[i]=1;
        di[i] = 2;
    }
    prime.push_back(2);
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            di[i] = i;
            prime.push_back(i);
            if(i*i<=n)
            {
                for(j=i*i; j<=n; j+=(i*2))
                {
                    mark[j]=1;
                    if(di[j]==0)di[j] = i;
                }
            }
        }
    }
}
//map<ll,ll>Factor;
//void Primefactorize(ll n){for(ll i=0; i<prime.size() && prime[i]*prime[i]<=n; i++){if(n%prime[i] == 0){while(n%prime[i] == 0){Factor[prime[i]]++;n/=prime[i];}}}if(n>1){Factor[n]++;}}
//(to print without sieve)--// void primeFactors(ll n){while (n % 2 == 0){cout << 2 << " ";n = n/2;}for (ll i = 3; i <= sqrt(n); i = i + 2){while (n % i == 0){cout << i << " ";n = n/i;}}if (n > 2)cout << n << " ";}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//ll LIS(vector<ll> const& v){ll n = v.size();const ll INF = 1e10;vecl gdp(n+1,INF);gdp[0] = -INF;for(ll i=0;i<n;i++){ll l = upper_bound(gdp.begin(),gdp.end(),v[i])-gdp.begin();if(gdp[l-1]<v[i] && v[i]<gdp[l]){gdp[l] = v[i];}}for(ll i=n;i>=0;i--){if(gdp[i]<INF){n = i;break;}}return n;}

multiset<ll>mul[200005];

map<ll,ll>m[200005];
ll bigmod(ll n,ll m)
{

 //   cout<<n<<" power "<<m<<endl;
    ll res = 1;
    while(m>0)
    {
        if(m%2==1)res = (res*n)%mod;
        n = (n*n)%mod;
        m/=2;
    }
    return res%mod;
}
void akam()
{
    ll n,i,j,c=0,x,y,k,ans=0,sum=0;

    //cout<<"Case "<<tst<<": ";

    sieve(200001);
    cin>>n>>k;

    ll a[n];

    ans = 1;
    for(i=0; i<n; i++)
    {
        cin>>a[i];

        x = a[i];
        y = di[x];
        c = 0;
        while(x>1)
        {
            y = di[x];
            c = 0;
            while(di[x]==y)
            {
                c++,x/=di[x];
            }
            //cout<<y<<" "<<c<<" I "<<i<<endl;
            m[i][y] = c;
            mul[y].insert(c);
            if(mul[y].size()==n){

                ans = (ans*bigmod(y,*mul[y].begin()))%mod;
            }
        }
    }
    ll prv=0;
    for(i=0; i<k; i++)
    {

        cin>>x>>y;
        x--;
        while(y>1)
        {

            j = di[y];
            c = 0;
            prv = 0;
            while(di[y]==j)c++, y/=di[y];

           // cout<<x<<" "<<j<<" DF "<<m[x][j]<<endl;
            if(m[x][j]!=0)
            {
                prv = *mul[j].begin();
                mul[j].erase(mul[j].find(m[x][j]));
            }

           /// cout<<j<<" jj"<<endl;
            mul[j].insert(m[x][j] + c);
            m[x][j]+=c;

            if(mul[j].size()==n){

                ans = (ans*bigmod(j,*mul[j].begin()-prv))%mod;
            }

        }
        cout<<ans<<endl;

    }


}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tst =0;

    //test
    akam();

    return 0;

}
