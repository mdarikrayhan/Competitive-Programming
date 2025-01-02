// LUOGU_RID: 156065106
#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[200005];
int col[1000005],val[1000005],to[1000005],tot;
int len[2],head[2],a,b;
vector<pair<int,int>>ans;
int newnode(int c,int v,int nxt){
    col[++tot]=c,val[tot]=v,to[tot]=nxt;
    return tot;
}
void build(int flag){
    scanf("%s",s+1);int n=strlen(s+1);
    int x=head[flag]=newnode(s[1]-'a',1,0);
    len[flag]=1;
    for(int i=2;i<=n;i++)
        if(s[i]==s[i-1])val[x]++;
        else x=to[x]=newnode(s[i]-'a',1,0),len[flag]++;
}
int main(){
    build(0),build(1);
    a=0,b=1;
    while(len[a]>1||len[b]>1){
        if(len[a]<len[b])swap(a,b);
        if(col[head[a]]==col[head[b]]&&(len[b]==1||len[a]==2)){
            int x=len[a]/2+(len[a]/2%2==0);
            int now=head[a],sum=val[now];
            for(int i=1;i<x;i++)sum+=val[now=to[now]];
            ans.push_back(make_pair(b?sum:0,a?sum:0));
            int hb=head[b];
            val[now]+=val[head[b]];
            head[b]=head[a],head[a]=to[now],to[now]=to[hb];
            len[a]-=x,len[b]=x+(len[b]>1);
        }else if(col[head[a]]!=col[head[b]]&&len[b]==1){
            int x=len[a]/2;
            int now=head[a],sum=val[now];
            for(int i=1;i<x;i++)sum+=val[now=to[now]];
            if(x%2){
                ans.push_back(make_pair(b?sum:val[head[b]],a?sum:val[head[b]]));
                int ha=head[a];
                val[to[now]]+=val[head[b]],head[a]=to[now],to[now]=0,head[b]=ha;
                len[a]-=x,len[b]=x;
            }else{
                ans.push_back(make_pair(b?sum:0,a?sum:0));
                int hb=head[b];
                val[now]+=val[head[b]];
                head[b]=head[a],head[a]=to[now],to[now]=to[hb];
                len[a]-=x,len[b]=x;
            }
        }else{
            int x=(len[a]-len[b]+2)/2+((len[a]-len[b]+2)/2%2==(col[head[a]]==col[head[b]]));
            int now=head[a],sum=val[now];
            for(int i=1;i<x;i++)sum+=val[now=to[now]];
            ans.push_back(make_pair(b?sum:val[head[b]],a?sum:val[head[b]]));
            int ha=head[a];
            val[to[now]]+=val[head[b]],head[a]=to[now];
            val[now]+=val[to[head[b]]],to[now]=to[to[head[b]]],head[b]=ha;
            len[a]-=x,len[b]+=x-2;
        }
    }
    printf("%d\n",(int)ans.size());
    for(auto p:ans)printf("%d %d\n",p.first,p.second);
    return 0;
}
/*
010 10
0
len[a]-x=x

0 1
01

01 010
0 10
len[a]-x=len[b]+x-2

01 010
1
len[a]-x=x

010 101
1

010 10
1 01
len[a]-x=len[b]+x-2
*/