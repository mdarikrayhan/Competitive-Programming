#include<iostream> 
#include<cstring> 
#include<map> 
using namespace std; 

int main(){
int m,n; cin>>n>>m;
int a[m]; 
string s[n+1]; 
map<int,int> mp; 
for(int i=1;i<=n;i++) cin>>s[i]; 
for(int i=0;i<m;i++){ cin>>a[i]; 
mp[a[i]]++; 
}
int comlen = s[a[0]].length(); 
string out=s[a[0]]; 
bool poss = true;
for(int i=1;i<m;i++){
if(s[a[i]].length()!=comlen){
    poss = false; 
}
for(int j=0;j<comlen;j++){
    if(s[a[i]][j]!=out[j]){
        out[j] = '?'; 
    }
}
}

for(int i=1;i<=n;i++){
if(mp[i]!=0)continue;
if(s[i].length()!=comlen)continue; 
bool flag = false; 
for(int j=0;j<comlen;j++){
    if(out[j]=='?') continue; 
    if(out[j]!=s[i][j]) {flag =true;  break; } 
}
if(flag==false){
    poss=false; break; 
}
}

if(poss){
    cout<<"Yes"<<endl; 
    cout<<out<<endl; 
}else{
     cout<<"No"<<endl; 
}
}