#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define e endl
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,d,l;
    cin>>n>>d>>l;

    if(l==1){
        if((n%2 ==0 && d==0)|| (n%2 ==1 && d==1)){
            for(int i=0;i<n;i++)cout<<1<<" ";cout<<e;
        }
        else cout<<-1<<e;
        return 0;
    }
    vector<int>ve;


    n--;
    while(n--){
        if(d<0){
            ve.push_back(1);
            d=(1-d);
            // cout<<1<<" "<<d<<e;
        }
        else if(d==0){
            ve.push_back(l-1);
            d=l-1;
            // cout<<l-1<<d<<e;
        }
        else{
            ve.push_back(l);
            d= l-d;
            // cout<<l<<" "<<d<<e;
        }
    }
    if(d>0 && d<=l){
        ve.push_back(d);
        for(int i=0;i<ve.size();i++)cout<<ve[i]<<" ";cout<<e;
    }
    else cout<<-1<<e;
    
return 0;
}