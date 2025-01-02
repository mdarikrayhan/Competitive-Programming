#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin >> n >> k;
        string s;cin>> s;
        if (k%2==1){
            string odd,even;
            for (int i=0;i<n;i++){
                if (i%2==0){
                    even += s[i];
                } 
                else{
                    odd += s[i];
                } 
            }
            sort(odd.begin(),odd.end());
            sort(even.begin(),even.end());
            for (int i=0;i<n;i++){
                if (i%2==0){
                    cout<<even[i/2];
                } 
                else{
                    cout<<odd[i/2];
                } 
            }
            cout<<endl;
        }
        else{
            sort(s.begin(),s.end());
            cout<<s<<endl;
        }
    }
    return 0;
}