#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
#define rep(a,b) for(ll i=a;i<b;i++)


ll vsum(vector<ll>v)
{
  ll n=v.size(),sum=0;
  rep(0,n)
  sum+=v[i];


  return sum;
}

vector<ll>pres(vector<ll>v)
{
  vector<ll>presum;
  presum.push_back(v[0]);
  ll n=v.size();
  for(ll i=1;i<n;i++)
  presum.push_back(presum[i-1]+v[i]);
  return presum;
  
}

void inp(vector<ll>&arr,ll n)
{
  for(ll i=0;i<n;i++)
  {
    ll x;
    cin>>x;
    arr.push_back(x);
  }  
}

ll primes_sieve(ll n)
{
  vector<bool>pr(n+1,true);
  if(n==0||n==1)
  return 0;
  pr[0]=false,pr[1]=false;

  for(ll i=2;i<=n;i++)
  {
    if(pr[i])
    for(ll j=i*i;j<=n;j+=i)
    {
      pr[j]=false;
    }
  }
  ll count=0;
  for(ll i=0;i<=n;i++)
  if(pr[i])
  count++;


  return count;


}


ll pal(string s)
{
  ll c=0;
  for(ll i=0;i<s.size();i++)
  if(i!=(s.size()-1-i)&&s[i]==s[s.size()-1-i])
  c++;
  ll ans=(s.size()-c)/2;
  return ans;
}

void fct(vector<ll> &v,ll n)
{
  for(ll i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      v.push_back(i);
      v.push_back(n/i);    
      

    }
  }
}




void jets()
{
  ll n;
  cin>>n;
  vector<ll>a,b;
  inp(a,n);
  ll c=0;
  ll part=0;
  for(ll i=0;i<n;i++)
  {
    part++;
    if(a[i]<0)
    c++;
    if(c>2)
    {
      b.push_back((part-1));
      part=1;
      c=1;
    }
  }
  b.push_back(part);



  cout<<b.size()<<endl;
  for(auto i:b)
  cout<<i<<" ";
  cout<<endl;

}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
  #endif

    
    long long t=1;
    //cin>>t;
 
    while(t--)
    {
      time_t start, end; 
      time(&start);        
      jets();
      time(&end);
      double time=double(end-start);
      //cout << "Time taken by program is : " << fixed << time << setprecision(5)<<" sec"<<endl;
        

    }

   
    return 0;
}