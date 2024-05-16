#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 200100
#define Hamim ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    int flg=0;
    for(int i=0;i<n;i++){
        if(v[i]%2)flg++;
    }
    //cout<<(flg?"YES":"NO")<<endl;
    if(flg<n && flg!=0)cout<<"YES"<<endl;
    else if(n%2 && flg)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    Hamim
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}

