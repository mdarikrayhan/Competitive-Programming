#include <bits/stdc++.h>
using namespace std;

void solve()
{
   int n; cin>>n;
   vector<int> v;
   while(true)
   {
      if(n%7!=0) {n=n-4; if(n>=0) v.push_back(4);} 
      else if(n%7==0)  {n=n-7; if(n>=0) v.push_back(7);}

      if(n<=0) break;
   }
   if(n<0) cout<<-1<<endl;
    else{
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
       cout<<v[i];
    }
   } 
}

int main()
{
        solve();
    

    return 0;
}