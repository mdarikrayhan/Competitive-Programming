#include<bits/stdc++.h>
#define int long long
#define pb(x) push_back(x)
#define in(x) insert(x)
#define mid (l+r)/2
#define F first
#define S second
#define endl '\n'
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
const int M=1e9+7;
const int N=1010;
using namespace std;
int pre[N],sp[N][12];
void build(int n)
{
    for(int i=1;i<=n;i++)
        sp[i][0] = pre[i];
    for(int j=1;j<=11;j++)
    {
        for(int i=1;i+(1<<(j-1))<=n;i++)
            sp[i][j] = min(sp[i][j-1] , sp[i+(1<<(j-1))][j-1]);
    }
}
int query(int l,int r)
{
    int j = 63 - __builtin_clzll(r-l+1);
    return min(sp[l][j] , sp[r-(1<<j)+1][j]);
}
int32_t main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
cin>>n;
string s;
cin>>s;
int ans=0,l=1,r=1;
s='!'+s;
int cnt = 0;
for(int i=1;i<=n;i++)
{
    if(s[i] == '(')
        cnt++;
    else
        cnt--;
}
if(cnt != 0)
{
    cout<<0<<endl;
    cout<<1<<' '<<1<<endl;
    return 0;
}
for(int i=1;i<=n;i++)
{
    for(int j=i;j<=n;j++)
    {
        if(s[i] == s[j] && i != j)
            continue;
        swap(s[i],s[j]);
        pre[0] = 0;
        int cur = 0;
        for(int z=1;z<=n;z++)
        {
            pre[z] = (s[z] == '(' ? 1 : -1);
            pre[z+n] = pre[z];
        }
        for(int z=1;z<=n*2;z++)
            pre[z] += pre[z-1];
        build(n*2);
        for(int z=1;z<=n;z++)
        {
            int mn = query(z,z+n-1);
            if(mn - pre[z-1] >= 0 && pre[z+n-1] - pre[z-1] == 0){
                cur++;
            }
        }
        if(cur>ans)
        {
            ans = cur;
            l = i;
            r = j;
        }
        swap(s[i],s[j]);
    }
}
cout<<ans<<endl;
cout<<l<<' '<<r<<endl;
}
