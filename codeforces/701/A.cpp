#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>x,pair<int,int>y)
{
       return x.first<y.first;
}
void solve()
{
       int n;
       cin>>n;
       vector<pair<int,int> >a(n);
       for(int i=0;i<n;i++){
              cin>>a[i].first;
              a[i].second=i+1;
       }
       sort(a.begin(),a.end(),cmp);
       for(int i=0,j=n-1;i<n/2;i++,j--){
              cout<<a[i].second<<' '<<a[j].second<<endl;
       }
       return ;
}
int main()
{
       solve();
       return 0;
}
