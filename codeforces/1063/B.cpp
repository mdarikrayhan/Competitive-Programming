#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define nl "\n"
using namespace std;
const ll INF = 1e18+10;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ///freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    ll t=1,tc=1,n,m,k,a1,b1,c1,x,y,z,u,v,w,p,q,start,finish,l,r,cnt=0,ans=0,cnt1=0,cnt2=0,temp=0;string s,s1,s2;
    ///cin>>t;
    while(t--)
    {
        cin>>n>>m>>start>>finish>>l>>r;
        start--, finish--;
        string s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        ///vector<ll>dis(n,INF);
        int dirx[]={0,0,1,-1};
        int diry[]={1,-1,0,0};

        vector<vector<bool>>processed(n,vector<bool>(m));
        priority_queue<tuple<ll,ll,pair<ll,ll>>>pq;   /// < weight , cell >
        tuple<ll,ll,pair<ll,ll>>tpl1(l+r,l,{start,finish});

        pq.push(tpl1);
        while(!pq.empty()){

            cnt=get<0>(pq.top());
            cnt1=get<1>(pq.top());
            x=get<2>(pq.top()).first;
            y=get<2>(pq.top()).second;
            pq.pop();

            if(processed[x][y]) continue;
            processed[x][y]=1;
            ///cout<<cnt<<" "<<cnt1<<", "<<x+1<<" "<<y+1<<"\n";

            for(int i=0;i<4;i++){
                ll nextx = x+dirx[i];
                ll nexty = y+diry[i];
                ll nextCnt=cnt;
                ll nextCnt1=cnt1;
                if(diry[i]){  ///left or right
                    nextCnt--;
                    if(diry[i]==-1) nextCnt1--;
                }
                if(nextx<0 or nextx>=n or nexty<0 or nexty>=m or s[nextx][nexty]=='*' or nextCnt1<0 or (nextCnt-nextCnt1)<0) continue;

                tuple<ll,ll,pair<ll,ll>>tpl(nextCnt,nextCnt1,{nextx,nexty});
                pq.push(tpl);
            }
        }
        cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(processed[i][j]) cnt++;
            }
        }
       cout<<cnt<<"\n";
    }
}
