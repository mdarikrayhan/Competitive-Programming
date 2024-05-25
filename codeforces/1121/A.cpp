/*Les do some thikr:
Subhanalloh
Alhamdulillah
Allohu akbar
Astagfirull0h
Subhanallohi wabihamdihi subhanllohil atheem
La hawla wala quwwata illa billah
La ilaha illalloh 
and durood
Sollallohu alaihi wa sallam
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
 //cin >> t;
    while (t--) {
   long long int n,mi,k,x,c=0,i;
   cin>>n>>mi>>k;
   long long int a[n+10],b[n+10],m[mi+10]={0};
   for(i=0; i<n; i++)
  { cin>>a[i];
  }
    for(i=0; i<n; i++)
   {cin>>b[i];
   m[b[i]]=max(a[i],m[b[i]]);
  
   }
  
    for(i=0; i<k; i++)
    {
        cin>>x;
        x--;
       if(a[x]!=m[b[x]])c++;
    }
    cout<<c;
    }
    return 0;
}