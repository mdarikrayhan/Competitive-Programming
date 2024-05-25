//I am beginner dont hack me plzzz :-)
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<unordered_map>

using namespace std;
#define ll long long
#define rp(i,n) for(ll int i=0;i<n;i++)
#define ina(arr,n) rp(i,n){cin>>arr[i];}
#define outa(arr,n) rp(i,n){cin>>arr[i]<<' ';}
#define sorta(vec) sort(vec.begin(),vec.end())
#define sortd(vec) sort(vec.rbegin(),vec.rend())

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int > a(2*n);
    rp(i,2*n){
        cin>>a[i];
    }
    sorta(a);
    int maxx=10000000;
    
    for(int i=0;i<2*n;i++){
        for(int j=i+1;j<2*n;j+=1){
         int ans=0;
        vector<int> b;
        for(int k=0;k<2*n;k++){
            if (k==i || k==j){
                continue;
            }
            else{
                b.push_back(a[k]);
            }
        }     
        
        for(int k=0;k<=2*n-4;k+=2){
            ans+=abs(b[k+1]-b[k]);
        }  
        
        maxx=min(maxx,ans);  
        }
    }
    cout<<maxx;

return 0;
}