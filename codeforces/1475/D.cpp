/*Industry is the key to success */
#include                                   <bits/stdc++.h>
#include                                   <iostream>
#include                                   <cmath>
#define               ll                   long long
#define               ff                   first
#define               vi                   vector<int>
#define               vl                   vector<ll>
#define               ss                   second
#define               pb                   push_back
#define               in                   insert
#define               sci(n)               scanf("%d",&n)
#define               scl(n)               scanf("%lld",&n)
#define               scc(c)               scanf("%c",&c)
#define               scs(s)               scanf("%s",s);
#define               prini(n)             printf("%d\n",n)
#define               prinl(n)             printf("%lld\n",n)
#define               princ(c)             printf("%c",c)
#define               prins(s)             printf("%s",s)
#define               ppb                  pop_back
#define               tp                   top()
#define               ppf                  pop_front
#define               pf                   push_front
#define               YES                  printf("YES\n")
#define               Yes                  printf("Yes\n")
#define               NO                   printf("NO\n")
#define               No                   printf("No\n")
#define               vb                   vector<bool>
#define               vs                   vector<string>
#define               inputi(a,n)          for(int i=1;i<=n;i++)scanf("%d",&a[i])
#define               vpi                  vector<pair<int,int>>
#define               vvi                  vector<vector<int>>
#define               pqmini               priority_queue<int,vector<int>,greater<int>>
#define               pqmaxi               priority_queue<int>
#define               pqminl               priority_queue<ll,vector<ll>,greater<ll>>
#define               pqmaxl               priority_queue<ll>
#define               mpii                 map<int,int>
#define               mpll                 map<ll,ll>
#define               mpil                 map<int,ll>
#define               mpli                 map<ll,int>
#define               mpib                 map<int,bool>
#define               mplb                 map<ll,bool>
#define               mpsi                 map<string,int>
#define               Seti                 set<int>
#define               inputl(a,n)          for(int i=1;i<=n;i++)scanf("%lld",&a[i])
#define               mkp(left,right)      make_pair(left,right)
#define               vpll                 vector<pair<ll,ll>>
#define               Qi                   queue<int>
#define               ld                   long double
#define               pll                  pair<ll,ll>
#define               pii                  pair<int,int>
#define               gi                   greater<int>
#define               ull                  unsigned long long int
#define               vvl                  vector<vector<ll>>
#include              <math.h>
#define               pie                  3.14159265358979323846
#define               rev(a)               reverse(a.begin(),a.end())
#define               nl                   printf("\n")
/* trigonometry: x=angle in redian :val=sin(x):val=cos(x):val=tan(x)
x=atan(val):x=acos(val):x=asin(val): x is in redian:
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
/*
above template is using in ordered set...the defference between ordered set and  set is
two operation....
1.order_of_key(x);    *here order_of_key give the position of the value x.
2.find_by_order(x);   **here find_by_order give the value of position x..In
 o(n)..                     other words give the positioned value like as vector or array

all other operation is operation is same to set..
NOTE:  order set supports both of dublicate and unique value.
We need to little bit change for this ...above defination less->less_equal
or greater_equal..
*/
ll const inf=1e9+7;
ll const hell=1e17;
ull expon(ull base,ull p,ull mod){ if(p==0)return 1;if(p==1)return base;
ull res=expon(base,p/2,mod)%mod;if(p%2==0)return (res%mod*res%mod)%mod;
else return ((res%mod*res%mod)%mod*base%mod)%mod;}
int _Gcdi(int a,int b){if(b==0)return a; else return _Gcdi(b,a%b);}
ll _Gcdl(ll a,ll b){if(b==0)return a; else return _Gcdl(b,a%b);}
using namespace std;
int tt=0;
void solution()
{
    int n,m;    sci(n);    sci(m);
    int a[n+1];    inputi(a,n);
    int b[n+1];    inputi(b,n);
    vl one(1,0);
    vl two(1,0);
    int ans=0;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==1)one.pb(a[i]);
        else two.pb(a[i]);
        ans+=b[i];
        sum+=a[i];
    }
    if(sum<m){
        cout<<"-1"<<endl;
        return;
    }
    sort(one.begin()+1,one.end(),greater<ll>());
    sort(two.begin()+1,two.end(),greater<ll>());
    for(int i=1;i<one.size();i++)one[i]=one[i]+one[i-1];
    for(int i=1;i<two.size();i++)two[i]=two[i]+two[i-1];
    int add1=1;  int add2=2;
    for(int i=0;i<one.size();i++)
    {
        ll cur=one[i];
        int temp=i*add1;
        ll more=m-cur;
        int ind=lower_bound(two.begin(),two.end(),more)-two.begin();
        if(two.size()<=ind)continue;
        //cout<<more<<" "<<i<<endl;
        temp+=(ind*add2);
        ans=min(ans,temp);
    }
    cout<<ans<<endl;
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    //cout.tie(NULL);
    int t=1;
   sci(t);
//   precal();
 //  sieve();
    while(t--)
    {
     // cout<<endl;
      solution();
    }
}
