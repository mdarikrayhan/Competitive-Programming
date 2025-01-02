#include<iostream>
#include <iomanip>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        
        // sort(v.begin(),v.end());
        
        double sum=0;
        int m=INT_MIN;
        for(int i=0;i<n;i++){
          if(v[i]>m){
            m=v[i];
          }
            sum+=v[i];
        }
        sum-=m;
        double ans=sum/(n-1);
        cout << fixed <<setprecision(9);
        cout<<ans+m<<endl;
    }
    return 0;
}