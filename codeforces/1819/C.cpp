// LUOGU_RID: 160380272
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[200100];
bool on[200100];
int far,fard;
void FAR(int n,int p,int d){
    if(d>fard)far=n,fard=d;
    for(auto i:adj[n]) if(i-p) 
        FAR(i,n,d+1);
}
vector<int>path;
bool gp(int n,int p,int t){
    path.push_back(n);
    if(n==t)return on[n]=1;
    for(auto i:adj[n])
        if(i-p&&gp(i,n,t))
            return on[n]=1;
    path.pop_back();
    return on[n]=0;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    if(n<=3){
        cout<<"Yes\n";
        for(int i=0;i<n;)
            cout<<++i<<' ';
        return 0;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    FAR(1,0,0);
    int X=far,Y;
    fard=0;
    FAR(X,0,0);
    Y=far;
    gp(X,0,Y);
    for(int i=1;i<=n;i++)
        if(!on[i]&&adj[i].size()>1)
            return puts("No"),0;
    cout<<"Yes\n";
    if(path.size()%2){
        for(int i=path.size()-1;i+2;i-=2){
            cout<<path[i]<<' ';
            if(i)for(auto x:adj[path[i-1]])
                if(!on[x])cout<<x<<' ';
        }
        for(int i=1;i<path.size();i+=2){
            for(auto x:adj[path[i-1]])
                if(!on[x])cout<<x<<' ';
            cout<<path[i]<<' ';
        }
    } else {
        for(int i=path.size()-1;i+1;i-=2){
            cout<<path[i]<<' ';
            for(auto x:adj[path[i-1]])
                if(!on[x])cout<<x<<' ';
        }
        for(int i=0;i<path.size();i+=2){
            if(i)for(auto x:adj[path[i-1]])
                if(!on[x])cout<<x<<' ';
            cout<<path[i]<<' ';
        }
    }
}