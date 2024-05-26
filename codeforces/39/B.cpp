#include<bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define fl(i,a,b) for(int i=b-1;i>=a;i--)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,false,sizeof(x))
#define tr(it,a) for(auto it = a.begin(); it!=a.end(); it++)
#define tl(it,a) for(auto it = a.rbegin(); it!=a.rend(); it++)
#define go(a,x) for(auto &a:x)
#define ter(a,b,c) ((a)?(b):(c))
#define yn(a) cout<<((a)?"YES\n":"NO\n")

using ll = long long;
using vi = vector<int>;
using vii = vector<pair<int,int>>;
using pi = pair<int,int>;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
ios::sync_with_stdio(0);
cin.tie(0);
    int n; cin>>n;
    int d = 1;
    vi ans;  
    fr(i,0,n)
    {
        int x; cin>>x;
        if(x == d)
        {
            ans.push_back(2000 + i + 1); 
            ++d; 
        }
    }
    cout<<ans.size()<<"\n";
    go(x,ans) cout<<x<<" "; 
}