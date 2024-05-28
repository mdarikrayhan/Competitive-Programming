#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define P pair<int,int>
#define m_p make_pair
#define pb push_back
#define lowbit(x) (x&(-x))
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin>>n;
    vector<pair<P,int> > a;
    for(int i=0;i<n;i++){
        int h,l,r;cin>>h>>l>>r;
        a.pb(m_p(m_p(l,h),0));
        a.pb(m_p(m_p(r,h),1));
    }
    sort(a.begin(),a.end());
    multiset<int> in;
    in.insert(0);
    vector<P> ans;
    for(int i=0;i<2*n;){
        int j=i;
        multiset<int>::iterator it=in.end();
        int o=*(--it);
        while(j<a.size()&&a[j].fr.fr==a[i].fr.fr){
            if(a[j].sc) in.erase(in.find(a[j].fr.sc));
            else in.insert(a[j].fr.sc);
            j++;
        }
        it=in.end();
        int now=*(--it);
        if(now!=o){
            ans.pb(m_p(a[i].fr.fr,o));
            ans.pb(m_p(a[i].fr.fr,now));
        }
        i=j;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i].fr<<" "<<ans[i].sc<<endl;
	return 0;
}