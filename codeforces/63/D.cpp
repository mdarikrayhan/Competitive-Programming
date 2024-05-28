#include <bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define int long long
#define float long double
int cs;
void solve()
{
    int a,b,c,d,n,sm=0,i,k=0;
    cin >> a >> b >> c >> d >> n;
    char ans[max(b,d)+1][a+c+1];
    memset(ans,'.',sizeof(ans));
    int aa[n];
    for(int i=0;i<n;i++) cin >> aa[i],sm+=aa[i];
    if(sm!=a*b+c*d)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    bool flag, mark;
    if((d>b && b%2)||(b>=d && d%2==0)) mark=0;
    else mark=1;
    for(int j=1;j<=max(b,d);j++)
    {
        if((!mark && j%2) || (mark && j%2==0)) flag=i=1;
        else i=a+c,flag=0;
        int lo=1, hi=a+c;
        if(j>b) lo=a+1, i=max(i,lo);
        else if(j>d) hi=a,i=min(hi,i);
        for(;i>=lo && i<=hi;i+=flag - (flag==0))
        {
            while(aa[k]==0) k++;
            ans[j][i]=k+'a';
            aa[k]--;
        }
    }
    for(int i=1;i<=max(b,d);i++)
    {
        for(int j=1;j<=a+c;j++) cout << ans[i][j];
        cout << endl;
    }
}
signed main()
{
    fast
    int t=1;
    // cin >> t;
    for(cs=1;cs<=t;cs++)
    {
        //cout << "Case " << cs << ": "; 
        solve();
    }
    return 0;
}