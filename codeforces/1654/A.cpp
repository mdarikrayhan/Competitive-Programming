#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define fr(i,n) for(int i=0;i<n;i++)
#define srt(v) sort(v.begin(),v.end())
#define ain(arr,n) for(int i{0};i<n;i++) cin>>arr[i]
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi v,vs;
        int sum=0;
        fr(i,n){
            int a;
            cin>>a;
            v.push_back(a);
            if(i>=1 && i<n){
                sum=v[i]+v[i-1];
                vs.push_back(sum);

            }
        }
        // for(auto itr:vs){
        //     cout<<itr<<" ";
        // }
        // cout<<endl;
        sort(v.begin(),v.end());
        vs.push_back(v[n-1]+v[n-2]);
        int mx=*max_element(vs.begin(),vs.end());
        cout<<mx<<"\n";
    }

}
    

    
