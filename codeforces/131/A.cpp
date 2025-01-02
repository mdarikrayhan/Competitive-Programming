#include<bits/stdc++.h>
#define ll long long int
#define lld long long double
#define N (ll)1e5
#define ct (ll)1000000007
using namespace std;
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    ll check1=0;
    for(int i=1;i<n;i++){
        if(s[i]>=65 && s[i]<=90){
            if(i==n-1) check1=1;
        }
        else break;
    }
    if(check1 || n==1){
        for(int i=1;i<n;i++){
            s[i]=s[i]+32;
        }
        if(s[0]>='a') s[0]=s[0]-32;
        else{
            s[0]=s[0]+32;
        }
    }
    cout<<s<<endl;
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}