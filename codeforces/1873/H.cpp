#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
    
        int n,a,b,i,u,v,x,p,dis_a=-1,dis_b=-1,cnt=0;
        cin>>n>>a>>b;
        set<int>adj[n+1];
        for(i=0;i<n;i++){
            cin>>u>>v;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        queue<int>leaf;
        for(i=1;i<=n;i++){
            if(adj[i].size()==1)leaf.push(i);
        }

        while(!leaf.empty()){
            x=leaf.front();
            leaf.pop();
            p=*adj[x].begin();

            if(x==a){
                dis_a++;
                a=p;
            }
            if(x==b){
                dis_b++;
                b=p;
            }

            adj[p].erase(x);
            if(adj[p].size()==1)leaf.push(p);
            adj[x].clear();
        }

        if(a==b){
            if(dis_a<=dis_b)cout<<"NO\n";
            else cout<<"YES\n";
        }
        else{
            dis_a++;
            p=*adj[a].begin();
            leaf.push(p);
            adj[a].erase(p);
            adj[p].erase(a);
            p=*adj[a].begin();
            leaf.push(p);
            adj[p].erase(a);
            adj[a].clear();

            while(!leaf.empty()){
                x=leaf.front();
                leaf.pop();
                if(x==b)break;

                p=*adj[x].begin();
                adj[p].erase(x);
                leaf.push(p);
                adj[x].clear();

                if(cnt%2)dis_a++;
                cnt++;
            }

            if(dis_a<=dis_b)cout<<"NO\n";
            else cout<<"YES\n";
        }
        
    }

    return 0;
}