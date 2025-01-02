#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
    string s;cin>>s;
    map<pair<int, int>, int>m;
    m[make_pair(0,0)]=0;
    int ax=0, ay=0;
    for(int i=0;i<s.size();i++){
        int bx=ax, by=ay;
        if(s[i]=='L')ay++;
        else if(s[i]=='R')ay--;
        else if(s[i]=='D')ax++;
        else ax--;
        if(m.count(make_pair(ax, ay))){cout<<"BUG"<<endl;return;}
        m[make_pair(ax, ay)]=m[make_pair(bx, by)]+1;
        for(int j=0;j<4;j++){
            int cx=ax+dx[j], cy=ay+dy[j];
            if(m.count(make_pair(cx, cy))&&m[make_pair(cx, cy)]+1<m[make_pair(ax, ay)]){cout<<"BUG"<<endl;return;}
        }
    }
    cout<<"OK"<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;t=1;//cin>>t;
    while(t--) solve();
    return 0;
}
