#include<bits//stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        int ans=k;
        
        int cnt=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(arr[i]%2==0) cnt++;
            if(arr[i]%k==0) ans=0;
            else{
                ans=min(ans,k-(arr[i]%k));
            }
            }
        if(k==4){
            if(cnt>=2) ans=0;
            else if(cnt==1) ans=min(ans,1);
            else ans=min(ans,2);
        }
        cout<<ans<<endl;
      
    }
    return 0;
}