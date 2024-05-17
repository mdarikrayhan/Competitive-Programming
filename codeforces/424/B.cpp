#include <bits\stdc++.h>
#define ll long long 
using namespace std;
double d(double x,double y){
    return (double) sqrt(pow(x,2)+pow(y,2));
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    double n,l;
    double ans;
   cin>>n>>l;
   vector<pair<double,double>>v(n);
    
   for (int i = 0; i < v.size(); i++)
   {
    double x,y,c;
    cin>>x>>y>>c;
    v[i].first=d(x,y);
    v[i].second=c;
   }
   sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        l+=v[i].second;
        ans=v[i].first;
        if(l>=1000000){
            break;
        }
    }
    if(l<1000000){
        cout<<"-1\n";
    }else
    {
        cout<<fixed<<setprecision(10)<<ans<<endl;

    }
       

}