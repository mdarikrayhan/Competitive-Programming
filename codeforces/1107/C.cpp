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
// cin >> t;
    while (t--) {
long long int n,k,i,p,c=1,sum=0;
cin>>n>>k;
string s;
 
long long int a[n+10];
priority_queue<long long int>pq;
for(i=0; i<n; i++)
cin>>a[i];
a[n]=0;
cin>>s;
 
s+="0";
//cout<<s;
for(i=0; i<n; i++)
{
    if(s[i]==s[i+1])
   { c++;
   pq.push(a[i]);
   
   }
   else
   {//cout<<c<<" ";
       pq.push(a[i]);
       if(c<=k)
       { while(!pq.empty()) 
       {
           sum+=pq.top();
           pq.pop();
       }
          // cout<<sum<<" ";
       }
       else
       {p=k;
           while(p--)
           {
               sum+=pq.top();
           pq.pop();
           }
      
          while(!pq.empty()) pq.pop(); 
           //cout<<sum<<" ";
       }
       c=1;
   }
    
}
cout<<sum<<"\n";
    }
    return 0;
}