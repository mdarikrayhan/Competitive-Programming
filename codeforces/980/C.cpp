#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using lli=long long;
 
long long int mod_power(long long int a,long long int b,lli mod)
{
   if(b==0)
   {
      return 1;
   }
   
   a%=mod;
   
   long long int ans=mod_power(a,b/2,mod);
   ans*=ans;
   ans%=mod;
   
   if(b%2)
   {
      ans*=a;
      ans%=mod;
   }
   
   return ans;
}
 
long long int power(long long int a,long long int b)
{
   if(b==0)
   {
      return 1;
   }
   
   long long int ans=power(a,b/2);
   ans*=ans;
   
   if(b%2)
   {
      ans*=a;
   }
   
   return ans;
}
 
vector<int> minfactor(int n)
{
   vector<int> nums(n+1,0);
   
   for(int i{2};i*i<=n;i++)
   {
      if(nums[i]!=0)
      {
         continue;
      }
      
      nums[i]=i;
      
      for(int j{i*i};j<=n;j+=i)
      {
         if(nums[j]==0)
         {
            nums[j]=i;
         }
      }
   }
   
   for(int i{2};i<n;i++)
   {
      if(nums[i]==0)
      {
         nums[i]=i;
      }
   }
   
   return nums;
}
 
vector<bool> prime()
{
   vector<bool> sieve(2000001,true);
   sieve[0]=false;
   sieve[1]=false;
   
   for(int i{2};i*i<=2000000;i++)
   {
      if(!sieve[i])
      {
         continue;
      }
      
      for(int j{i*i};j<=2000000;j+=i)
      {
         sieve[j]=false;
      }
   }
   
   return sieve;
}
 
void is_bipartite(vector<vector<int>> &adj,int i,vector<int> &col,int curr_col,vector<bool> &visited,bool &b,vector<int> &nums1,vector<int> &nums2)
{
   /*
      b will tell weather grph is bipartite or not
      initialise col array with -1
      nums1 && nums2 store the vertex
   */
   
   //BC
   
   // if(i==4)
   // {
   //    cout<<"Yo1"<<endl;
   // }
   
   if(visited[i])
   {
      return;
   }
   
   //RC
   
   visited[i]=true;
   int n=adj[i].size();
   
   // if(i==4)
   // {
   //    cout<<"Yo"<<endl;
   // }
   
   if(col[i]==1)
   {
      // cout<<" ana "<<i<<endl;
      nums1.push_back(i);
   }
   else
   {
      // cout<<" avi "<<i<<endl;
      nums2.push_back(i);
   }
   
   for(int j{};j<n;j++)
   {
      if(col[adj[i][j]]==-1)
      {
         col[adj[i][j]]=1-curr_col;
      }
      else if(col[adj[i][j]]!=1-curr_col)
      {
         b=false;
         return;
      }
      
      is_bipartite(adj,adj[i][j],col,1-curr_col,visited,b,nums1,nums2);
   }
}
 
long long int square_root(long long int x)
{
   /**********  Will return the sqrt if number is perfect square else floor 
                of square root *******/
   
   long long int l{},h=INT_MAX;
   
   while(l<h)
   {
      lli mid=l+(h-l+1)/2;
      
      if(mid*mid<=x)
      {
         l=mid;
      }
      else
      {
         h=mid-1;
      }
   }
   
   return l;
}

vector<lli> take_input(int n)
{
   vector<lli> nums(n,0);
   
   for(int i{};i<n;i++)
   {
      cin>>nums[i];
   }
   
   return nums;
}

lli nCr(lli a,lli b)
{
   if(a<b)
   {
      return 0;
   }
   
   lli ans=1,c=1;
   
   while(c<=b)
   {
      ans*=a;
      ans/=c;
      c++;
      a--;
   }
   
   return ans;
}

/*
 
**Just observer how you can maximize or minimize the result by given opeartion
**If question says you can partition your array into k>1 parts{then think you realy
   need k partition or just 2 partition}
**Test Case ache se dekh le bsdk
**Permutaion array ko sort karne par A[i]=i+1 {0 based indexing} ho jaiga
**Greedy => sorting,lexographical string,kadane algo,looking for every element
   weather it can be answer??
 
*/

vector<vector<int>> dirs={{-2,2},{2,2},{-2,-2},{2,-2}};

int main()
{
   fastio()
   
   int T{};
   //  cin>>T;
   T=1;
   
   vector<bool> seive=prime();
   
   vector<lli> fact(200001,1);
   
   for(lli i{1};i<200001;i++)
   {
      fact[i]=fact[i-1]*i;
      fact[i]%=1000000007;
   }
   
   vector<int> mf=minfactor(10000001);
   
   for(int Q{};Q<T;Q++)
   {
      /*
         **Observations likh bsdk
         **Apna logic proove kar le ki sahi hi hoga answer
         **Jab bhi max ya min pooche to ek baar binary search dimak me aana chahiye
         **Does any edge case for n==1,n==2,n==0
         **Jo bhi thought aai usko sahi maan kar proof karne ka try kara karo aur agar proof ho gaya to may=tlab sahi hai 
         
         ****************************************************************
                              Binary Search
            
            **Pehle pata karlo ki BS hai
            **Varible socho jis par BS laga hai
            **Predicate socho
            **Monotonocity check karo
         ****************************************************************
         
         ****************************************************************
         
         **Visualisation of problem is most important{So your first step should be visualisation{feel the problem}}
         **Soln sochne ke baad ek baar soch lo isko sabse ache se kaise implement kar sakte hai
         **Agar aise operation kiye ja rahe jisse ki elements increase hi ho rahe hai to maximum element se start karo{same for decrease =>start with minimum element}
         
         ****************************************************************
         
         **{
               cout<<fixed;
               cout<<setprecision(7)<<l<<endl;
           }
      */
      
      int n{},k{};
      cin>>n>>k;
      
      vector<lli> nums=take_input(n),ans(n,0);
      map<lli,lli> mp,mp1;
      
    //   int cnt{};
      
      for(int i{};i<n;i++)
      {
         if(mp.count(nums[i]))
         {
            ans[i]=mp[nums[i]];
            continue;
         }
         
         for(int j{};j<256;j++)
         {
             if(mp.count(j))
             {
                 int a=mp[j];
                 
                 if(abs(a-nums[i])+1<=k)
                 {
                     ans[i]=a;
                     int x=a;
                     
                     while(x<=nums[i])
                     {
                         mp[x]=ans[i];
                         x++;
                     }
                     break;
                 }
             }
             else
             {
                 if(abs(j-nums[i])+1<=k)
                 {
                     ans[i]=j;
                     int x=j;
                     
                     while(x<=nums[i])
                     {
                         mp[x]=ans[i];
                         x++;
                     }
                     break;
                 }
             }
         }
      }
      
      for(int i{};i<n;i++)
      {
         cout<<ans[i]<<" ";
      }
      
      cout<<endl;
   }
   
   return 0;
}