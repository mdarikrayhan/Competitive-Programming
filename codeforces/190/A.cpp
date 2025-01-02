#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll t=1;
    while(t--){
        ll n, m; cin >> n >> m;
        if(n==0){
            if(m!=0) cout<<"Impossible"<<endl;
            else cout<<0<<" "<<0<<endl;
        }
        else{
            if(n>m){
                if(m!=0) cout<<n<<" "<<n-1+m<<endl;
                else cout<<n<<" "<<n+m<<endl;
            }
            else{
                if(m!=0) cout<<m<<" "<<n-1+m<<endl;
                else cout<<m<<" "<<n+m<<endl;
            }
        }
    }
}