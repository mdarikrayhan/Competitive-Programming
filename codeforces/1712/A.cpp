#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<stack>
 
#define ll long long int
 
using namespace std;
 
int main(){
int q;cin>>q;
while(q--){
 int n,k;
cin>>n>>k;
bool x=1;
int c=0;
for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        if(temp>(k) && x)c++;
        if(i==k)x=0;
      
}


cout<<c<<endl;
   
}
return 0;
}