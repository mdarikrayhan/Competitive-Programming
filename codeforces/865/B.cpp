#include <bits/stdc++.h>
 
using namespace std;

bool cmp(tuple<int64_t, int64_t, int64_t> a, tuple<int64_t, int64_t, int64_t> b){
    int64_t af=get<1>(a), as=get<2>(a), bf=get<1>(b), bs=get<2>(b);
    return as - af < bs - bf;
}

void solve(){
    int64_t n, k, la=0, lb=0, su=0, lc;
    cin>>n>>k;
    vector<tuple<int64_t, int64_t, int64_t>> p(n);
    for(int64_t i=0; i<n; ++i){
        int64_t s, l, r;
        cin>>s>>l>>r;
        p[i]={s, l, r};
        if(l>r){
            la+=s;
        }
        su+=s;
    }
    if(su%k!=0){
        p.push_back({k-(su%k), 0, 0});
    }
    sort(p.begin(), p.end(), cmp);
    la/=k;
    la*=k;
    lb=la+k;
    lc=la-k;
    int64_t t1=0, t2=0, t3=0;
    for(int i=0; i<p.size(); ++i){
        int64_t s=get<0>(p[i]), l=get<1>(p[i]), r=get<2>(p[i]);
        if(la>0){
            if(la>=s){
                t1+=s*l;
                la-=s;
            }
            else{
                t1+=l*la;
                t1+=abs(s-la)*r;
                la=0;
            }
        }
        else{
            t1+=s*r;
        }
        if(lb>0){
            if(lb>=s){
                t2+=s*l;
                lb-=s;
            }
            else{
                t2+=l*lb;
                t2+=abs(s-lb)*r;
                lb=0;
            }
        }
        else{
            t2+=s*r;
        }
        if(lc>0){
            if(lc>=s){
                t3+=s*l;
                lc-=s;
            }
            else{
                t3+=l*lc;
                t3+=abs(s-lc)*r;
                lc=0;
            }
        }
        else{
            t3+=s*r;
        }
    }
    cout<<max(t1, max(t2, t3));
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
    return 0;
}