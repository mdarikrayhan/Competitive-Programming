# include<bits/stdc++.h>
using namespace std;

const char nl='\n';

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> ans(n);
        ans[0]=a[0];
        for(int i=1;i<n;i++){
            if(ans[i-1]==0){
                ans[i]=a[i];
            }
            else{
                ans[i]=ans[i-1] & a[i];
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ans[i]==0){
                cnt++;
            }
        }
        if(cnt==0 || cnt==1){
            cout<<1<<nl;
        }
        else{
            cout<<cnt<<nl;
        }
    }
    return 0;
}