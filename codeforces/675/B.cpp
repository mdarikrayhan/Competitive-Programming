#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{

   // freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll n,a,b,c,d;  cin>>n>>a>>b>>c>>d;
    vector<ll>v{a+b,a+c,d+c,d+b};
    sort(v.begin(),v.end());
    ll sum=2+v[3];
    ll mi=sum-(1+v[0]);
    cout<<n*max((n-mi+1LL),0LL);
    return 0;
}
