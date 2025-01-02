#include<bits/stdc++.h>
using namespace std;
#define int             long long

void solve(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  sort(v.begin(),v.end());

  vector<int>w,x;
  for(int i=0;i<n;i++){
    if(i>0){
      if(v[i]==v[i-1])x.push_back(v[i]);
      else w.push_back(v[i]);
    }
    else w.push_back(v[i]);
  }
  int res(0);
  for(int i=0;i<=w.size();i++){
    auto it = find(w.begin(),w.end(),i);
    if(it==w.end()){
      res+=i;
      break;
    }
  }
  if(x.size()==0)cout<<res<<"\n";
  else{
    for(int i=0;i<=x.size();i++){
      auto it = find(x.begin(),x.end(),i);
      if(it==x.end()){
        res+=i;
        break;
      }
    }
    cout<<res<<"\n";
  }
}
int32_t main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int t;
cin>>t;
while(t--){
solve();
}
return 0;
}