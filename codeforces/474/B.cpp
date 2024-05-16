#include<bits/stdc++.h>
using namespace std;
#define fastIOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;

ll bs(vector<pair<ll,ll>> &a,ll n,ll target){
    ll s=0,e=n-1;
    while(s<=e){
        ll mid=s+(e-s)/2;
        if(a[mid].first<=target && a[mid].second>=target){
            return (mid+1);
        }
        else if(a[mid].first>target){
            e=mid-1;
        }
        else if(a[mid].second<target){
            s=mid+1;
        }
    }
    return -1;
}

void worms(){
    ll n,m;
    cin>>n;
    vector<pair<ll,ll>> b; 
    for(int i=0;i<n;i++){
        if(i==0){
            ll ele;
            cin>>ele;
            b.push_back(make_pair(1,ele));
        }
        else{
            ll ele;
            cin>>ele;
            b.push_back(make_pair(b[i-1].second+1,b[i-1].second+ele));
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        ll ele;
        cin>>ele;
        cout<<bs(b,n,ele)<<endl;
    }
    return;
}

int main(){
    worms();
    return 0;
}
