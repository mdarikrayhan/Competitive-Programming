#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
   vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int ops=0;
    vector<pair<int,int>>p;

    while(ops<30){

    int mn=*min_element(a.begin(),a.end());
    int mx=*max_element(a.begin(), a.end());
    int mn_i=distance(a.begin(), find(a.begin(), a.end(), mn));
    

    if(mn==1 && mx!=1){cout<<-1<<endl;return;}
    
    for(int i=0;i<n;i++){
       while(a[i]>mn){
        p.push_back({i+1, mn_i+1});
          a[i]=ceil(a[i]/(mn*1.0));
       }
    }
     
      mn=*min_element(a.begin(),a.end());
      mx=*max_element(a.begin(), a.end());

      if(mn==mx)
      break;
    ops++;

    }

    cout<<p.size()<<endl;
    for(int i=0;i<p.size();i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    cout<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    solve();
}