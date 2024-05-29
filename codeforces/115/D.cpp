// LUOGU_RID: 156991541
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[2005];
int n;
int a[2005];
void parse(){
    int len=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='+' || s[i]=='-')a[++len]=3;
        else if(s[i]=='*' || s[i]=='/')a[++len]=1;
        if(isdigit(s[i])){
            while(i<n && isdigit(s[i+1]))i++;
            a[++len]=2;
        }
    }
    n=len;
}
int f[2005][2005];
const int mod=1000003;
int pos[2005];
int tr[2005],tl[2005];
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    parse();
    for(int i=1;i<=n;i++)if(a[i]==1 && a[i-1]!=2){
        printf("0");
        return 0;
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=2)for(int j=1;j<=n;j++)f[i][j]=f[i-1][j-1];
        else for(int j=n;j>=0;j--)f[i][j]=(f[i-1][j]+f[i][j+1])%mod;
    }
    printf("%d",f[n][0]);
    return 0;
	// quod erat demonstrandum
}
