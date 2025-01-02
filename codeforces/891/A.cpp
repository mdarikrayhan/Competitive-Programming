#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mpp make_pair
#define pb push_back
int M = 1e9 + 7;

signed main(){
    int n;
    cin>>n;
    int a[n];
    int f = 0;
    for(int i = 0 ; i < n; i++){
       cin>>a[i];
       if(a[i]==1)f++;
    }
    if(f!=0){
        int ans = n-f;
        cout<<ans<<endl;
    }else{
        int mini = 2001;
        for(int i = 0 ;i < n;i++){
            int gcd = a[i];
            for(int j = i+1 ; j < n ;j++){
                gcd = __gcd(gcd,a[j]);
                if(gcd==1){
                    mini = min(mini,j-i);
                }  
            }
        }
        if(mini==2001) cout<<"-1"<<endl;
        else{
          int ans = n-1 + mini;
          cout<<ans<<endl;
        }
    }
    
}


