#include "bits/stdc++.h"
#define int long long
#define double long double
#define TxtIO  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
const int mod=1e9+7;
const int inf=1e18;
#define vi vector<int>
#define pii pair<int,int>
#define all(p) p.begin(),p.end()
#define fri(n) for(int i=0;i<n;i++)
#define fra(a) for(auto i:a)
#define fro(x,y) for(int i=x;i<y;i++)
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char> > v(n,vector<char>(m)),ans(n,vector<char>(m,'.'));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>v[i][j];
        for(int i=0;i<n;i++)
        {
            int c2=0;
            for(int j=0;j<m;j++)
            {
                if(v[i][j]!='.'&&ans[i][j]=='.')
                {
                    if (v[i][j]=='U')
                    {
                        if(c2%2==0)
                        {
                            ans[i][j]='W';
                            ans[i+1][j]='B';
                        }
                        else
                        {
                            ans[i+1][j]='W';
                            ans[i][j]='B';
                        }
                        c2++;
                    }
                }
            }
        }
        for(int j=0;j<m;j++)
        {
            int c1=0;
            for(int i=0;i<n;i++)
            {
                if(v[i][j]!='.'&&ans[i][j]=='.')
                {
                    if(v[i][j]=='L')
                    {
                        if(c1%2==0)
                        {
                            ans[i][j]='W';
                            ans[i][j+1]='B';
                        }
                        else
                        {
                            ans[i][j+1]='W';
                            ans[i][j]='B';
                        }
                        c1++;
                    }
                }
            }
        }
        int b=0;
        int c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j]=='W')c1++;
                else if(ans[i][j]=='B') c1--;
            }
            if(c1)b=1;
        }
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(ans[i][j]=='W')c2++;
                else if(ans[i][j]=='B')c2--;
            }
            if(c2)b=1;
        }
        if(b) cout<<-1<<endl;
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    cout<<ans[i][j];
                cout<<endl;
            }
        }
    }
    return 0;
}