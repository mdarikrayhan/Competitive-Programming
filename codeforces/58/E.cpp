#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define setmin(x,y) x=min((x),(y))
#define setmax(x,y) x=max((x),(y))
#define fi first
#define se second

// mt19937 hdp(chrono::high_resolution_clock::now().time_since_epoch().count());
// int rand(int l,int r){return l+((hdp()%(r-l+1))+r-l+1)%(r-l+1);}

const int N = 1e3+5;
const int K = 11;
const int NN = (1<<8);
// const int mod = 1e9+7;
const double eps = 1e-9;

string s[3];
vector<int> a[3];
int dp[10][10][10][8];
pair<pair<int,int>,pair<int,int>> par[10][10][10][8];

int DP(int p0,int p1,int p2,int rem);

void trans(int p0,int p1,int p2,int rem,int np0,int np1,int np2,int nrem,int d)
{
    if(dp[p0][p1][p2][rem]>DP(np0,np1,np2,nrem)+d)
    {
        dp[p0][p1][p2][rem]=DP(np0,np1,np2,nrem)+d;
        par[p0][p1][p2][rem]={{np0,np1},{np2,nrem}};
    }
}

int DP(int p0,int p1,int p2,int rem)
{
    // cout<<p0<<' '<<p1<<' '<<p2<<' '<<rem<<endl;
    if(p0==a[0].size()&&p1==a[1].size()&&p2==a[2].size()&&!(rem&1)) return 0;
    if(~dp[p0][p1][p2][rem]) return dp[p0][p1][p2][rem];
    dp[p0][p1][p2][rem]=1e9;
    if(p0!=a[0].size()&&p1!=a[1].size()&&p2!=a[2].size())
    {
        if(a[0][p0]+a[1][p1]+rem==a[2][p2]) trans(p0,p1,p2,rem,p0+1,p1+1,p2+1,0,0);
        if(a[0][p0]+a[1][p1]+rem==10+a[2][p2]) trans(p0,p1,p2,rem,p0+1,p1+1,p2+1,1,0);
        if(a[2][p2]-rem>=0) trans(p0,p1,p2,rem,p0,p1,p2+1,0,2);
        if(a[2][p2]-rem<9) trans(p0,p1,p2,rem,p0,p1,p2+1,1,2);
        if(a[0][p0]+rem<=a[2][p2]) trans(p0,p1,p2,rem,p0+1,p1,p2+1,0,1);
        else trans(p0,p1,p2,rem,p0+1,p1,p2+1,1,1);
        if(a[1][p1]+rem<=a[2][p2]) trans(p0,p1,p2,rem,p0,p1+1,p2+1,0,1);
        else trans(p0,p1,p2,rem,p0,p1+1,p2+1,1,1);
        if(a[0][p0]+a[1][p1]+rem<=9) trans(p0,p1,p2,rem,p0+1,p1+1,p2,0,1);
        else trans(p0,p1,p2,rem,p0+1,p1+1,p2,1,1);
    }
    else
    {
        int l=(rem&1),r=0;
        if(p0!=a[0].size()) l+=a[0][p0];
        if(p1!=a[1].size()) l+=a[1][p1];
        if(p2!=a[2].size()) r+=a[2][p2];
        if(p2!=a[2].size()) 
        {
            if((rem>>1)!=3) 
            {
                if(p0==a[0].size()&&!(rem>>2&1)) trans(p0,p1,p2,rem,p0,p1,p2+1,((rem>>1)<<1),1);
                if(p1==a[1].size()&&!(rem>>1&1)) trans(p0,p1,p2,rem,p0,p1,p2+1,((rem>>1)<<1),1);
            }
            if(a[2][p2]-(rem&1)<9&&!(rem>>1)) trans(p0,p1,p2,rem,p0,p1,p2+1,((rem>>1)<<1)|1,2);
            if(l==r) 
            {
                int nrem=0;
                if(p0==a[0].size()) nrem|=(1<<1);
                if(p1==a[1].size()) nrem|=(1<<2);
                trans(p0,p1,p2,rem,p0+(p0!=a[0].size()),p1+(p1!=a[1].size()),p2+(p2!=a[2].size()),nrem,0);
            }
            if(p0==a[0].size()&&!(rem>>1&1)) trans(p0,p1,p2,rem,p0+(p0!=a[0].size()),p1+(p1!=a[1].size()),p2+(p2!=a[2].size()),((rem>>1)<<1)|(l>r),1);
            if(p1==a[1].size()&&!(rem>>2&1)) trans(p0,p1,p2,rem,p0+(p0!=a[0].size()),p1+(p1!=a[1].size()),p2+(p2!=a[2].size()),((rem>>1)<<1)|(l>r),1);
        }
        else trans(p0,p1,p2,rem,p0+(p0!=a[0].size()),p1+(p1!=a[1].size()),p2+(p2!=a[2].size()),((rem>>1)<<1)|(l>9),1);
    }
    return dp[p0][p1][p2][rem];
}

int lmao(int x)
{
    if(x>9) return x-10;
    if(x<0) return x+10;
    return x;
}

signed main()   
{
    fastIO
    char c;
    cin>>c;
    while(c!='+')
    {
        a[0].push_back(c-'0');
        cin>>c;
    }
    cin>>c;
    while(c!='=')
    {
        a[1].push_back(c-'0');
        cin>>c;
    }
    while(cin>>c) a[2].push_back(c-'0');
    for(int i=0;i<3;i++) reverse(a[i].begin(),a[i].end());
    memset(dp,-1,sizeof dp);
    DP(0,0,0,0);
    int x=0,y=0,z=0,t=0;
    while(x!=a[0].size()||y!=a[1].size()||z!=a[2].size()||(t&1))
    {
        int nx=par[x][y][z][t].fi.fi,ny=par[x][y][z][t].fi.se,nz=par[x][y][z][t].se.fi,nt=par[x][y][z][t].se.se;
        if(x!=a[0].size()&&y!=a[1].size()&&z!=a[2].size())
        {
            if(nx==x+1&&ny==y+1&&nz==z+1)
            {
                s[0]+=(char)(a[0][x]+'0');
                s[1]+=(char)(a[1][y]+'0');
                s[2]+=(char)(a[2][z]+'0');
            }
            else if(nx!=x+1&&ny!=y+1)
            {
                s[2]+=(char)(a[2][z]+'0');
                if(nt==1)
                {
                    s[0]+='9';
                    s[1]+=(char)(lmao(a[2][z]-9-t)+'0');
                }
                else
                {
                    s[0]+='0';
                    s[1]+=char(a[2][z]-t+'0');
                }
            }
            else
            {
                if(nx!=x+1)
                {
                    s[0]+=(char)(lmao(a[2][z]-a[1][y]-t)+'0');
                    s[1]+=(char)(a[1][y]+'0');
                    s[2]+=(char)(a[2][z]+'0');
                }
                if(ny!=y+1)
                {
                    s[0]+=(char)(a[0][x]+'0');
                    s[1]+=(char)(lmao(a[2][z]-a[0][x]-t)+'0');
                    s[2]+=(char)(a[2][z]+'0');
                }
                if(nz!=z+1)
                {
                    s[0]+=(char)(a[0][x]+'0');
                    s[1]+=(char)(a[1][y]+'0');
                    s[2]+=(char)(lmao(a[0][x]+a[1][y]+t)+'0');
                }
            }
        }
        else
        {
            int l=(t&1),r=0;
            if(x!=a[0].size()) l+=a[0][x];
            if(y!=a[1].size()) l+=a[1][y];
            if(z!=a[2].size()) r+=a[2][z];
            if(z!=a[2].size())
            {
                s[2]+=(char)(a[2][z]+'0');
                if(nz==z+1&&!(ny==y+1||nx==x+1))
                {
                    if(!(nt&1))
                    {
                        if(y==a[1].size()&&!(t>>1&1)) s[0]+=(char)(a[2][z]+'0'-(t&1));
                        else s[1]+=(char)(a[2][z]+'0'-(t&1));
                    }
                    else
                    {
                        s[0]+='9';
                        s[1]+=(char)(lmao(a[2][z]-9-t)+'0');
                    }
                }
                else if(l==r)
                {
                    if(x!=a[0].size()) s[0]+=(char)(a[0][x]+'0');
                    else s[0]+='0';
                    if(y!=a[1].size()) s[1]+=(char)(a[1][y]+'0');
                    else s[1]+='0';
                }
                else
                {
                    if(x==a[0].size()&&!(t>>1&1))
                    {
                        s[0]+=(char)(lmao(r-l)+'0');
                        s[1]+=(char)(a[1][y]+'0');
                    }
                    else 
                    {
                        if(x!=a[0].size()) s[0]+=(char)(a[0][x]+'0');
                        s[1]+=(char)(lmao(r-l)+'0');
                    }
                }
            }
            else
            {
                if(x!=a[0].size()) s[0]+=(char)(a[0][x]+'0');
                if(y!=a[1].size()) s[1]+=(char)(a[1][y]+'0');
                s[2]+=(char)(lmao(l)+'0');
            }
        }
        x=nx; y=ny; z=nz; t=nt;
    }
    for(int i=0;i<=2;i++) 
    {
        bool b=0;
        for(int j=s[i].size()-1;j>=0;j--)
        {
            if(s[i][j]!='0') b=1;
            if(b) cout<<s[i][j];
        }
        if(i==0) cout<<'+';
        if(i==1) cout<<'=';
    }
}
			 		  	  	 	    				  			 			