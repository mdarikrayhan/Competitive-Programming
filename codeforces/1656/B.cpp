#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n";
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
typedef long long int ll;
int main(){
    fast int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        bool f=true;
        for(int i=0;i<n-1;i++){
            auto it=binary_search(a.begin()+i+1,a.end(),a[i]+k);
            if(it){
                yes;
                f=false;
                break;
            }
        }
        if(f) no;
    }
}