#include<stdio.h>
#include<cstdlib>
constexpr int n(200);
int main() {
    printf("? %d\n",n*n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%d %d ",i,j);
        }
    }
    printf("\n");
    fflush(stdout);
    int s;
    scanf("%d",&s);
    int l(1),r(7),t(0);
    while(l<=r) {
        const int mid(l+r>>1);
        printf("? %d\n",((n-1>>mid)+1)*n);
        for(int i=1;i<=n;i+=1<<mid) {
            for(int j=1;j<=n;j++) {
                printf("%d %d ",i,j);
            }
        }
        printf("\n");
        fflush(stdout);
        int p;
        scanf("%d",&p);
        if(s==p<<mid) {
            l=mid+1;
        }
        else {
            t=p,r=mid-1;
        }
    }
    const int a(std::abs((s>>r)-(t<<1)));
    printf("! %d\n",a+s/a-2<<1);
    return 0;
}