#include <iostream> 
#include<cmath>
#include<iomanip>
#include<string.h>
using namespace std; 
void solve();
int main(){ 
ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin); 
freopen("error.txt", "w", stderr); 
freopen("output.txt", "w", stdout); 
#endif 
int t = 1; 
//cin >> t;
while (t--) { 
  solve(); 
}
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
return 0; 
}
void solve(){
int na,nb;
cin>>na>>nb;
int k,m;
cin>>k>>m;
int a[na],b[nb];
for(int i=0;i<na;i++){
  cin>>a[i];
}
for(int i=0;i<nb;i++){
  cin>>b[i];
}
if(a[k-1]<b[nb-m]){
  cout<<"YES";
}
else{cout<<"NO";}
}
