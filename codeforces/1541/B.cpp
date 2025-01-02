#include<bits/stdc++.h>
using namespace std;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
long long t;
cin>>t;
while(t--){
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    vector<pair<long long,long long>>d;
    for(long long i=0;i<n;i++){
        d.emplace_back(v[i],i+1);
    }
    sort(d.begin(),d.end());

    long long count=0;
    for(long long i=0;i<n;i++){
        long long j=i+1;
        while((d[i].first)*(d[j].first)<=2*n && j<n){
        if((d[i].first)*(d[j].first)==d[i].second+d[j].second){
            count++;
        }
        j++;

    }
        
    }

    
    cout<<count<<endl;
}
 return 0;
}