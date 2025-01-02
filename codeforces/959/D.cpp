/***
*   سبحان الله والحمد لله ولا إله إلا الله والله أكبر
*         لا حول ولا قوة إلا بالله,
***/


#include "bits/stdc++.h"

using namespace std;

using ll = long long;



#ifdef BuGs
#include "Debug.h"
#else
#define debug(...) 1.618033
#endif




/// 20% ==> 80%
///-------------------------------------------------------------------------------+
const int N=2e6+100;
int pf[N];

void seive(int N=2e6+5)
{
    pf[1]=pf[0]=1;
    for(int i=2; i<=N; i++)
    {
        if(pf[i]==0)
        {

            for(int j=i; j<=N; j+=i)
            {
                if(pf[j])continue;
                pf[j]=i;
            }
        }
    }

}
vector<int> ret;
void  f(int x)
{
    while(pf[x]>1)
    {
        ret.push_back(pf[x]);
        x=x/pf[x];
    }
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    seive();
    int n;
    cin>>n;
    vector<int>a(n);
    set<int> st;
    for(int&I:a)cin>>I;
    if(n==1)
    {
        cout<<a[0]<<"\n";
        return 0 ;
    }
    for(int i=2; i<N; i++)
    {
        st.insert(i);
    }
    bool ok=true;
    for(int i=0; i<n; i++)
    {
        int v;
        if(ok)
        {
            v=*st.lower_bound(a[i]);
            if(v>a[i])ok=false;
        }
        else
        {
            v=*st.begin();
        }
        f(v);
        for(int x:ret)
        {
            for(int j=x; j<N; j+=x)
            {
                if(st.count(j))st.erase(j);
            }
        }
        ret.clear();
        cout<<v<<" ";

    }




}
