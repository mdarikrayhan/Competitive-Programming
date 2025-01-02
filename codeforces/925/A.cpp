#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define ld long double
using namespace std;
const int M = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,m,cs,ce,v;cin >> n >> m >> cs >> ce >> v;
    vector<ll>st,ev;
    while(cs--){ll tmp;cin>>tmp;st.push_back(tmp);}sort(st.begin(),st.end());
    while(ce--){ll tmp;cin>>tmp;ev.push_back(tmp);}sort(ev.begin(),ev.end());
    ll q;cin >> q;while(q--){
        ll y1,x1,y2,x2,r=1e18;cin >> y1 >> x1 >> y2 >> x2;
        if(y1==y2){cout << abs(x1-x2) << "\n";continue;}
        ll costst=abs(y2-y1),costev=abs(y1-y2)/v;if((y1-y2)%v)costev++;
        if(st.size()){
            ll mid=lower_bound(st.begin(),st.end(),(ll)min(x1,x2))-st.begin(),lt,rt;
            if(mid==st.size()){mid--;rt=mid;if(mid==0)lt=mid;else lt=mid-1;}
            else if(mid==0){lt=0;if(mid==st.size()-1)rt=mid;else rt=mid+1;}
            else{lt=mid-1;if(mid==st.size()-1)rt=mid;else rt=mid+1;}
            ll mins=min({abs(x1-st[lt])+abs(x2-st[lt]),abs(x1-st[mid])+abs(x2-st[mid]),abs(x1-st[rt])+abs(x2-st[rt])});
            r=mins+costst;
        }if(ev.size()){
            ll mid=lower_bound(ev.begin(),ev.end(),(ll)min(x1,x2))-ev.begin(),lt,rt;
            if(mid==ev.size()){mid--;rt=mid;if(mid==0)lt=mid;else lt=mid-1;}
            else if(mid==0){lt=0;if(mid==ev.size()-1)rt=mid;else rt=mid+1;}
            else{lt=mid-1;if(mid==ev.size()-1)rt=mid;else rt=mid+1;}
            ll mins=min({abs(x1-ev[lt])+abs(x2-ev[lt]),abs(x1-ev[mid])+abs(x2-ev[mid]),abs(x1-ev[rt])+abs(x2-ev[rt])});
            r=min(r,mins+costev);
        }cout << r << "\n";
    }
}