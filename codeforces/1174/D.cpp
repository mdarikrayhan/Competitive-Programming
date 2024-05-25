// LUOGU_RID: 160120657
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  int n,x; cin>>n>>x;
  vector<bool> b(1<<n);
  if(x>=1<<n)x=0;
  vector<int> r;
  for(int i=b[x]=1;i<1<<n;i++)
    if(!b[i])r.emplace_back(i),b[i^x]=true;
  adjacent_difference(r.begin(),r.end(),r.begin(),bit_xor<>());
  cout<<r.size()<<endl;
  for(int i:r)cout<<i<<' ';
  cout<<endl;
  return 0;
}