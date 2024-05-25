#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--) 
#define fast_io ios_base::sync_with_stdio(0);
#define show(x) cout<<x<<endl;
#define pret(x) cout<<x<<endl; return 0;
#define disp(x) cout<<x<<" ";
#define let(x,y) cout<<x<<" "<<y<<endl;
ll MOD=1e9+7;
ll MAX=1e17;

int main(){
    fast_io;
    int n;
    cin>>n;
    int h[n];
    int s[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>h[i];
        s[i]=h[i];
    }
    sort(s,s+n);
    map<int,int>mymap;
    for (int i = 0; i < n; ++i)
    {
        if(mymap[s[i]]==0){
            mymap[s[i]] = i+1;
        }
    }    
    int id[n];
    for (int i = 0; i < n; ++i)
    {
        id[i] = mymap[h[i]];
        mymap[h[i]]++;
    }
    int curr=1;
    int tot=0,ans=0;
    for (int i = 0; i < n; ++i)
    {
        tot++;
        if(id[i]>curr){
            curr = id[i];
        }
        if(tot==curr) {
            ans++;
            curr++;
        }
    }
    show(ans);
    return 0;
}