//Bit_Optimizer
 
//Hello!! Stalker---->STOP STALKING :)
 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <chrono>
#include <complex>
#define ub upper_bound
#define lb lower_bound
#define endl "\n"
#define ll long long
#define lli long long int


#define vi vector<int>
#define vs vector<string>
#define vll vector<ll>
#define vvi vector < vi >
#define vpll vector<pair<ll,ll>>
  #define pii pair<int,int>
  #define mll map<ll,ll>
  #define pll pair<ll, ll>

  #define PI 3.141592653589793238462    //double PI=2*asin(1.0);
  #define mod 1000000007
  #define mod2 998244353
  // #define p 1000000000000000001
  #define INF 10000007
  #define all(c) c.begin(),c.end()
  #define rall(c) c.rbegin(),c.rend()
  #define mp(x,y) make_pair(x,y)
  #define mem(a,val) memset(a,val,sizeof(a))
  #define eb emplace_back
  #define f first
  #define s second
  #define clz __builtin_clz
  #define clzll __builtin_clzll
  #define ctz __builtin_ctz
  #define ctzll __builtin_ctzll
  #define pcount __builtin_popcount
  #define pcountll __builtin_popcountll
  #define pb push_back
  #define ppb pop_back
  #define pf  push_front
  #define ppf pop_front
  #define rep(i,a,b) for(ll i=a;i<b;i++)
  #define repe(i,a,b) for(ll i=a;i<=b;i++)
  #define dep(i,a,b) for(ll i=a; i>=b; i--)
  #define yes cout<<"YES"<<endl
  #define no cout<<"NO"<<endl
  #define dne cout<<-1<<endl

 
 
  using namespace std;
  using namespace __gnu_pbds;
 
 typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // datatype
 //less, greater, less_equal
 //Element at position-->*A.find_by_order()
 //count smaller elements--->A.order_of_key()
 //lower & upper bound-->*A.lower_bound()
  
  

  const ll inf = 1e9 + 7;
  // vi isprime(10000000 , 1);
  // vi g(10000000, 0);
  
  //***********************************************************************************************
//Hello!! Stalker---->STOP STALKING :)
 
  //Euclid's algorithm----O(logN)
  ll gcd(ll a, ll b) { if (b == 0) {return a;} return gcd(b, a % b);}
 
//Hello!! Stalker---->STOP STALKING :)
  //LCM
  ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
 
//Hello!! Stalker---->STOP STALKING :)
  //Prime factorisation----O(sqrt(n))
  vpll primefact(ll n)  { vpll pfact; 
  for(ll i=2; i*i<=n; i++) if(n%i==0){ll cnt=0; while(n%i==0) {cnt++; n/=i;} pfact.pb({i,cnt});}
  if(n>1) pfact.pb({n,1});  return pfact; }
 
//Hello!! Stalker---->STOP STALKING :)
  //Binary Exponentiation(recursive)---divide & conquer-----> O(log b)
  ll powerRec(ll a, ll b) { 
  if(b==0) return 1;
  ll store = powerRec(a, b/2);
  if(b&1) {return (a* ((store*store) %mod)) %mod;} else{ return (store*store) %mod;} }
 
//Hello!! Stalker---->STOP STALKING :) 
  //Binary Exponentiation(iterative)---divide & conquer-----> O(log b)
  ll powerIter(ll a, ll b){
    ll ans=1;
    while(b){ if(b&1) { ans=(ans*a);} a=(a*a); b>>=1;} return ans;
  }
 
//Hello!! Stalker---->STOP STALKING :)
  // Sieve of Erastosthenes---> O(n* log(logn))
   vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; 
  for (int i = 2; i <= n; i++)
  if (arr[i] == 0) {vect.push_back(i); 
  for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
 
//Hello!! Stalker---->STOP STALKING :)
  //sum_of_digits
  ll sum_of_digits(ll n) {ll sum=0; while(n>0) {sum+=n%10; n/=10; } return sum;}
 
//Hello!! Stalker---->STOP STALKING :)
  // Prime or not-----O(sqrt(n))
  bool isPrime(ll n)
  {if(n==1) return false; for(ll i=2; i<=sqrt(n); i++){ if(n%i==0) return false;} return true;}
 
//Hello!! Stalker---->STOP STALKING :)
  //Perfect square or not----->O(1)
  bool prfSq (ll n){ if(ceil(double(sqrt(n)) == floor(double(sqrt(n))))){ return 1; }else{ return 0;}}
 
//Hello!! Stalker---->STOP STALKING :)
  //factorial of a no.----->O(n)
  ll fact(ll n)
  {
    if(n==0)
      return 0;
    else
    {
      ll factorial=1;
    for(ll i=1; i<=n; i++)
    {
      factorial=(factorial*i)%mod;
 
    }
    return factorial;
  }
  }

  //
      ll sqrtt(ll x) {
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}
  //
 
 
//Hello!! Stalker---->STOP STALKING :)
  // regulr bracket string or not
  bool regular(string a)
  {
    ll cnt=0;
    for(ll i=0; i<a.length(); i++)
    {
      if(a[i]=='(')
        cnt++;
      else
        cnt--;
      if(cnt<0)
        return false;
    }

    
   
    if(cnt>0)
      return false;
    return true;
    
  }
 
//Hello!! Stalker---->STOP STALKING :)
  //Reverse a number
  vector<int> reverse_no(ll n)
  {
    vi v;
    ll ans=0, rem;
    while(n != 0) {
    rem = n % 10;
    v.pb(rem);
    ans = ans * 10 + rem;
    n /= 10;
  }
  return v;
  }
  //**************************************************************************************************
 
//Hello!! Stalker---->STOP STALKING :)
 ll countPrimes(ll n) {
        if(n<2) return 0;
        int count=0;
        vector<bool> primes(n,1);
        primes[0] = false;
        primes[1] = false;
        for(ll i=2;i<n;i++)
        {
            if(primes[i])
            {
                count++;
                for(ll j=i*i;j<n;j+=i)
                    primes[j]=0;
            }
        }
        
        return count;
    }
 
//Hello!! Stalker---->STOP STALKING :)
    int countDigit(int n)
{
 
    int count = 0;
 
    while (n != 0) 
 
    {
 
        n = n / 10;
 
        ++count;
 
    }
 
    return count;
}
 
//Hello!! Stalker---->STOP STALKING :)
// number is power of 2 or not
 bool check(ll n)
 {
  if(n==0)
    return false;
  return (ceil(log2(n)) == floor(log2(n)));
 }
 
 ll find_ncr(ll n, ll r)
 {
  ll ans=fact(n)/(fact(r)*fact(n-r));
  return ans;
 }
 //************************************************************************************
 
 
//**************************************************************************************
 
//Hello!! Stalker---->STOP STALKING :)
 bool ispalindrome(string s)
{
  ll i=0, j=s.length()-1;
  while(i<=j)
  {
    if(s[i]!=s[j])
      {return false;  break;}
    i++;
    j--;
  }
  return true;
}
 
  
  void calculate()
  {
    ll A, B, C, D; cin >> A >> B >> C >> D;
    ll val = A*B;
    rep(i,A+1,C+1) {
        ll cur = val / __gcd(val, (ll) i);
        ll nxt = B+1;
        if (nxt % cur != 0) {
            nxt += cur-(nxt%cur);
        }
        if (nxt <= D) {
                cout << i << " " << nxt << endl; return;
        }
    }
    cout << "-1 -1" << endl;
  }
 
  // bool comp()
  // {
    
  // }
 
 //*******************************************************************************************
   
 // ***************************************************************
 
 
//Hello!! Stalker---->STOP STALKING :)
int highestPowerof2(int n)
{
   int p = (int)log2(n);
   return (int)pow(2, p);
}
//**************************************************************************

 
 
 
//Hello!! Stalker---->STOP STALKING :)
 
 
 
 
  string findTime(string T, int K)
{
   
    // convert the given time in minutes
  string ans="";
    int minutes = ((T[0] - '0')
                       * 10
                   + T[1] - '0')
                      * 60
                  + ((T[3] - '0')
                         * 10
                     + T[4] - '0');
   
    // Add K to current minutes
    minutes += K;
   
    // Obtain the new our
    // and new minutes from minutes
    int hour = (minutes / 60) % 24;
   
    int min = minutes % 60;
   string c=to_string(hour);
    // Print the hour in appropriate format
    if (hour < 10) {
      
        ans+="0";
        ans+=c;
    }
    else {
        ans+=c;
    }
   string w=to_string(min);
    // Print the minute in appropriate format
    if (min < 10) {
      
        ans+="0";
        ans+=w;   
         }
    else {
        ans+=w;
    }
    return ans;
}

 
 bool isDiv11(string num){
   int n = num.length();
   long odd_sum = 0, even_sum = 0;
   for(int i = 0; i < n; i++){
      if(i % 2 == 0){
         odd_sum += num[i] - '0';
      } else {
         even_sum += num[i] - '0';
      }
   }
   if(odd_sum == even_sum)
      return true;
      return false;
}
 


 
  
    void build(ll ind, ll low, ll high, ll arr[], ll seg[])
    {
      if(low==high)
      {
        seg[ind]=arr[low];
        return;
      }
 
      ll mid=(low+high)>>1;
      build(2*ind+1,low,mid,arr,seg);
      build(2*ind+2,mid+1,high,arr,seg);
      seg[ind]=max(seg[2*ind+1] , seg[2*ind+2]);
    }

    ll query(ll ind, ll low, ll high, ll l, ll r, ll seg[])
    {


      // No overlap
      // l r low high or low high l r
      if(r<low || high<l) return 0;

      // Complete overlap
      // l low high r
      if(low>=l && high<=r) return seg[ind];

      ll mid=(low+high)>>1;
      ll left=query(2*ind+1, low, mid, l, r, seg);
      ll right=query(2*ind+2, mid+1, high, l, r, seg);
      return left+right;
    }

   
 
 
bool isvowel(char x)
{
  int p=int(x);
    if (x == 97 || x == 101 || x == 105 || x == 111 || x == 117 || x==65 || x==69 || x==73 || x==79 || x==85)
        return true;
    else
        return false;
}
 
//

 bool valid_index(ll i, ll j, ll n, ll m)
 {
  if(i>=0 && i<n && j>=0 && j<m)
    return true;
  return false;
 }

 //
 

   ll f(ll ind, vll &dp)
   {
    if(ind==0) return 1;
    if(ind==1) return 1;
    ll left=f(ind-1,dp);
    ll right=f(ind-2,dp);
    return left+ right;
   }

   ll find(vll v)
   {
    ll curr=0, best=0;
    rep(i,0,v.size())
    {
      curr+=v[i];
      if(curr<0) curr=0;
      best=max(best,curr);
    }
    return best;
   }

//
string digitsNum(int N)
  {
      int p=0;
      string s;
      string w="yes";
      while(p+9<N)
      {
          s+='9';
          p+=9;
      }
      int rem=N-p;
      if(rem>0) s+=to_string(rem);
      
      reverse(s.begin(),s.end());
      // cout<<s<<endl;
      while(N--)
      s+='0';
      
      return s;
      
  }
   

   //
  vll dijkstra(ll V, vpll A[], ll S)
    {
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vll dist(V+1,1e9+7);
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty())
        {
            ll dis=pq.top().first;
            ll prev=pq.top().second;
            pq.pop();
            for(auto child:A[prev])
            {
                ll next=child.f;
                ll nextDist=child.s;
                if(dist[next]>dist[prev]+nextDist)
                {
                   dist[next]=dist[prev]+nextDist;
                   pq.push({dist[next],next});
                }
                
            }
        }
        return dist;
        
    }

  //
    void shortest_distance(vector<vector<int>>&d){
       int n = d.size();
      for(int k=0;k<n;k++){
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  if(d[i][k]==-1 || d[k][j]==-1)continue;
                  if(d[i][j]==-1)   d[i][j] = d[i][k] + d[k][j];
                  else d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
              }
          }
      }
  }

 //
  vi toposort(ll n, vi A[])
  {
    queue<ll> q;
    vi indegree(n,0);
    for(ll i=0; i<n; i++)
    {
      for(auto it:A[i]) indegree[it]++;
    }

  for(ll i=0; i<n; i++)
  {
    if(indegree[i]==0) q.push(i);
  }

  vi topo;
  ll cnt=0;

  while(!q.empty())
  {
    ll node=q.front();
    q.pop();
    cnt++;
    topo.pb(node);

    for(auto it:A[node])
    {
      indegree[it]--;
      if(indegree[it]==0) q.push(it);
    }
  }

  return topo;


  }


 
//


  

  int main()
  {
    
    // sumera
    ll mini=sum_of_digits(707);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    // // cin.ignore(); must be there when using getline(cin, s)
    ll T;
    cin>>T;
    
    // T=1;
    ll monk, sid=1;
   
    //Hello!! Stalker---->STOP STALKING :)
   
   // auto it=s.find(arr[i-k]);
    //        s.erase(it); 
  while(T--)       
  {
    // string s;
    // cin>>s;
    // ll f=0;
    // string a="yes";
    // ll k=s.length();
    // string p="";

    // while(k--)
    // {
    //   p+=a;
    // }

    // k=0;
    // for(ll i=0; i<p.length(); i++)
    // {
    //   rep(j,i,p.length())
    //   {
    //     if(k==s.length()) {
    //       f=1;
    //       break;
    //     }
    //     if(p[j]==s[k]) k++;
    //     else
    //     {
    //       continue;
    //     }

    //   }
    // }
    // if(f) yes;
    // else no;

    ll m,s;
    cin>>m>>s;
    ll vis[3000]={0};

    vll v(m);
    rep(i,0,m)
    {
      cin>>v[i];
      vis[v[i]]=1;
    }
    
   sort(all(v));
   ll ch=1;
   rep(i,1,m)
   {
    if(v[i]==v[i-1]) ch=0;
   }

   ll sum=accumulate(v.begin(),v.end(),0LL);
   map<ll,ll> mp;

   repe(i,1,1000)
   {
    ll x=(i*(i+1))/2;
    mp[x]=1;
   }

   if(ch==0) no;
   else
   {
    ll f=0;
    ll k=0;
    rep(i,1,3000)
    {
      if(!vis[i]) k+=i;
      if(k==s && mp.find(sum+s)!=mp.end())
      {
        f=1;
        break;
      }
    }

    if(f) yes;
    else no;
   }
  
  }
   return 0; 
 }
 
  //Hello!! Stalker---->STOP STALKING :)
 //This is Robust_Monk here....and I am trying my best to do O(N!) in O(1) :)
    
  
