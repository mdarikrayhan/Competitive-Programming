#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
   int b=0,a,A[100000];
   cin>>a;
   for (int i=0; i<a*2; ++i)
  {
   cin>>A[i];
   if (A[i]%2==1)
   b++;
   }
   cout<<((b==a and b!=0)? "YES":"NO")<<endl;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    solve();
    return 0;
}