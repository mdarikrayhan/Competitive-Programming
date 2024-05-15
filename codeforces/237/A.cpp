#include<bits/stdc++.h>
using namespace std;



int main() {
int t;
cin>>t;
int arr[t];
for(int i=0;i<t;i++){
    int h,m;
    cin>>h>>m;
    arr[i]=(h*60)+m;
}
unordered_map<int,int> mpp;
for(int i=0;i<t;i++){
    mpp[arr[i]]++;
}
int maxi=0;
for(auto x:mpp){
    if(x.second>=maxi){
        maxi=x.second;
    }
}
cout<<maxi<<endl;
   return 0;
}
//Every complete string is also a subsequence of itself
