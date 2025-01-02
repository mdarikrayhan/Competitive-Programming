#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> res(k+1,0);

    vector<int> minInd(k+1,n);
    vector<int> maxInd(k+1,-1);
    set<int> s;

    int temp=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s.insert(arr[i]);
        temp=max(temp,arr[i]);
        minInd[arr[i]]=min(minInd[arr[i]],i);
        maxInd[arr[i]]=max(maxInd[arr[i]],i);
    }

    // for(auto i:minInd){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i:maxInd){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // cout<<temp<<endl;

    int l=n;
    int r=-1;
    
    for(int i=temp;i>=1;i--){
        if(s.find(i)==s.end()) continue;
        int mini=minInd[i];
        int maxi=maxInd[i];

        r=max(maxi,r);
        l=min(mini,l);

        res[i]=r-l+1;

        // if(mini==n && maxi==-1){
        //     res[i]=0;
        //     continue;
        // }
        // if(mini==n){
            
        //     res[i]=0;
        //     continue;
        // }
    }

    for(int i=1;i<=k;i++){
        cout<<2*res[i]<<" ";
    }
    cout<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}