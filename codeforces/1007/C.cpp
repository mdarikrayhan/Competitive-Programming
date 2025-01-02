#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int ask(ll x,ll y){x=(n+1-x),y=(n+1-y);cout<<x<<" "<<y<<endl;int ret;cin>>ret;return ret;}
ll clamp(ll x,ll lo,ll hi){
    return max(min(x,hi),lo);
}
ll go(ll xMax,ll yMax,__int128 totalArea,vector<pair<ll,ll>>&restrict){
    __int128 currentArea=0;
    for(int a=1;a<restrict.size();++a){
        ll sliceArea=yMax-restrict[a].second;
        ll xBegin=restrict[a-1].first+1;
        ll xEnd=restrict[a].first;//inclusive
        if(((__int128)(xEnd-xBegin+1)*sliceArea+currentArea)*3<2*totalArea){
            currentArea+=(__int128)(xEnd-xBegin+1)*sliceArea;
        }
        else{
            return clamp(((2*totalArea-3*currentArea)/3+sliceArea-1)/sliceArea+xBegin,restrict[0].first+1,xMax);
        }
    }
    return xMax;
}
ll xMax,yMax;
vector<pair<ll,ll>>restrict,tmr;
signed main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    xMax=yMax=n;
    restrict.push_back({0,n});
    restrict.push_back({n,0});
    while(true){
        //Check if we can die
        __int128 area=(__int128)xMax*(__int128)yMax;
        ll xWall=0;
        for(auto a:restrict){
            area-=(__int128)(a.first-xWall)*a.second;
            xWall=a.first;
        }
        assert(area>0);
        //Find partition point
        xWall=go(xMax,yMax,area,restrict);
        for(auto&a:restrict)swap(a.first,a.second);
        reverse(restrict.begin(),restrict.end());
        ll yWall=go(yMax,xMax,area,restrict);
        for(auto&a:restrict)swap(a.first,a.second);
        reverse(restrict.begin(),restrict.end());
        int res=ask(xWall,yWall);
        if(res==0)return 0;
        else if(res==1){
            xMax=xWall-1;
        }
        else if(res==2){
            yMax=yWall-1;
        }
        else if(res==3){
            restrict.push_back({xWall,yWall});
        }
        else{
            assert(false);
        }
        //Recompute restrict
        for(auto&a:restrict)a.first=min(a.first,xMax),a.second=min(a.second,yMax);
        sort(restrict.begin(),restrict.end());
        tmr.clear();
        for(auto a:restrict){
            while(!tmr.empty()&&tmr.back().second<=a.second)tmr.pop_back();
            tmr.push_back(a);
        }
        restrict.swap(tmr);
    }

}