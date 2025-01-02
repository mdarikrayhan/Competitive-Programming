// LUOGU_RID: 160416995
#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int bit[3][N]={0},n,ans[N]={0},a[2][N];
void add(int *b,int x,int val) {
    while(x<=n) b[x]+=val,x+=x&-x;
}
int sum(int *b,int x) {
    int s=0;while(x) s+=b[x],x-=x&-x;return s;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<2;i++) for(int j=1;j<=n;j++) scanf("%d",a[i]+j);
    for(int i=0;i<3;i++) for(int j=1;j<=n;j++) add(bit[i],j,1);
    for(int i=0;i<2;i++) for(int j=1;j<=n;j++) {
        int tmp=a[i][j];
        a[i][j]=sum(bit[i],tmp);
        add(bit[i],tmp+1,-1);
    }
    for(int j=n;j;j--) {
        ans[j-1]+=(a[0][j]+a[1][j]+ans[j])/(n-j+1);
        ans[j]=(a[0][j]+a[1][j]+ans[j])%(n-j+1);
    }
    for(int i=1;i<=n;i++) {
        int l=1,r=n,mid;
        while(l<r) {
            mid=(l+r)>>1;
            if(sum(bit[2],mid)<=ans[i]) l=mid+1;
            else r=mid;
        }
        ans[i]=l-1;
        add(bit[2],l,-1);
    }
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}
		 			 	 		   		 	 					  	   	