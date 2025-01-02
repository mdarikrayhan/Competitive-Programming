// 大きな夢を持ち、ポジティブであり続けましょう
#include <bits/stdc++.h>
using namespace std;
#define int long long

string binary(int n)
{
    string s = "";
    while(n>=1){
        string s1;
        if(n%2) s1="1";
        else s1="0";
        s1+=s; s=s1;
        n/=2;
    }
    return s;
}

void solve()
{
    int n; cin>>n;
    int a[n][31], cnt[n][31];
    for(int i=0;i<n;i++) for(int j=0; j<31; j++) a[i][j]=0,cnt[i][j]=0;
    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        string bin = binary(x); int s=bin.size();
        for(int j=0; j<s; j++) if(bin[j]=='1') a[i][31+j-s]=1;
    }
    for(int i=0; i<31; i++)
    {
        int c=0;
        for(int j=0; j<n; j++){
            if(a[j][i]==1) c++;
            cnt[j][i]=c;
        }
    }
    //Let's answer queries
    int q; cin>>q;
    while(q--)
    {
        int ans = -1;
        int l,k; cin>>l>>k; l--;
        int lo = l, hi = n-1; bool b=0;
        while(!(lo>hi))
        {
            int m = lo+(hi-lo)/2;
            int num = 0;
            for(int i=0; i<31; i++)
            {
                int f = cnt[m][i]-cnt[l][i];
                num += (f==m-l&&a[l][i]!=0?(1<<(30-i)):0);
            }
            if(num>=k) lo=m+1,ans=max(ans,m);
            else hi=m-1;
        }
        cout<<(ans==-1?ans:ans+1)<<' ';
    }
    cout<<'\n';
}

signed main(){
    int tc=1; cin>>tc; while(tc--) solve();
    return 0;
}