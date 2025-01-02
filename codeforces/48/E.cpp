#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
int h[205],t[202],hd[202],tl[202],n,m,cycle=0;
int vis[402][402],mp[402][402];
void dfs(int l,int r,int lim)
{
    vis[l][r]=1;
    int i,j,k;
    if(l+r > lim)return;
    pi tm = {l,r};
    for(i=1; i<=min(n,tm.first); i++)
    {
        int nwx=tm.first-i+h[i];
        int nwy=tm.second+t[i];

        if(vis[nwx][nwy]==0)
        {
            dfs(nwx,nwy,lim);

        }
        else if(vis[nwx][nwy]==1 && nwx+nwy<=lim)
        {
            cycle=1;
            return;
        }

    }
    for(i=1; i<=min(m,tm.second); i++)
    {
        int nwx=tm.first+hd[i];
        int nwy=tm.second+tl[i]-i;

        if(vis[nwx][nwy]==0)
        {
            dfs(nwx,nwy,lim);
        }
        else if(vis[nwx][nwy]==1 && nwx+nwy <= lim)
        {
            cycle=1;
            return;

        }


    }
    vis[l][r]=2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,l,p,x,y,r;
    cin>>x>>y>>r;

    cin>>n;

    for(i=1; i<=n; i++)
    {
        cin>>h[i]>>t[i];
    }
    cin>>m;

    for(i=1; i<=m; i++)
    {
        cin>>hd[i]>>tl[i];
    }

    priority_queue<pii,vector<pii>,greater<pii>>pq;

    //to win check
    pq.push({0,{x,y}});
    for(i=0; i<=r*2; i++)
    {
        for(j=0; j<=r*2; j++)
        {
            mp[i][j]=1e8;
        }
    }

    mp[x][y]=0;
    int drw=0;
    while(pq.size())
    {
        int cst = pq.top().first;
        pi tm = pq.top().second;


        pq.pop();

        if(tm.first+tm.second > r)continue;

        for(i=1; i<=min(n,tm.first); i++)
        {
            int nwx=tm.first-i+h[i];
            int nwy=tm.second+t[i];

            if((cst+1 < mp[nwx][nwy]))
            {
                mp[nwx][nwy]=cst+1;
                pq.push({cst+1,{nwx,nwy}});

            }

        }
        for(i=1; i<=min(m,tm.second); i++)
        {
            int nwx=tm.first+hd[i];
            int nwy=tm.second+tl[i]-i;

            if((cst+1 < mp[nwx][nwy]))
            {
                mp[nwx][nwy]=cst+1;
                pq.push({cst+1,{nwx,nwy}});

            }

        }
    }
    dfs(x,y,r);

    if(mp[0][0]<1e8)
    {
        cout<<"Ivan\n";
        cout<<mp[0][0]<<"\n";
    }
    else if(cycle)
    {
        cout<<"Draw\n";
    }

    else
    {

        cout<<"Zmey\n";
        priority_queue<pii>pq;
        int mx_cost=0;

        //to loose check
        pq.push({0,{x,y}});
        for(i=0; i<=r*2; i++)
        {
            for(j=0; j<=r*2; j++)
            {
                mp[i][j]=0;
            }
        }


        while(pq.size())
        {
            int cst = pq.top().first;
            pi tm = pq.top().second;

            pq.pop();

            if(tm.first+tm.second > r)
            {
                mx_cost=max(mx_cost,cst);
                continue;
            }

            for(i=1; i<=min(n,tm.first); i++)
            {
                int nwx=tm.first-i+h[i];
                int nwy=tm.second+t[i];

                if((cst+1 > mp[nwx][nwy]))
                {
                    mp[nwx][nwy]=cst+1;
                    pq.push({cst+1,{nwx,nwy}});

                }

            }
            for(i=1; i<=min(m,tm.second); i++)
            {
                int nwx=tm.first+hd[i];
                int nwy=tm.second+tl[i]-i;

                if((cst+1 > mp[nwx][nwy]))
                {
                    mp[nwx][nwy]=cst+1;
                    pq.push({cst+1,{nwx,nwy}});

                }

            }
        }
        cout<<mx_cost<<"\n";

    }
}
