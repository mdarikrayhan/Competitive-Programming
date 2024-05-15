#include<bits/stdc++.h>
#define ll long long
using namespace std ;
int main()
{
    int t ;
    cin>>t ;
    while(t--){
        ll n ;
        cin>>n ;
        char c ;
        cin>>c ;
        string s ;
        cin>>s ;
        s+=s ;
        ll count=0 ;
        ll maxi=0 ;
        for(ll i=0 ;i<s.length() ;i++){
            if(s[i]==c){
                count=0 ;
                while(s[i]!='g' && i<s.size()){
                    count++ ;
                    i++ ;
                }
                maxi=max(count,maxi) ;
            }
            
        }
        cout<<maxi<<endl ;
    }
    return 0 ;
}