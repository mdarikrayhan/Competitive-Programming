#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define endl "\n" 
bool checkstr(string s,string temp){
    for(int i=0;i<s.size();i++){
        if(s[i]!=temp[i])return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    int ___=1;
    // cin>>___;
    while(___--){
        string s,temp,ans(101,'z');int n=1,c=0;
        for(int i=0;i<n;i++){
            if(i==0)cin>>s>>n;
            cin>>temp;
            if(checkstr(s,temp))ans=min(ans,temp),c=1;
        }
        if(!c)ans=s;
        cout<<ans<<endl;
    }
    return 0;
}