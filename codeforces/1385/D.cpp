#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll work(int l,int r,char ch)
{
    if(l==r)
        return str[l]!=ch;
    int mid=(l+r)>>1,ans1=0,ans2=0;
    for(int i=l;i<=mid;i++)
    {
        if(str[i]!=ch)
            ans1++;
    }
    for(int i=mid+1;i<=r;i++)
    {
        if(str[i]!=ch)
            ans2++;
    }
    return min(work(l,mid,ch+1)+ans2,work(mid+1,r,ch+1)+ans1);
}
void solve() {
    ll n;
    cin>>n;
    cin>>str;
    cout<<work(0,n-1,'a')<<endl;
}
int main() {
    ll t;
    cin>>t;
    //t=1;
    while(t--){
       solve();
    }
    return 0;
}