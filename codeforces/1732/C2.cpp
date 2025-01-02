#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main(){
    IOS
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        vector<int> v[30];
        for(int i=0;i<30;++i){
            for(int j=0;j<n;++j){
                if((1<<i)&a[j]){
                    v[i].push_back(j+1);
                }
            }
        }
        while(q--){
            int L,R;
            cin>>L>>R;
            int l=n,r=1;
            vector<pair<int,int>> tp;
            for(int i=0;i<30;++i){
                auto x=lower_bound(v[i].begin(),v[i].end(),L)-v[i].begin();
                if(x==v[i].size() || v[i][x]>R){
                    continue;
                }
                auto y=upper_bound(v[i].begin(),v[i].end(),R)-v[i].begin()-1;
                if(x==y){
                    continue;
                }
                if((y-x)&1){
                    l=min(l,v[i][x]);
                    r=max(r,v[i][y]);
                }else{
                    l=min(l,v[i][x+1]);
                    r=max(r,v[i][y-1]);
                    tp.push_back({v[i][x],v[i][y]});
                }
            }
            if(l==n && r==1){
                cout<<L<<' '<<L<<'\n';
                continue;
            }
            tp.push_back({l,r});
            int len=n;
            int l1=l,r1=r;
            for(int i=0;i<tp.size();++i){
                if(tp[i].first>l) continue;
                int lt=tp[i].first,rt=r;
                for(auto &it:tp){
                    if(it.first<lt){
                        rt=max(rt,it.second);
                    }
                }
                if(len>rt-lt){
                    len=rt-lt;
                    l1=lt,r1=rt;
                }
            }
            cout<<l1<<' '<<r1<<'\n';
        }
    }
    return 0;
}

