
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define append push_back
#define pii pair<int,int>
#define ld long double

void quick_read(){ios::sync_with_stdio(false); cin.tie(0);}

int multi_test=1;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> vi(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        vi[b]++;
    }
    int dex=-1;
    for(int i=1;i<=n;i++)
    {
        if(vi[i]==0)
        {
            dex=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=dex)
        {
            cout<<dex<<" "<<i<<endl;
        }
    }
}

signed main()
{
	int T=1;
	if(multi_test)cin>>T;
	while(T--)solve();



    return 0;
}