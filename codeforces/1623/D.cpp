#include<bits/stdc++.h>
using namespace std;
# define int long long
const int mod=1e9+7;
int binp(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}
void solve(){
    int n,m,x1,y1,x,y,p;
    cin>>n>>m>>x1>>y1>>x>>y>>p;
    vector<pair<int,int>>vct={{x1,y1}};
    int currx=x1,curry=y1,dirx=1,diry=1,stx,sty;
    if(currx+dirx<1 || currx+dirx>n)dirx*=-1;
    if(curry+diry<1 || curry+diry>m)diry*=-1;
    stx=dirx,sty=diry;
    currx+=dirx;
    curry+=diry;
    vct.push_back({currx,curry});
    while(true){
        if(currx+dirx<1 || currx+dirx>n)dirx*=-1;
        if(curry+diry<1 || curry+diry>m)diry*=-1;
        if((dirx==stx) && (diry==sty) &&(currx==x1) && (curry==y1) ){
            break;
        }
        currx+=dirx;
        curry+=diry;
        vct.push_back({currx,curry});
    }
    vct.pop_back();
    int l=vct.size();
    bool val[l];
    for(int i=0;i<l;i++){
        val[i]=false;
        if((vct[i].first==x) ||(vct[i].second==y) )val[i]=true;
    }
    vector<int>ind;
    for(int i=0;i<l;i++)if(val[i])ind.push_back(i);
    int k=ind.size();
    int q=100-p;
    p*=binp(100,mod-2);
    q*=binp(100,mod-2);
    p%=mod;
    q%=mod;
    int qk=binp(q,k);
    int val2=binp(binp((1-qk+mod)%mod,mod-2),2);
    val2*=(qk*l)%mod;
    val2%=mod;
    int val1=binp((1-qk+mod)%mod,mod-2);
    int answer=0;
    int curr=1;
    for(int j=0;j<ind.size();j++){
        int vv=((ind[j]*val1)%mod+val2)%mod;
        answer+=(vv*curr)%mod;
        curr*=q;
        curr%=mod;
    }
    answer%=mod;
    answer*=p;
    answer%=mod;
    cout<<answer<<"\n";
}
int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test=1;
    cin>>test;
    while(test--)solve(); 
}