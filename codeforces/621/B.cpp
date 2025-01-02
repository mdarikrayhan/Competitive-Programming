#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fr(i,a,b,k) for(int i=a;i<b;i+=k)
#define frrev(i,a,b,k) for(int i=a;i>b;i-=k)
#define NO cout<<"NO\n"
#define YES cout<<"YES\n"
#define V vector<ll int> 
#define VP vector<pair<ll int,ll int>> 
#define MP map<ll int,ll int> 
#define pb push_back
#define ff first 
#define ss second 
#define input(A) for(auto &i:A)cin>>i
#define output(A) for(auto &i:A)cout<<i<<" "
void solve(int t)
{
 int n;
 cin>>n;
 map<int,int>sum,diff;
 for(int i=0;i<n;i++)
 {
    int x,y;
    cin>>x>>y;
    sum[x+y]++;
    diff[x-y]++;
 }
 ll int ans =0;
 
 for(auto &i:sum)
 ans+=((i.ss)*(i.ss-1))/2;
 
 for(auto &i:diff)
 ans+=((i.ss)*(i.ss-1))/2;
 
 cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
       solve(t);
    }
    return 0;
}

