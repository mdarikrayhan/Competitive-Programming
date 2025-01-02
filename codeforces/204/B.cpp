#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

void solve(){
    ll n;cin>>n;
    map<ll,ll> mF,mT;
    for (int i = 0; i < n; ++i) {
        ll x,y;
        cin>>x>>y;
        mF[x]++;
        mT[x]++;
        if(x != y) mT[y]++;
    }
    bool f=false;
    ll mini=LONG_LONG_MAX;
    for(auto it=mT.begin();it != mT.end();it++){
        if(it->second >= (n+1)/2){
            f= true;
            if(mF[it->first] >= (n+1)/2){
                cout<<0<<endl;
                return;
            }else if(mini>(n+1)/2 - mF[it->first]){
                mini=(n+1)/2 - mF[it->first];
            }
        }
    }

    f? cout<<mini<<endl:cout<<-1<<endl;
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
	 	  		   	 	 	  				  	  	 		