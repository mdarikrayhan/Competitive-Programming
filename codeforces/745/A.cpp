#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define gcd __gcd
#define yes cout<<"YES";
#define no cout<<"NO";
#define fi first
#define se second
using namespace std;
string func(string s)
{
    string t="";
    t=s;
    t[0]=s[s.size()-1];
     for(int i=0; i<s.size()-1; i++)t[i+1]=s[i];
    //    t+=s[s.size()-1];
    return t;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll salmon=1;
    //cin>>salmon;
    //p=salmon%2;+
    while(salmon--)
    {
        string s,t;
        cin>>s;
        t=s;
          ////////////////////////////////  cout<<s<<endl;
        ll ans=1;
        t[0]=s[s.size()-1];
        for(int i=0; i<s.size()-1; i++)t[i+1]=s[i];
        while(t!=s)
        {
            ans++;
            t=func(t);
        }
        cout<<ans;
    }
}
