// LUOGU_RID: 159021857
#include<bits/stdc++.h>
using namespace std;
int n,k,B;
int vis[2005];
int main(){
    scanf("%d%d",&n,&k);
    B=max(k/2,1);
    if(n==B)
        for(int i=1;i<=n;i++){
            printf("? %d\n",i);
            fflush(stdout);
            char c=getchar();
            while(c!='N'&&c!='Y')c=getchar();
            if(c=='Y')vis[i]=1;
        }
    else
        for(int i=1;i<=n;i+=B)
            for(int j=i+B;j<=n;j+=B){
                puts("R");fflush(stdout);
                for(int k=i;k<i+B;k++){
                    printf("? %d\n",k);
                    fflush(stdout);
                    char c=getchar();
                    while(c!='N'&&c!='Y')c=getchar();
                    if(c=='Y')vis[k]=1;
                }
                for(int k=j;k<j+B;k++){
                    printf("? %d\n",k);
                    fflush(stdout);
                    char c=getchar();
                    while(c!='N'&&c!='Y')c=getchar();
                    if(c=='Y')vis[k]=1;
                }
            }
    int ans=0;
    for(int i=1;i<=n;i++)if(!vis[i])ans++;
    printf("! %d\n",ans);fflush(stdout);
    return 0;
}