#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(), a.rend()
#define forn(u,n) for(int u=0;u<n;++u)
#define forns(u,i,n) for(int u=i;u<n;++u)
#define todo0(a) a,0,sizeof a
#define todom1(a) a,-1,sizeof a
#define reverso long long, vector<pair<long long,int>>, greater<pair<long long,int>>
#define mod 998244353
#define N 100005
#define pb push_back
#define snd second
#define fst first
 
using namespace std;
 
typedef long long ll;
int n,t;
string s, ns;
vector <int> manacher(string str){ /// hash = 784265
    int i, j, k, l = str.size(), n = l << 1;
    vector <int> pal(n);
 
    for (i = 0, j = 0, k = 0; i < n; j = max(0, j - k), i += k){
        while (j <= i && (i + j + 1) < n && str[(i - j) >> 1] == str[(i + j + 1) >> 1]) j++;
        for (k = 1, pal[i] = j; k <= i && k <= pal[i] && (pal[i] - k) != pal[i - k]; k++){
            pal[i + k] = min(pal[i - k], pal[i] - k);
        }
    }
 
    pal.pop_back();
    return pal;
}
int main(){
    #ifdef LOCAL
    freopen("entra.in","r",stdin);
    #endif
    ios_base::sync_with_stdio();
    cin.tie();
    cin>>t;
    while(t--){
        cin>>s;
        int ini=0,fin=(int)s.size()-1;
        string rev="",ans;
 
        for(int i=0;i<=fin;i++){
            ini=i;
            if(fin==i){
                break;
            }
            if(s[fin]==s[i]){
                rev+=s[i];
                fin--;
                ini=i+1;
            }
            else break;
 
        }
 
        ans=rev;
        reverse(all(rev));
        string mid="";
        ns="";
        for(int i=ini;i<=fin;i++)ns+=s[i];
        if(ns.size()){
            vector<int>palind=manacher(ns);
            int lef=0,rig=0;
            for(int i=0;i<palind.size();i++){
                if(i-palind[i]<0)lef=palind[i];
            }
            for(int i=palind.size()-1;i>=0;i--){
                if(i+palind[i]>=palind.size())rig=palind[i];
            }
            if(lef>rig){
                for(int i=0;i<lef;i++)mid+=ns[i];
            }
            else{
                for(int i=ns.size()-rig;i<ns.size();i++)mid+=ns[i];
            }
        }
        ans+=mid,ans+=rev;
        cout<<ans<<"\n";
    }
}