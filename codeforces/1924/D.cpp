// LUOGU_RID: 160470590
#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
const int N=100005;
long long fac[N],rfac[N];
int n,m,k;
long long C(int n,int m)
{
    if(n<m||n<0||m<0)return 0;
    return fac[n]*rfac[m]%mo*rfac[n-m]%mo;
}
int calc(int k)
{
	return C(n+m,k); 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fac[1]=rfac[1]=fac[0]=rfac[0]=1;
    
    for(int i=2;i<=100000;i++)
    {
        fac[i]=fac[i-1]*i%mo;
        rfac[i]=rfac[mo%i]*(mo-mo/i)%mo;
    }
    for(int i=2;i<=100000;i++)
    {
        rfac[i]=rfac[i-1]*rfac[i]%mo;
    }

    int _;
    cin>>_;
    while(_--)
    {
        cin>>n>>m>>k;
        if(k>min(n,m))
        {
            cout<<0<<'\n';
            
        }
        else cout<<((calc(k)-calc(k-1)%mo)+mo)%mo<<'\n';
    }
}