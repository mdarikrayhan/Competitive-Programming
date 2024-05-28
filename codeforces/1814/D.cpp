// LUOGU_RID: 160583666
#include<bits/stdc++.h>
#define int long long 
#define pii pair <int ,int > 
#define mkp make_pair
using namespace std;
const int N=3e3;
int T;
int n,k,tot,val[N+5];
struct gun{
	int x,y,val;
}a[N+5];
bool cmp(gun x,gun y) { return x.val<y.val; }
int calc(int id){
    vector <int > cnt(n+5);
    vector <pii > v;
    int now=0,maxi=0;
    for(int i=1;i<=n;i++){
        if(i==id) v.emplace_back(mkp(a[i].val,i));
        else {
            if(a[i].val<=a[id].val){
                int tim=(a[id].val-a[i].val)/a[i].x;
                if(a[i].y>1) v.emplace_back(mkp(a[i].val+(tim-1)*a[i].x,i));
                v.emplace_back(mkp(a[i].val+tim*a[i].x,i));
                v.emplace_back(mkp(a[i].val+(tim+1)*a[i].x,i));
            }
            else {
                int tim=(a[i].val-a[id].val)/a[i].x;
                if(a[i].y>tim) v.emplace_back(mkp(a[i].val-tim*a[i].x,i));
                if(a[i].y>tim+1) v.emplace_back(mkp(a[i].val-(tim+1)*a[i].x,i));
            }
            v.emplace_back(mkp(a[i].val,i));
        }
    }
    sort(v.begin(),v.end());
    for(int l=0,r=0;l<v.size();l++){
        while(r<v.size()&&v[l].first+k>=v[r].first){
            if(!cnt[v[r].second]) now++;cnt[v[r].second]++;
            r++;
        }
        if(now==n){
            int place=lower_bound(val+1,val+1+n,v[l].first)-val;
            int place2=upper_bound(val+1,val+1+n,v[r-1].first)-val-1;
            maxi=max(maxi,place2-place+1);
        }
        cnt[v[l].second]--;
        if(!cnt[v[l].second]) now--;
    }
    return maxi;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i].x;
    for(int i=1;i<=n;i++) cin>>a[i].y,a[i].val=a[i].x*a[i].y,val[i]=a[i].val;//cout<<val[i]<<" ";cout<<'\n';
    sort(val+1,val+1+n);
    int ans=n;
    for(int i=1;i<=n;i++) ans=min(ans,n-calc(i));
    cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}