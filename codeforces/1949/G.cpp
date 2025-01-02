#include<bits/stdc++.h>
using namespace std;
int n;string s,t;
vector<int> v[3][3];
vector<int> ans;
inline int get(char x){
    if(x=='-') return 0;
    if(x=='C') return 1;
    return 2;
}
stack<int> fr[3];
int to[2005];
vector<int> zhu;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++){
        int u=get(s[i-1]),v=get(t[i-1]);
        if(u!=v)
        ::v[u][v].push_back(i);
    }
    for(int i:{1,2})
    for(auto x:v[0][i]) fr[i].push(x),zhu.push_back(x);
    if(fr[1].empty()&&!v[2][1].empty()){
        int p=fr[2].top();fr[2].pop();
        int w=v[2][1].back();v[2][1].pop_back();
        to[p]=w;fr[1].push(w);
    }
    if(fr[2].empty()&&!v[1][2].empty()){
        int p=fr[1].top();fr[1].pop();
        int w=v[1][2].back();v[1][2].pop_back();
        to[p]=w;fr[2].push(w);
    }
    while(!v[2][1].empty()||!v[1][2].empty()){
        if(!v[2][1].empty()){
            int p=fr[2].top();fr[2].pop();
            int w=v[2][1].back();v[2][1].pop_back();
            to[p]=w;fr[1].push(w);
        }
        if(!v[1][2].empty()){
            int p=fr[1].top();fr[1].pop();
            int w=v[1][2].back();v[1][2].pop_back();
            to[p]=w;fr[2].push(w);
        }
    }
    for(int i:{1,2})
    for(auto x:v[i][0]){
        int p=fr[i].top();fr[i].pop();
        to[p]=x;
    }
    for(auto x:zhu){
        int p=x;if(to[p])
        ans.push_back(p);
        while(to[p]){
            ans.push_back(-1);
            p=to[p];
            ans.push_back(p);
            ans.push_back(-2);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans){
        if(x>0) cout<<"DRIVE "<<x<<'\n';
        else if(x==-1) cout<<"PICKUP\n";
        else cout<<"DROPOFF\n";
    }
}