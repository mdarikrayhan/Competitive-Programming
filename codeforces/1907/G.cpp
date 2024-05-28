#include<bits/stdc++.h>
#define rep(i,x,n) for(int i=x;i<=n;i++)

using namespace std;

const int N = 2e5+10;

int t,n,x;
int st[N],vis[N],to[N],dg[N];
vector<int> g[N];

main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    
    for(cin >> t;t--;)
    {
        cin >> n;
        string s; cin >> s;
        rep(i,1,n) {
            g[i].clear();
            vis[i]=0;
            dg[i]=0;
            st[i]=s[i-1]-'0';
        }
        rep(i,1,n) cin >> to[i],dg[to[i]]++,g[i].emplace_back(to[i]);
        queue<int> q;
        rep(i,1,n) if(!dg[i]) q.push(i);
        vector<int> ans;
        // rep(i,1,n) cout << dg[i] << " ";cout << "&\n";
        while(q.size())
        {
            auto w = q.front(); q.pop(); vis[w]=1;
            
            for(auto i:g[w]) {
                // cout << st[w] << " " << w << "*\n";
                if(!--dg[i]) q.push(i);
                if(st[w]) st[w]=0,st[i]^=1,ans.emplace_back(w);
            }
        }
        
        int ok=1;
        
        rep(i,1,n) {
            if(!vis[i]) {
                vector<int>c; c.push_back(i);
		    	int cnt=0;
		    	vis[i]=1;
		    	while(to[c.back()]!=i)c.push_back(to[c.back()]),vis[c.back()]=1;
		    	vector<int>v[2];
		    	for(int x:c)
		    	{
    				if(st[x]) cnt+=1;
    				v[cnt&1].push_back(x);
		    	}
    			if(cnt&1)ok=0;
    			if(v[0].size()>v[1].size()) v[0].swap(v[1]);
    			for(int x:v[0])ans.push_back(x);
            }
        }
        
        if(!ok) cout << -1 << "\n";
        else {
            cout << ans.size() << "\n";
            for(auto i:ans) cout << i << " ";
            if(ans.size()) cout << "\n";
        }
    }
}