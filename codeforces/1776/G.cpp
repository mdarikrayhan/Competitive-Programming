#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main(){
    IOS
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c=0;
    for(int i=0;i<n;++i){
        c+=(s[i]=='W');
    }
    int ans=c;
    for(int i=n;i<2*n-1;++i){
        c+=(s[i]=='W');
        c-=(s[i-n]=='W');
        ans=max(ans,c);
    }
    cout<<ans;
    return 0;
}

