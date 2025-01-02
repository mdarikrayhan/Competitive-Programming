#include<bits/stdc++.h>
#define t int t;cin>>t;while (t--)
#define ll long long
#define all(x) begin(x),end(x)
#define endl "\n"
using namespace std;
ostream &operator<<(ostream &os,vector<auto>&v){for(auto &c:v)os<<c<<" ";return os;}
istream &operator>>(istream &is,vector<auto>&v){for(auto i=0;i<v.size();i++)is>>v[i];return is;}
void solve(){
    ll n,w;
    cin>>n>>w;
    vector<ll>v(n);
    vector<pair<ll,ll>>v_pair(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        v_pair[i].first=v[i];
        v_pair[i].second=i+1;
    }
    sort(all(v));
    sort(all(v_pair));
    ll temp = ceil((double)w/2);
    auto c=lower_bound(all(v),temp);
    if(c!=v.end()&&v[c-v.begin()]<=w){
        cout<<1<<endl;
        cout<<v_pair[c-v.begin()].second<<endl;
    }
    else {
        ll new_temp=(c-v.begin());
        vector<ll>vnew;
        ll temp_sum=0;
        for(int i=0;i<new_temp;i++ ){
            temp_sum+=v[i];
            if(temp_sum>w)break;
            vnew.push_back(v_pair[i].second);
        }
        if(temp_sum<temp)cout<<-1<<endl;
        else {
            cout<<vnew.size()<<endl;
            for(auto c:vnew)cout<<c<<" ";
        }
    }


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    t
    {
     solve();
    }
 return 0;
}