#include<bits/stdc++.h>
using namespace std;
// OM NAMAH SHIVAY

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops,O3")

#define endl "\n"
#define int long long


// int dx[4]={-1,0,1,0};
// int dy[4]={0,1,0,-1};

// int dx[8]={0,-1,-1,-1,0,1,1,1};
// int dy[8]={1,1,0,-1,-1,-1,0,1};

const int N = 200200;
const int mod = 1e9+7;
using ii = pair<int,int>;

//write on copy

void solver(){
    int n,m;
    cin>>n>>m;

    vector<vector<ii>>g(n+1);

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    //cost,s,node
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{arr[1],1}});

    vector<vector<int>>dist(n+1, vector<int>(1001,1e18));
    dist[1][arr[1]]=0;


    while(!pq.empty())
    {
        auto tp = pq.top();pq.pop();

        int node = tp.second.second;
        int prevS = tp.second.first;
       
        int currS = arr[node];

        int s = min(prevS, currS); 

        for(auto c:g[node])
        {
            int child = c.first;
            int d = c.second;

            
            
            if(dist[child][s]>dist[node][prevS]+s*d)
            {
                dist[child][s]=dist[node][prevS]+s*d;
                pq.push({-dist[child][s],{s,child}});
            }
        }
    }

    int ans = 1e18;
    for(int i=1;i<=1000;i++)
    {
        ans=min(ans,dist[n][i]);
    }

    cout<<ans<<endl;
}


signed main()
{
    IOS
    int _t;cin>>_t;while(_t--)
    solver();    
    return 0;
}

#undef int