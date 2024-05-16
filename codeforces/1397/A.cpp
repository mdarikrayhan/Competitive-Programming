#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,b;cin>>n;
    b=n;
    int a[26]={0};
    while(b--)
    {
        string s;cin>>s;
        for(int i=0;i<s.length();i++) a[s[i]-97]++;
    }
    for(int i=0;i<26;i++) if(a[i]%n!=0) {cout<<"NO"<<endl; return 0; }
    cout<<"YES"<<endl;
    return 0;
}
int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}