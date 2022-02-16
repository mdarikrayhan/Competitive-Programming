#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve() {
       int n;
       cin>>n;
       int ar[n+3];
       for(int i=1;i<=n;i++)cin>>ar[i];
       int ans = 1;
       int val = ar[1];
       int cnt = 1;
       for(int i=2;i<=n;i++)
       {
           if(ar[i]>val)
           {
               if(cnt==val){
                  ans++;
               }
               val = ar[i];
           }
 
           cnt++;
       }
       cout<<ans<<endl;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T = 1;
cin >> T;
while(T--) {
solve();
}
return 0;
}