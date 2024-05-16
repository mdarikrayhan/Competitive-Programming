#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e16;
const int mod=1000000007;
#define F first
#define S second

void solve(){
   int n;
   cin>>n;
   vector<int> a(n),b(n+1);

   for (int i = 0; i < n; ++i)
   {
      cin>>a[i];
   }
   sort(a.begin(),a.end());
   int ans=0;
   for (int k = 1; k <= n; ++k)
   {
      for (int i = 0; i <= n; ++i)
      {
         b[i]=0;
      }
      for (int i = k; i >=1; --i)
      {
         for (int j = n-1; j >=0; --j)
         {
            if(a[j]<=i){
               b[i]=j+1;
               break;
            }
         }
      }
      int f=1;
      for (int i = 1; i <= k; ++i)
      {
         if(b[i]<i+k-1)f=0;
      }
      if(f)ans=k;
   }
   cout<<ans<<endl;

}


signed main() {
	ios_base::sync_with_stdio(false);
	int t=1;
	cin>>t;
	while(t--)
	solve();
   
	return 0;
}