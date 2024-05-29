#include<bits/stdc++.h>
using namespace std;
vector<long long>v[200005];
int low[200005],tin[200005],vis[200005],tim=1;
set<pair<int,int>>bridge;
void find_bridge(int ind,int par){

    low[ind]=tim++;
    tin[ind]=low[ind];
    vis[ind]=true;
    for(auto t:v[ind]){
        if(t==par)continue;
        if(vis[t]==false){
            find_bridge(t,ind);
            low[ind]=min(low[ind],low[t]);
            if(low[t]>tin[ind]){
                int x=t;
                int y=ind;
                if(x>y)swap(x,y);

                bridge.insert({x,y});
            }
        }
        else{
            low[ind]=min(low[ind],tin[t]);

        }
    }
}
int com[200005];
vector<int>comm[200005];
int kom=1;
void make_bridge(int ind,int par=-1){
    vis[ind]=true;
    com[ind]=kom;
    comm[kom].push_back(ind);
    for(auto t:v[ind]){
        if(t==par || vis[t]==true)continue;
        int x=t;
        int y=ind;
        if(x>y)swap(x,y);
        if(bridge.find({x,y})==bridge.end()){
            make_bridge(t,ind);
        }
    }
}
vector<int>ans;
vector<int>nw_v[2000];
void dfss(int node,int par=-1){
    for(auto t:nw_v[node]){
        if(t==par)continue;
        dfss(t,node);
    }
    if(nw_v[node].size()==1){
        ans.push_back(node);
    }
}
int main()
{
    long long n,m,i,j,k,l,p;
    cin>>n>>m;
    map<pair<int,int>,int>mp;
    for(i=1;i<=m;i++){
        cin>>k>>l;
        mp[{k,l}]=1;
        mp[{l,k}]=1;
        v[k].push_back(l);
        v[l].push_back(k);
    }
    if(n<=2)cout<<-1<<"\n";
    if(n<=2)return 0;

    find_bridge(1,0);
    for(i=0;i<=n;i++)vis[i]=false;
    for(i=1;i<=n;i++){
        if(vis[i]==false){
            make_bridge(i);
            kom++;
        }
    }

    long long com_count[n+2]={0};
    for(auto t:bridge){
        nw_v[com[t.first]].push_back(com[t.second]);
        nw_v[com[t.second]].push_back(com[t.first]);
    }
    dfss(1);
  
    
    vector<pair<int,int>>anss;
    if(ans.size()>0 && (int)ans.size()%2){
        ans.push_back(ans[0]);
    }
    int stt=ans.size();
    stt/=2;
    for(i=0;i<ans.size()/2;i++){
       
            int xx=ans[i];
            int yy=ans[i+stt];
            for(auto t:comm[xx]){
                if(xx==0)break;
                for(auto tt:comm[yy]){
                    if(mp.count({t,tt})==0){
                        anss.push_back({t,tt});
                        mp[{t,tt}]=1;
                        mp[{tt,t}]=1;
                        xx=0;break;
                    }
                    
                }
            }
    }
    cout<<anss.size()<<"\n";
    for(auto t:anss)cout<<t.first<<" "<<t.second<<"\n";
}
 	 	 		 			 		 		 	  	       	