#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n+1);
        for(int i=0;i<n;++i){
            int a;
            cin>>a;
            v[a]++;
        }
        sort(v.begin(),v.end());
        int max = v[n];
        int count = 1;
        for(int i =n-1;i>=0;--i){
            if(max==v[i]){
                count++;
            }
            else{
                break;
            }
        }
        cout<<(n-max-count+1)/(max-1)<<endl;
        
    }
}