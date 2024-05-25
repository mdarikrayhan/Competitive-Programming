#include<bits/stdc++.h>
#define ll long long
#define vint vector<int>
#define df double
#define pb push_back
#define fs first
#define sc second
#define pii pair<int,int>
#define vll vector<long long>
#define fr(k,i,n) for(int i=k;i<n;i++)
#define f0(i,n) for(int i=0;i<n;i++)
#define M 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b;
    set<int>x,y;
    set<pii>pt;
    f0(i,8){
        cin>>a>>b;
        x.insert(a);y.insert(b);
        pt.insert({a,b});
    }
    if(x.size()!=3||y.size()!=3||pt.size()!=8){cout<<"ugly";return 0;}
    vint r,c;
    for(auto i:x){r.pb(i);}
    for(auto i:y){c.pb(i);}
    cout<<(pt.find({r[1],c[1]})==pt.end()?"respectable":"ugly");
    return 0;
}