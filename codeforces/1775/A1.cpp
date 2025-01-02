#include <bits/stdc++.h>
 
using namespace std;

int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        
    string s;
    cin>>s;
    
    int n = s.size();
    bool cc = true;
    for(int i=1;i<=n-2;i++){
        string a = s.substr(0,i);
        for(int j=1;j<=n-i-1;j++){
            string b = s.substr(i,j);
            string c = s.substr(i+j,n-i-j);
            if(b<=a && b<=c){
                cout<<a<<" "<<b<<" "<<c<<endl;
                cc = false;
                break;
            }
            if(b>=a && b>=c){
                cout<<a<<" "<<b<<" "<<c<<endl;
                cc = false;
                break;
            }
        }
        if(!cc){
            break;
        }
    }
    
    }
    
    return 0;
}