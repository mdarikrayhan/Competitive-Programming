#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int  n;
    cin>>n;
    long long int prf[n];
    vector<long long int >v(n);
    for(long long int  i=0;i<n;i++){
      cin>>v[i];
    }
    set<long long int >s;
    s.insert(0);
    long long int  sum=0,ans=0;
    for(long long int  i =0;i<n;i++){
      sum+=v[i];

      if(s.count(sum)){
         ans++;
         s.clear();
         s.insert(0);
         s.insert(v[i]);
         sum=v[i];


      }
      else{
        s.insert(sum);
      }
    }
    cout<<ans;

}
  







  