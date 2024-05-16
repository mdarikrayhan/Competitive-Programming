#include<bits/stdc++.h>
 
#define ll long long
#define el endl
#define vll vector<ll>
#define yes() cout << "YES" << el
#define no() cout << "NO" << el
 
using namespace std;
 
void solve();
 
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	//ll t; cin>>t;
	ll t=1;
	while(t--){
		solve();
	}
	
	return 0;
}
 
void solve(){
    ll n; cin>>n;
    vll vec;
    ll num25 = 0, num50 = 0, num100 = 0;
    
    for(ll i = 0; i < n; i++){
        ll x; cin>>x;
        vec.push_back(x);
    }
    
    for(ll i = 0; i < n; i++){
        ll dif = vec[i] - 25;
        if(dif > 0){
            if(dif == 25){
                if(num25 > 0){
                    num50++;
                    num25--;
                }
                else{
                    no();
                    return;
                }
            }
            else{
                if(num25 > 0 && num50 > 0){
                    num25--;
                    num50--;
                    num100++;
                }
                else if(num25>=3){
                    num25-=3;
                    num100++;
                }
                else{
                    no();
                    return;
                }
            }
        }
        else{
            num25++;
        }
    }
    
    yes();
    return;
}