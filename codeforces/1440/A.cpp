#include<bits/stdc++.h> 
using namespace std;
#define v vector 
#define ll long long
#define pb push_back

void solve(){
    int t,a,c0,c1,d;
    cin>>t;v<int> ss;
    while(t--){
        cin>>a>>c0>>c1>>d;
        string str;cin>>str;
        int val=0;
        for(int i=0;i<a;i++){
            if(str[i]=='0'){
                val+=min(c0,c1+d);
            }else{
                val+=min(c1,c0+d);
            }
        }
        cout<<val<<"\n";
    }
    for(int i=0;i<ss.size();i++){
        cout<<ss[i]<<"\n";
    }
}

int main(){
    solve();
    return 0;
}