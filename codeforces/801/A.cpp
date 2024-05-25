#include<bits/stdc++.h>
#include <fstream>
#define Asma ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define testcase int t; cin>>t; while(t--)
#define ll long long
#define endl "\n"

using namespace std;

vector<ll>divisors(ll n){ //O(sqrt(n))
    vector<ll>ret;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0) {
            ret.emplace_back(i);
            ret.emplace_back(n / i);
        }

    }
    return ret;
}

//gcd(x,0)=x , max val we can get from n%mod is n/2  so log(n)
ll gcd(ll a, ll b) {//O(log(n))
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(a%b,b);
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
ll sum(ll mid){
    return mid*(mid+1)/2;
}
//-----------------------------------------------------------------------------------------------------------------

void solve() {
    string s; cin>>s;
    int ans=0;
    int i=0;
    string temp;
    while(i<s.size()){
        temp+=s[i];
        if(temp.size()==2){
            if(temp=="VK"){
                s[i]='0';
                s[i-1]='0';
                ans++;
                temp.clear();
            }
            else {
                temp.clear();
                temp+=s[i];
            }
        }
        i++;
    }
    i=0;
    temp.clear();
    while(i<s.size()){
       temp+=s[i];
       if(temp.size()==2&&(temp=="VV"||temp=="KK")){
           ans++;
           break;
       }
       else if(temp.size()==2&&!(temp=="VV"||temp=="KK")){
           temp.clear();
           temp+=s[i];
       }
       i++;
    }
    cout<<ans;
}


int main(){
    Asma
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}
	 	  		  	   	  	 			  	 	  		