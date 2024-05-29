#include<bits/stdc++.h>
using namespace std;
#define N 1010
#define ll long long
#define llinf 1000000000000000000ll
mt19937 rng(19260817);
int n;
ll L;
ll block;
ll qvx[N],pvx[N];
pair<ll,ll>ans[N];
void dnq(vector<pair<int,ll>>pos,ll loOut,ll hiOut,ll lIn,ll hIn){
    if(pos.size()==1){
        ans[pos[0].first]={lIn,hIn};
        return;
    }
    for(auto a:pos)pvx[a.first]=a.second;
    ll midOut=(loOut+hiOut)/2;
    vector<int>partition,left,right;
    ll loIn;
    for(auto a:pos)partition.push_back(a.first);
    while(left.size()<midOut-loOut){
        int i=rng()%partition.size();
        int oi=partition[i];
        loIn=lIn;
        ll hiIn=hIn;
        while(loIn<hiIn){
            ll mid=(loIn+hiIn)/2;
            cout<<"? "<<partition[i]+1<<" "<<mid<<endl;
            cin>>qvx[partition[i]];
            if(pvx[partition[i]]+(midOut-loOut)*block<=qvx[partition[i]])hiIn=mid;
            else loIn=mid+1;
        }
        vector<int>pr,pl,pm;
        for(int a:partition){
            if(a==partition[i])continue;
            cout<<"? "<<a+1<<" "<<loIn<<endl;
            cin>>qvx[a];
            if(qvx[a]-pvx[a]>(midOut-loOut)*block){
                pl.push_back(a);
            }
            else if(qvx[a]-pvx[a]==(midOut-loOut)*block){
                pm.push_back(a);
            }
            else{
                pr.push_back(a);
            }
        }
        pm.push_back(oi);
        bool sg=pr.empty();
        if(pl.size()+pm.size()+left.size()<=midOut-loOut){
            for(auto a:pl)left.push_back(a);
            pl.clear();
            for(auto a:pm)left.push_back(a);
            pm.clear();
        }
        if(pr.size()+right.size()<=hiOut-midOut){
            for(auto a:pr)right.push_back(a);
            pr.clear();
        }
        int osz=partition.size();
        partition.clear();
        for(auto a:pl)partition.push_back(a);
        for(auto a:pm)partition.push_back(a);
        for(auto a:pr)partition.push_back(a);
        if(left.size()<midOut-loOut&&osz==partition.size()){
            vector<int>npl,npart=vector<int>{oi};
            for(auto a:partition){
                if(a==oi)continue;
                cout<<"? "<<a+1<<" "<<loIn-1<<endl;
                cin>>qvx[a];
                if(qvx[a]-pvx[a]>=(midOut-loOut)*block){
                    npl.push_back(a);
                }
                else{
                    npart.push_back(a);
                }
            }
            if(npl.empty()){
                for(auto a:npart)left.push_back(a);
                break;
            }
            else{
                if(npl.size()+left.size()<=midOut-loOut){
                    for(auto a:npl)left.push_back(a);
                    loIn--;
                    if(left.size()<midOut-loOut){
                        loIn++;
                        for(auto a:npart)left.push_back(a);
                    }
                    break;
                }
                else{
                    for(auto a:npart)right.push_back(a);
                    partition=npl;
                }
            }
        }
    }
    for(auto a:pos){
        cout<<"? "<<a.first+1<<" "<<loIn<<endl;
        cin>>qvx[a.first];
    }
    sort(pos.begin(),pos.end(),[&](const pair<int,ll>&x,const pair<int,ll>&y)->bool{return qvx[x.first]-x.second>qvx[y.first]-y.second;});
    vector<pair<int,ll>>lb,rb;
    for(int a=0;a<midOut-loOut;++a)lb.push_back(pos[a]);
    for(int a=midOut-loOut;a<pos.size();++a)rb.push_back({pos[a].first,qvx[pos[a].first]});
    dnq(lb,loOut,midOut,lIn,loIn);
    dnq(rb,midOut,hiOut,loIn,hIn);
}
vector<pair<int,ll>>buk;
signed main(){
    iostream::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>L;
    for(int a=0;a<n;++a){
        buk.push_back({a,0});
    }
    block=L/n;
    dnq(buk,0,n,0,llinf);
    cout<<"!\n";
    for(int a=0;a<n;++a)cout<<ans[a].first<<" "<<ans[a].second<<endl;
}