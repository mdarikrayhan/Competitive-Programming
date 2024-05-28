// LUOGU_RID: 158541212
#include<bits/stdc++.h>
using namespace std;
#define N 1050500
#define ll long long 
int lik[N],ch[N][26],len[N],n,m,num=1,lst=1,idt[N];
ll col[N],val[N];
void insert(int c,int id){
    int p=lst,np=++num;lst=np;idt[id]=num;len[np]=len[p]+1;val[num]=col[id];
    for(;p&&!ch[p][c];p=lik[p])ch[p][c]=np;
    if(!p){
        lik[np]=1;return ;
    }
    int q=ch[p][c];
    if(len[q]==len[p]+1){
        lik[np]=q;return ;
    }
    int now=++num;lik[now]=lik[q],len[now]=len[p]+1;
    for(;p&&ch[p][c]==q;p=lik[p])ch[p][c]=now;
    for(int i=0;i<26;i++)ch[now][i]=ch[q][i];
    lik[q]=lik[np]=now;
}
int numt=1,rt=1,trans[N][26];
void insert_(string s,int w){
    int n=s.size(),p=rt;
    for(int i=0;i<n;i++){
        if(!trans[p][s[i]-'a'])trans[p][s[i]-'a']=++numt;
        p=trans[p][s[i]-'a'];col[p]+=w;
    }
}
vector<int>e[N];
void build(){
    queue<int>q;idt[rt]=1;q.push(rt);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<26;i++){
            if(trans[u][i]){
                lst=idt[u];
                insert(i,trans[u][i]);
                q.push(trans[u][i]);
            }
        }
    }
    for(int i=1;i<=num;i++)e[lik[i]].push_back(i);
}
ll res=0;
void dfs(int u){
    for(auto v:e[u]){
        dfs(v);val[u]+=val[v];
    }
    // cout<<u<<" "<<val[u]<<" "<<len[u]<<"\n";
    res=max(res,1ll*val[u]*len[u]);
}
string s[N];
signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++){
        int c;cin>>c;insert_(s[i],c);
    }
    build();
    dfs(1);
    cout<<res<<"\n";
}