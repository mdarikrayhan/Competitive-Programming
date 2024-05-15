/*
    Author: Rakib Sarder
    Codeforces: iamrakibsarder
*/

#include <bits/stdc++.h>

#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define yes             cout<<"YES"<<endl
#define no              cout<<"NO"<<endl
#define INF             100000000

using namespace std;
 
void speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

ll lcm(ll l, ll r){
    if (l<r){
        if(r%l==0){
            return r;
        }else{
            return r * l;
        }
    }else{
        if(l%r==0){
            return l;
        }else{
            return r * l;
        }
    }
}

void solve(){
          string s;            cin>>s;
      int n=s.size();
 
      if(count(s.begin(),s.end(),'?')==0){
         cout<<s<<endl;
         return;
      }
 
      char last='?';
      queue<int> later;
      for(int i=0;i<n;i++){
         if(s[i]=='?'){
            later.push(i);
            continue;
         }
         last=s[i];
         while(!later.empty()){
            s[later.front()]=s[i];
            later.pop();
         }
      }
 
 
      char c='0';
      if(last=='1')c='1';
      while(!later.empty()){
         s[later.front()]=c;
         later.pop();
      }
 
      cout<<s<<endl;

}




int main() {
    file();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    //solve();
    return 0;
}