#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    set<int>s;
    map<int,int>mp;
    s.insert(m);
    vector<pair<int,int>>pr(n);

    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        pr[i]={l,r};
        s.insert(l);
        s.insert(r);
    }

    int j=2;
    if(*s.begin()==1)j=1;

    for(auto &i:s){
        mp[i]=j;
        j++;
    }
  m=mp[m];
//   cout<<m<<endl;
    for(auto &[a,b]:pr){
        a=mp[a];
        b=mp[b];
        // cout<<a<<" "<<b<<endl;
    }
    // cout<<endl;

    vector<int>prsum(m+2,0);
    vector<int>sufsum(m+2,0);
     
    for(auto &[l,r]:pr){
      if(l>1){
        prsum[l]++;
        prsum[r+1]--;
      }
      if(r<m){
        sufsum[l]++;
        sufsum[r+1]--;
      }
    }

    int mx=0;

    for(int i=1;i<=m;i++){
       prsum[i]=prsum[i-1]+prsum[i];
       sufsum[i]=sufsum[i-1]+sufsum[i];
       mx = max({mx,sufsum[i],prsum[i]});
    }
    cout<<mx<<endl;

}

signed main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
        /* code */
    }
    
}