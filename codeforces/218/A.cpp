#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
    int n,k,t;cin>>n>>k;
    vector<int>v;
    t=2*n+1;
    while(t--){
        int r;cin>>r;
        v.pb(r);
    }
    for (int i = 1; i < v.size()-1; i++)
    {
        
        if (( v[i] - v[i-1] > 1 ) && (v[i] - v[i+1] > 1) && k>0)
        {
            v[i]-=1;
            k--;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    
    
    return 0;
}