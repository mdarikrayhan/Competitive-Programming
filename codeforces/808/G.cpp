#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define int long long
#define ld long double
#define endl "\n"
#define FOCUS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void Go() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
string s,pat;
vector<ll>pi;
vector<vector<ll>>dp1;
int dp2[(ll)2e5+1][30];
int longest_pref(int l, char c)
{
    while (l>0&&c!=pat[l])
    {
        l=pi[l-1];
    }
    l+=(c==pat[l]);
    return l;
}
void fail()
{
    ll n=(ll)pat.size();
    for(int i=1;i<n;i++)
    {
        pi[i]= longest_pref(pi[i-1],pat[i]);
    }
}
ll solve(ll idx,ll l)
{
    if(idx==s.size())return 0;
    ll &ret=dp1[idx][l];
    if(ret!=-1)return ret;
    ret=0;
    if(s[idx]!='?')
    {
        char i=s[idx];
        if(dp2[l][i-'a']==-1)dp2[l][i-'a']= longest_pref(l,i);
        return ret=max(ret, solve(idx+1,dp2[l][i-'a'])+(dp2[l][i-'a']==pat.size()-1));
    }
    for(char i='a';i<='z';i++)
    {
        if(dp2[l][i-'a']==-1)dp2[l][i-'a']= longest_pref(l,i);
        ret=max(ret, solve(idx+1,dp2[l][i-'a'])+(dp2[l][i-'a']==pat.size()-1));
    }
    return ret;
}
signed main() {
    Go();
    cin>>s>>pat;
    pi.resize(pat.size());
    fail();
    pat+='A';
    memset(dp2,-1,sizeof(dp2));
    dp1.resize(s.size()+1,vector<ll>(pat.size()+1,-1));
    cout<<solve(0,0)<<endl;
    return 0;
}