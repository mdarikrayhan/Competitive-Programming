#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
int n,k;
int T[N];

void solve(){
    cin>>n;
    long long ans = 0;
    int t = 0;
    // t代表该点跳的次数
    for(int i=0;i<=n+1;i++)T[i]=0;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++){
        t += T[i];
        if(t>a[i]-1){
            T[i+1] += t-a[i]+1;
            T[i+2] -= t-a[i]+1;
        }
        else {
            ans += a[i]-1-t;
        }
        if(a[i]>1){
            T[i+2]++;
            T[min(n,a[i]+i)+1]--;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }


    return 0;
}
  	 				 			  	 				 		 	  			