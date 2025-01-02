#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define int long long
int n;
signed main()
{
    cin>>n;
    string s;
    stack<int>st;
    long long ans=0;
    bool ovf=0;
    int MX=(1ll<<32)-1;
    st.push(1);
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s[0]=='a')
        {
            ans+=st.top();
            if(st.top()==-1)
                ovf=1;
            if(ans>MX)
                ovf=1;
        }
        else if(s[0]=='f')
        {
            int xx;
            cin>>xx;
            int nw=xx*st.top();
            if(nw>MX||st.top()==-1)
                st.push(-1);
            else
                st.push(nw);
        }
        else
        {
            st.pop();
        }
    }
    if(ovf)
        puts("OVERFLOW!!!");
    else
        cout<<ans<<"\n";
}
