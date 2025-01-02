#include <bits/stdc++.h>
using namespace std;
using ll=long long int;



int main()
{
int t;cin>>t;
while(t--){
   int ADS;
    string s;
    cin>>s;
    bool f=false;
    for(int i=0;i<s.length();i++){
        if(i!=s.length()-1){
            if(s[i]=='i'&&s[i+1]=='t'){
                f=true;break;
            }
        }
    }
    if(f)
    cout<<"YES"<<endl;
    else 
    cout<<"NO"<<endl;
}
    return 0;
}