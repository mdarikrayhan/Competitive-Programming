#include<bits/stdc++.h>
using namespace std;
#define Adham cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long int
#define ld long double
#define T int t;cin>>t;while(t--)
#define fup(i, n) for(int i=0;i<n;i++)
#define fdn(i, n) for(int i=n-1;i>=0;i--)
#define pal(i, j, n) for(int i=0,j=n-1;i<j;i++,j--)
#define endl "\n"
int main() {
    Adham
    int n,m,x,c=1;
    cin>>n>>m;
    int fre[n]={};
    set<pair<int,int>>s;
    fup(i,n)s.emplace(0,i);
    fup(i,m){
        cin>>x;
        s.erase(make_pair(fre[x-1]++,x-1));
        s.emplace(fre[x-1],x-1);
        if((*s.begin()).first==c)cout<<1,c++;
        else cout<<0;
    }
}
