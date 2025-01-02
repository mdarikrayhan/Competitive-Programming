#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define input int t;cin>>t; while(t--)
void solve()
{
    string a,b;cin>>a>>b;
    int n=a.length();
    for(int i=0;i<n-1;i++)
    {
        if((a[i]=='0'&&b[i]=='0')&&(a[i+1]=='1'&&b[i+1]=='1'))
        {cout<<"YES"<<endl;return;}
    }
    cout<<"NO"<<endl;
}
int main(){
fastio();
input
{
solve();
}
 
}