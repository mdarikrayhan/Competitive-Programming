// LUOGU_RID: 158489017
#include <bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
const int maxhash=7e5+5;
const int base=27;
const int maxc=5;
const int lim=305;
const int tot=(maxn/lim)+5;
const int tot2=105;
const int inf=0x3f3f3f3f;
int n,q,h[maxn][maxc],ans[tot][maxn<<2],cnt[maxhash];
int sum,flag[maxhash];
vector <int> pos[maxhash],s;
string str,id[maxhash];
inline int gethash(string ss){
    while (ss.size()<5) ss+=('a'-1);
    int res=0;
    for (int i=1;i<=4;i++) res=(res*base)+(ss[i]-'a'+1);
    return res;
}
inline void updmin(int &u,int v) {u=min(u,v); }
inline int calc(int l1,int len1,int l2,int len2){
    int r1=l1+len1-1,r2=l2+len2-1;
    // printf("%d-%d %d-%d %d\n",l1,r1,l2,r2,max(r1,r2)-min(l1,l2)+1);
    return max(r1,r2)-min(l1,l2)+1;
}
inline void solve(int d){
    int p=0;
    string qwq=" abc";
    // if (d==gethash(qwq)) {printf("qwq\n"); }
    for (int i=1;i<=n;i++){
        while (p+1<pos[d].size() && pos[d][p+1]<=i) p++;
        for (int j=1;j<=4;j++){
            if (i+j-1>n) break;
            updmin(ans[sum][cnt[h[i][j]]],calc(i,j,pos[d][p],id[d].size()-1));
            if (p+1<pos[d].size()) updmin(ans[sum][cnt[h[i][j]]],calc(i,j,pos[d][p+1],id[d].size()-1));
        }
    }
}
int main(){
    memset(ans,inf,sizeof(ans));
    cin>>str,n=str.size();
    str=' '+str;
    for (int i=1;i<=n;i++){
        string x=" ";
        for (int j=1;j<=4;j++){
            if (i+j-1>n) break;
            x+=str[i+j-1];
            int now=gethash(x);
            h[i][j]=now;
            if (!pos[now].size()) cnt[now]=s.size(),s.push_back(now);
            pos[now].push_back(i);
            id[now]=x;
        }
    }
    for (int i=0;i<s.size();i++){
        if (pos[s[i]].size()<lim) continue;
        flag[s[i]]=++sum;
        solve(s[i]);
    }
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        string x,y;
        cin>>x>>y;
        x=' '+x,y=' '+y;
        if (x.size()>y.size()) swap(x,y);
        int hx=gethash(x),hy=gethash(y);
        if (!(pos[hx].size() && pos[hy].size())) printf("-1\n");
        else{
            if (pos[hy].size()>=lim) printf("%d\n",ans[flag[hy]][cnt[hx]]);
            else{
                int p1=0,p2=0,res=n;
                while (p1<pos[hx].size()){
                    while (p2+1<pos[hy].size() && pos[hy][p2+1]<=pos[hx][p1]) p2++;
                    updmin(res,calc(pos[hx][p1],x.size()-1,pos[hy][p2],y.size()-1));
                    if (p2+1<pos[hy].size()) updmin(res,calc(pos[hx][p1],x.size()-1,pos[hy][p2+1],y.size()-1));
                    p1++;
                }
                printf("%d\n",res);                
            }
        }
    }
    return 0;
}