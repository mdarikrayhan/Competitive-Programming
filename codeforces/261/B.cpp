#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define fr                first
#define sc                second
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define debug(x)  cout<<(x)<<'\n';
#define vi                vector<int>

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

double calc(int val1,int val2,int val3)
{
    
    int x=min(val3-val2,val3-val1);
    if(min(val1,val2)==0) return (double)1.00/val3;
    
    int temp1=max(val1,val2);
    double val4=1;
    for(int i=1;i<=min(val1,val2);i++)
        val4=val4*i;
    for(int i=temp1+1;i<=val3;i++)
    {
        val4=val4/i;
    }
    return val4;

    
}


void solve(){
   
int n;
cin>>n;
int a[n+1];
for(int i=1;i<=n;i++) cin>>a[i];


int p;
cin>>p;
if(n==1)
{

  if(a[1]<=p)
  {
    cout<<1;
    return;
  }
  cout<<0;
  return;


}

double ans=0;
if(accumulate(a+1,a+n+1,0ll)<=p) ans=n;

for(int i=1;i<=n;i++)
{

   int x=p-a[i]+1;
   
   vector<int> temp;
   for(int j=1;j<=n;j++)
   {

      if(j!=i) temp.pb(a[j]);

   }
   int dp[n][n][p+1];
   for(int j=0;j<n;j++)
   {
    for(int k=0;k<n;k++)
    {
        for(int l=0;l<=p;l++)
            dp[j][k][l]=0;
    }
   }
   dp[1][0][0]=1;
   if(temp[0]<=p)
   dp[1][1][temp[0]]=1;
   
   for(int j=2;j<n;j++)
   {
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<=p;l++)
            {
               if(temp[j-1]<=l && k)
               dp[j][k][l]=dp[j-1][k][l]+dp[j-1][k-1][l-temp[j-1]];
               else dp[j][k][l]=dp[j-1][k][l];

            }

        }


   }
   //4 dp[n-1][4][]
   //
   
   
   for(int j=max(x,0ll);j<=p;j++)
   {

      for(int k=1;k<n;k++)
      {
           
           ans=ans+k*dp[n-1][k][j]*calc(k,n-k-1,n);


      }



   }


}

cout<<setprecision(6)<<ans;

    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t=1;
    
    while(t--) solve();
    return 0;
}
