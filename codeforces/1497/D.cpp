//Starting In The Name Of ALLAH
#include<bits/stdc++.h>
using namespace std;
 
#define   ll   long long int
#define   pb push_back
#define   yes  cout<<"YES\n";
#define   no   cout<<"NO\n";
#define   endl "\n";

#define   gcd(gd,a)    __gcd(gd,a) 
// ll gd(ll a, ll b)
//{ 
// if(b>a)swap(a,b); if(b==0)return a; if(a%b==0)return b; return gd(b, a%b);
//}

#define   lcm(a,b)   (a/gcd(a,b))*b
#define   srt(v)    sort(v.begin(),v.end());
#define   rev(v)    reverse(v.begin(),v.end());

#define   dq   deque<ll>dq; //qd.push_front(x) , dq.push_back(x);
#define   pq   priority_queue<ll>q;
#define   pq1  priority_queue <ll, vector<ll>, greater<ll> > q;
#define   pq2  priority_queue<pair<ll, ll> ,vector<pair<ll, ll>>,greater<pair<ll, ll > > > q;

#define   erase_duplicates(v)  v.erase(unique(v.begin(),v.end()), v.end());
#define   fraction() printf("%.15lf",sm/(double)n);

#define   input_eof  //while (getline(cin, s)) // EOF input data

#define   mem(a,b) memset(a, b, sizeof(a) )
#define   count  count(ar, ar+n, 1);
#define   rotate rotate(ar, ar+ind, ar+n); //  int ind = find(ar, ar+n, 1) - ar;

#define   binary_to_decimal cout<<bset.to_ullong()<<endl;  // bitset<32> bset;  cin>>bset; 
#define   decimal_to_binary cout<<bset<<endl; //  bitset<32> bset(5);
#define   one_s_complement  bset.flip(); // bitset<4> bset(10); cout<<bset<<endl;

#define   SR() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define   DBG(a) cerr<< "Line "<<__LINE__ <<" : "<< #a <<" = "<<(a)<<endl

bool sortsecond(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
       return a.second<b.second;
}
int isSubstring(string s, string sub)
{
    if (s.find(sub) != string::npos)return s.find(sub);
    else return -1;
}

const ll mod= 1000000000 + 7;

int main()
{
   ll n,m,t,i,j,l,r,a,b,c,d,k,k1 ;
    string s,s1,s2, s3,ss;
   
    cin>>t;
    while(t--)
    {
      cin>>n;
      ll ar[n+1], br[n+1];

      for(i=0; i<n; i++)cin>>ar[i]; 
      for(i=0; i<n; i++)cin>>br[i];

      std::vector<ll> dp(n+1, 0);

      for(i=1; i<n; i++)
      {
        for(j=i-1; j>=0; j--)
        {
            if(ar[i]==ar[j])continue;

            ll x=dp[i], y=dp[j], val=abs(br[i]-br[j]);

            dp[i]=max(dp[i], y+val);
            dp[j]=max(dp[j], x+val);

            //cout<<i<<" "<<j<<" "<<dp[i]<<" "<<dp[j]<<endl;
        }
      }

      cout<<*max_element(dp.begin(), dp.end())<<endl;
    }

}