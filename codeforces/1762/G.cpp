// LUOGU_RID: 159373910
#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n;
int a[N],cnt[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cnt[i]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(cnt[a[i]]>(n+1)/2){
            flag=1;
            break;
        }
    }
    if(flag)cout<<"NO"<<'\n';
    else{
        vector<int> ans;
        int idx=1;
        while(idx<=n){
            int v=a[idx];
            vector<int> v1,v2;
            while(idx<=n){
                if(a[idx]==v)v1.push_back(idx);
                else v2.push_back(idx);
                if(v1.size()==v2.size()){
                    for(int i=0;i<v1.size();i++){
                        ans.push_back(v1[i]),ans.push_back(v2[i]);
                    }
                    ans.pop_back();
                    break;
                }
                if(idx==n){
                    while(1){
                        if(ans.empty()||v1.size()==v2.size()){//不妨用偶数构造，这样可以方便的解决a[l-1]=a[n]的问题
                            // cout<<ans.size()<<" "<<v1.size()<<" "<<v2.size()<<'\n';
                            sort(v1.begin(),v1.end());
                            sort(v2.begin(),v2.end());
                            // for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";
                            // cout<<'\n';
                            // for(int i=0;i<v2.size();i++)cout<<v2[i]<<" ";
                            // cout<<'\n';
                            if(v1.size()!=v2.size()){
                                ans.push_back(v1[0]);
                                v1.erase(v1.begin());
                            }
                            if(v2.size()&&ans.size()){
                                if(a[ans.back()]==a[v2[0]])swap(v1,v2);
                            }
                            for(int i=0;i<v1.size();i++){
                                ans.push_back(v2[i]),ans.push_back(v1[i]);
                            }
                            break;
                        }
                        if(a[ans.back()]==v)v1.push_back(ans.back());
                        else v2.push_back(ans.back());
                        ans.pop_back();
                    }
                    idx=n+1;
                }
                idx++;
            }
        }
        cout<<"YES\n";
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<'\n';
    }
}
int main(){
    // ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}
/*   /\_/\
*   (= ._.)
*   / >  \>
*/