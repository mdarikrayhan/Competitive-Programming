// LUOGU_RID: 157297216
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,INF=5e8+10;

struct State{
    map<int,int> u,d;
    set<tuple<int,int,int>> segs;
    int t;

    State(){
        u[INF*2]=0;
        u[-INF*2]=0;
        d[INF*2]=0;
        d[-INF*2]=0;
    }
    void add(int p,int v){
        // cerr<<"raw_add "<<p<<" "<<v<<endl;
        auto itu=u.lower_bound(p+t),itd=d.upper_bound(p-t);
        if(itu->first-t < itd->first+t){
            auto htu=prev(itu),htd=prev(itd);
            if(htd->first+t > htu->first-t && abs(itu->first)<INF && abs(htd->first)<INF){
                // cerr<<"remove "<<htd->first+t<<" "<<itu->first-t<<"  "<<htd->first<<" "<<itu->first<<endl;
                int _=segs.erase({itu->first-htd->first,htd->first,itu->first});
                // if(!_)cerr<<"??"<<endl;
            }
        }
        itu=u.lower_bound(p+t);
        itd=d.lower_bound(p-t);
        
        if(itu->first-t==p)v+=itu->second,u.erase(itu);
        if(itd->first+t==p)v-=itd->second,d.erase(itd);

        if(v>0){
            u[p+t]=v;
            // cerr<<"U "<<p+t<<" "<<v<<endl;
            auto htu=prev(u.lower_bound(p+t));
            auto htd=prev(d.lower_bound(p-t));
            if(htd->first+t > htu->first-t && abs(htd->first)<INF){
                // cerr<<"insert "<<htd->first+t<<" "<<p<<"  "<<htd->first<<" "<<p+t<<endl;    
                segs.insert({p+t-htd->first,htd->first,p+t});
            }
        } else if(v<0) {
            d[p-t]=-v;
            // cerr<<"D "<<p-t<<" "<<v<<endl;
            auto itd=d.upper_bound(p-t);
            auto itu=u.upper_bound(p+t);
            if(itu->first-t < itd->first+t && abs(itu->first)<INF){
                // cerr<<"insert "<<p<<" "<<itu->first-t<<"  "<<p-t<<" "<<itu->first<<endl;
                segs.insert({itu->first-(p-t),p-t,itu->first});
            }
        } else {
            auto itu=u.lower_bound(p+t),itd=d.lower_bound(p-t);
            if(itu->first-t < itd->first+t){
                auto htu=prev(itu),htd=prev(itd);
                if(htd->first+t > htu->first-t && abs(itu->first)<INF && abs(htd->first)<INF){
                    // cerr<<"insert "<<htd->first+t<<" "<<itu->first-t<<"  "<<htd->first<<" "<<itu->first<<endl;
                    segs.insert({itu->first-htd->first,htd->first,itu->first});
                }
            }
        }
    }
    void merge(const State b){
        for(auto it:b.u){
            if(abs(it.first)<INF)add(it.first-b.t,it.second);
        }
        for(auto it:b.d){
            if(abs(it.first)<INF)add(it.first+b.t,-it.second);
        }
    }
    void extend(int dt){
        while(segs.size()&&get<0>(*segs.begin())<=(t+dt)*2){
            auto [len,dt,ut]=*segs.begin();
            // cerr<<"Seg: "<<len<<" "<<dt<<" "<<ut<<" "<<t<<endl;
            int dv=0,uv=0;
            auto it=d.find(dt);
            auto jt=u.find(ut);
            if(it!=d.end())dv=it->second;
            if(jt!=u.end())uv=jt->second;
            add(dt+t,min(dv,uv));
            add(ut-t,-min(dv,uv));
        }
        t+=dt;
    }
    int delta_if_extend_one(int p){
        int du=0,dd=0;
        if(auto it=u.find(p+1+t);it!=u.end())du=it->second;
        if(auto it=d.find(p-t);it!=d.end())dd=it->second;
        return max(du,dd);
    }
    vector<pair<int,int>> get_array(){
        vector<pair<int,int>> res;
        for(auto i:u)res.push_back({i.first-t, i.second});
        for(auto i:d)res.push_back({i.first+t, -i.second});
        sort(res.begin(),res.end());
        return res;
    }
};
void swap(State &a,State &b){
    swap(a.d,b.d);
    swap(a.u,b.u);
    swap(a.segs,b.segs);
    swap(a.t,b.t);
}

vector<pair<int,int>>to[N];
vector<pair<int,int>>obs[N];
State f[N];

int rt=1;

void ss(int x,int fa,int lfa){
    for(auto [y,z]:to[x]){
        if(y==fa)continue;
        ss(y,x,z);
        if(f[y].d.size()>f[x].d.size()){
            swap(f[x],f[y]);
        }
        f[x].merge(f[y]);
        // cerr<<"<<<<< "<<x<<"  ";
        // for(auto [p,v]:f[x].get_array())cerr<<p<<":"<<v<<" ";
        // cerr<<"  + ";for(auto [p,v]:f[x].u)cerr<<p<<":"<<v<<" ";
        // cerr<<"  - ";for(auto [p,v]:f[x].d)cerr<<p<<":"<<v<<" ";
    }
    // cerr<<endl;
    for(auto &[z,w]:obs[x]){
        w-=f[x].delta_if_extend_one(z);
    }
    f[x].extend(1);
    for(auto [z,w]:obs[x]){
        // cerr<<"> "<<z<<" "<<w<<endl;
        if(w>0){
            f[x].add(z,w);
            f[x].add(z+1,-w);
        }
    }
    f[x].extend(lfa-1);
    // cerr<<"> "<<x<<"  ";
    // for(auto [p,v]:f[x].get_array())cerr<<p<<":"<<v<<" ";
    // cerr<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y,z;
        cin>>x>>y>>z;
        z*=2;
        to[x].push_back({y,z});
        to[y].push_back({x,z});
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x*=2;
        obs[z].push_back({x,y});
    }
    ss(rt,0,1);
    int cur=0,ans=0;
    for(auto [x,y]:f[rt].get_array()){
        cur+=y;
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
    return 0;
}
