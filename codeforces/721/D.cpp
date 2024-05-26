#include<bits/stdc++.h>
#define Faster ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;




ll a[200200];
pair<ll,ll>p;
bool g=1;
set<pair<ll,ll>>s;
int main()
{
    Faster

    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,k,x;
        cin>>n>>k>>x;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<0)
                g^=1;
            p.first=abs(a[i]);
            p.second=i;
            s.insert(p);
        }
        while(k--)
        {
            p=*(s.begin());
            s.erase(p);
            int i=p.second;
            if(g)
            {
                if(a[i]>=0)
                {
                    a[i]-=x;
                    if(a[i]<0)
                    g^=1;
                }
                else
                {
                    a[i]+=x;
                    if(a[i]>=0)
                        g^=1;
                }
            }
            else
            {
                if(a[i]>=0)
                    a[i]+=x;
                else
                    a[i]-=x;

            }
                p.first=abs(a[i]);
            s.insert(p);
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
    }
}
/*

*/
