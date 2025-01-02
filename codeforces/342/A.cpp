#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int gp=n/3;
    int flag=1;
    vector<int>v1;
    for(int i=0;i<gp;i++){
        if(v[i]>=v[i+gp] || v[i+gp]>=v[i+2*gp] || v[i]>=v[i+2*gp]){
            flag=0;
            break;
        } 
        if(v[i]>7 || v[i+gp]>7  || v[i+2*gp]>7){
            flag=0;
            break;
        }
        if(v[i+gp]%v[i]!=0 || v[i+2*gp]%v[i+gp]!=0){
            flag=0;
            break;
        }
    }
    if(flag==1){
    for(int i=0;i<gp;i++){
        cout<<v[i]<<" "<<v[i+gp]<<" "<<v[i+2*gp]<<endl;
    }
    }
    else{
        cout<<"-1"<<endl;
    }
return 0;
}