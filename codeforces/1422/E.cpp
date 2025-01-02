#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
struct node{
    string pre;
    string seg;
    int len=0;
    char a,b;
};
node add_char(char x,node b){
    node ans=b;
    ans.pre=x+ans.pre;
    if(ans.pre.size()>10)    ans.pre.pop_back();
    if(ans.seg.size()<10)    ans.seg=x+ans.seg;
    ans.len++;
    if(ans.a=='?')  ans.a=x;
    else if(ans.a!=x){ans.b=ans.a;ans.a=x;}
    return ans;
}
bool operator < (node a,node b){
    if(a.pre!=b.pre)    return a.pre<b.pre;
    if(b.b=='?')    return false;
    if(b.b>b.a) return true;
    else return false;    
}
void print(node a){
    int sz=a.len;
    if(sz>10){
        cout<<sz<<' ';
        for(int i=0;i<5;i++)   cout<<a.pre[i];
        int len=a.seg.size();
        cout<<"..."<<a.seg[len-2]<<a.seg[len-1]<<'\n';
    }
    else{
        string s;
        s.resize(sz);
        for(int i=0;i<a.pre.size();i++) s[i]=a.pre[i];
        int sq=a.seg.size();
        for(int i=0;i<a.seg.size();i++) s[sz-sq+i]=a.seg[i];
        cout<<sz<<' '<<s<<'\n';
    }
}
void solve() {
    string s;
    cin>>s;
    int sz=s.size();
    vector<node> dp(sz+1);
    dp[sz-1].pre=dp[sz-1].seg=s[sz-1];
    dp[sz-1].len=1;dp[sz-1].a=s[sz-1];
    dp[sz-1].b='?';
    dp[sz].a=dp[sz].b='?';
    for(int i=sz-2;i>=0;i--){
        if(s[i]!=s[i+1])    dp[i]=add_char(s[i],dp[i+1]);
        else{
            node c=add_char(s[i],add_char(s[i],dp[i+2]));
            if(c<dp[i+2])   dp[i]=c;
            else dp[i]=dp[i+2];
        }
    }
    for(int i=0;i<sz;i++){
        print(dp[i]);
    }
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
   // cin >> _;
    while(_--) solve();
    return 0;
}