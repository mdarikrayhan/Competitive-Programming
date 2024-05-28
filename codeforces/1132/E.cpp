#include<bits/stdc++.h>
using namespace std;
long long w,res;
vector<long long>vec(8);
void dfs(int idx,long long val){
    if(val<0)return ;
    res = max(res,w - val);
    if(idx==-1)return ;
    long long cnt = min(val/(idx+1),vec[idx]);
    for(int i = 0;i<=idx && cnt - i >=0 ;++i){
        dfs(idx-1,val - (cnt-i)*(idx+1));
    }
}
int main(){
    cin>>w;
    for(auto &a:vec)cin>>a;
    dfs(7,w);
    cout<<res<<endl;
    return 0;
}