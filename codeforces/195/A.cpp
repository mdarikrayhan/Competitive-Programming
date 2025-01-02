#include<bits/stdc++.h>
using namespace std;
#define fastIOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007


bool possible(int a,int b,int mid,int c){
    return (((mid+c)*b-((c)*a))>=0);
}

void football(){
    int a,b,c;
    cin>>a>>b>>c;
    int s=1;
    int e=a*c;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(possible(a,b,mid,c)){
            e=mid-1;
            ans=mid;
        }
        else{
            s=mid+1;
        }
    }
cout<<ans;
}

int main(){
football();
return 0;
}