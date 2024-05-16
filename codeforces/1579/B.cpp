#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define f(i,a,b) for(int i=a; i<b; i++)

int main(){
    ll t;
    // int z=34;
    cin>>t;
    while(t--){
        // z--;
        int n;
        cin>>n;
        vector<int> v;
        vector<pair<int,int>> ans;
        f(i,0,n){int temp; cin>>temp; v.push_back(temp);}
        // if(z==0){cout<<n<<"/";f(i,0,n){cout<<v[i]<<"//";}}
        f(i,1,n){
            if(v[i]>=v[i-1]){continue;}
            int j; 
            for(j=0;j<i; j++){
                if(v[j]>v[i]){break;}
            }
            ans.push_back(make_pair(j,i));
            // cout<<j<<" "<<i<<endl;
            sort(v.begin(), v.begin()+i+1);
            // for(int i: v){cout<<i<<" ";}cout<<endl;
        }
        cout<<ans.size()<<endl;
        for(auto i: ans){
            cout<<i.first+1<<" "<<i.second+1<<" "<<i.second-i.first<<endl;
        }

    }
    return 0;
}
