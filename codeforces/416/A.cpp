#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    long long a = -2000000000;
    long long b = 2000000000;
    for(int i = 0; i<n+1; i++){
        
        string s;
        getline(cin, s); 
        string ss;
        if(i==0){
          continue;
        }
        //cout<<s.size();
        if(s[1]==' '){
            for(int j = 2; j<s.size()-2; j++){
                ss.push_back(s[j]);
            }
            long long num = stoll(ss);
            
            if(s[0]=='>'){
                if(s[s.size()-1]=='Y'){
                    a=max(a, num+1);
                }
                else{
                    b=min(b, num);
                }
            }
            else{
                if(s[s.size()-1]=='Y'){
                    b=min(b, num-1);
                }
                else{
                    a=max(a, num);
                }
            }
        }
        else{
            for(int j = 3; j<s.size()-2; j++){
                ss.push_back(s[j]);
            }
            long long num = stoll(ss);
            
            if(s[0]=='>'){
                if(s[s.size()-1]=='Y'){
                    a=max(a, num);
                }
                else{
                    b=min(b, num-1);
                }
            }
            else{
                if(s[s.size()-1]=='Y'){
                    b=min(b, num);
                }
                else{
                    a=max(a, num+1);
                }
            }
        }
    }
    if(a<=b){
      cout<<a;
    }else{
      cout<<"Impossible\n";
    }
}