#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1e9 + 7;
#define inf 1e17

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    b[0]=0;
    int dist[n+1];
    int parent[n+1];
    for(int i=0;i<=n;i++){
        dist[i]=inf;
        parent[i]=-1;
    }
    for(int i=1;i<=n;i++){
        a[i]=i-a[i];
        if(a[i]<0){
            a[i]=0;
        }
        b[i]=i+b[i];
        if(b[i]>n){
            b[i]=n; 
        }
    }
    queue<int> s;
    s.push(n);
    dist[n]=0;
    parent[n]=-1;
    int parentfornav[n+1];
    for(int i=0;i<=n;i++){
        parentfornav[i]=-1;
    }
    bool visited[n+1];
    for(int i=0;i<=n;i++){
        visited[i]=false;
    }
    visited[n]=true;
    int cur=n;
    while(s.size()>0){
        auto it=s.front();
        int ind=it;
        if(ind==0){
            break;
        }
        s.pop();
        for(int i=a[ind];i<cur;i++){
            if(!visited[i]){
                s.push(b[i]);
                if(dist[b[i]]>dist[ind]+1){
                    parentfornav[b[i]]=ind;
                    parent[b[i]]=i;
                    dist[b[i]]=dist[ind]+1;
                }
                visited[i]=true;
            }
        }
        cur=min(a[ind],cur);
        auto it1=s.front();
        if(s.size()==1 && it1==n){
            break;
        }
    }

    // for(int i=0;i<=n;i++){
    //     cout<<parent[i]<<' ';
    // }
    // cout<<endl;
    // for(int i=0;i<=n;i++){
    //     cout<<dist[i]<<' ';
    // }
    // cout<<endl;
    if(dist[0]==inf){
        cout<<-1<<endl;
    }else{
        int x=0;
        int y=0;
        vector<int> v;
        while(x!=n){
            v.push_back(y);
            x=parentfornav[x];
            y=parent[x];
        }
        reverse(v.begin(),v.end());
        cout<<v.size()<<endl;
        for(auto it:v){
            cout<<it<<' ';
        }
        cout<<endl;
    }


}