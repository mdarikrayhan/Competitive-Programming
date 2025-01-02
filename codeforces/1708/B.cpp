#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,l,r;
        cin>>n>>l>>r;
        bool f=1;
        vector<long long>ans;
        for(long long i=1;i<=n;i++){
            if(ceil((long double)l/(long double)i)<=(r/i)){
                ans.push_back((long long)i*ceil((long double)l/(long double)i));
            }else{
                f=0;
                break;
            }
        }
        if(f){
            cout<<"YES"<<endl;
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}