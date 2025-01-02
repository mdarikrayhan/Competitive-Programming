#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
using namespace std;


int main(){
    ll n,t,k,d;
    cin>>n>>t>>k>>d;
    ll ans_1=0;
    ll ans_2=d;
    ll number_ovens=(n+k-1)/k;
    for(int i=0;i<number_ovens;i++){
        if(ans_1<=ans_2){
            ans_1+=t;
        }
        else{
            ans_2+=t;
        }
    }
   // cout << number_ovens<<endl;
   // cout<<ans_1<<" "<<ans_2<<endl;
   if(max(ans_1,ans_2)<number_ovens*t){
    cout<<"YES"<<endl;   
    }
   else{
    cout<<"NO"<<endl;
   }
}