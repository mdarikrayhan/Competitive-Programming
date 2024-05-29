// LUOGU_RID: 159059485
#include<bits/stdc++.h>

using namespace std;
int n,k;
int a[200005];
int pa[200005][21],pb[200005][21],sa[200005][21],sb[200005][21];
int last[200005];
int calc(int x,int k,int op){
    while(k){
        int s=__lg(k);
        if(op==0)x=pa[x][s];
        else if(op==1)x=pb[x][s];
        else if(op==2)x=sa[x][s];
        else if(op==3)x=sb[x][s];
        if(!x)return x;
        k^=(1<<s);
    }
    return x;
}
int Solve(int x,int y,int op){
    int ans=0;
    if(op)ans=n+1;
    int l=0,r=(k-2)/2,Lim=(k-2)/2;
    while(l<=r){
        int mid=l+r>>1;
        int u=calc(x,mid,(op?2:0)),v=calc(y,Lim-mid,(op?3:1));
        // if(!op)cerr<<x<<" "<< y <<" "<<mid<< " "<< u<<" "<<v<<endl;
        if(!u)r=mid-1;
        else if(!v)l=mid+1;
        else {
            if(op){
                if(u>v)r=mid-1,ans=min(ans,u);
                else l=mid+1,ans=min(ans,v);
            }
            else {
                if(u<v)r=mid-1,ans=max(ans,u);
                else l=mid+1,ans=max(ans,v);
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    if(k&1){
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        pa[i][0]=last[a[i]-1];
        pb[i][0]=last[a[i]+1];
        last[a[i]]=i;
        for(int j=1;j<20;j++){
            pa[i][j]=pa[pa[i][j-1]][j-1];
            pb[i][j]=pb[pb[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=n;i++)last[i]=0;
    for(int i=n;i>=1;i--){
        sa[i][0]=last[a[i]-1];
        sb[i][0]=last[a[i]+1];
        last[a[i]]=i;
        for(int j=1;j<20;j++){
            sa[i][j]=sa[sa[i][j-1]][j-1];
            sb[i][j]=sb[sb[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=n;i++)last[i]=0;
    int ans=n+1;
    for(int i=1;i<=n;i++){
        int x=last[a[i]],y=i;last[a[i]]=i;
        if(!x)continue;
        int L=Solve(x,x,0),R=min(Solve(x,y,1),Solve(y,x,1));
        // cerr<<x<<" "<<y<< " "<<L<< " "<<R<<endl;
        if(L&&R!=n+1)ans=min(ans,R-L);
        R=Solve(y,y,1),L=max(Solve(x,y,0),Solve(y,x,0));
        if(L&&R!=n+1)ans=min(ans,R-L);
    }
    printf("%d\n",(ans==n+1?-1:ans));
    return 0;
}