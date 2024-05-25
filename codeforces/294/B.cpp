// LUOGU_RID: 160071655
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
int read(){
    int sz=0,zf=1;
    char ch=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-') zf=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        sz=sz*10+(ch-'0');
        ch=getchar();
    }
    return sz*zf;
}
int min(int x,int y){
	return x>y ? y : x;
}

vector<int> t,w;
int hou;
int main(){
    int n=read();
    t.push_back(0),w.push_back(0);
    for(int i=1;i<=n;i++) t.push_back(read()),w.push_back(read()),hou+=t[i];
    vector<int> dp(hou+1,10086);
    dp[0]=0;
    for(int i=1;i<=n;i++) for(int j=hou;j>=t[i];j--) dp[j]=min(dp[j],dp[j-t[i]]+w[i]);
    for(int i=hou;i>=0;i--){
        if(hou-i>=dp[i]){
            printf("%d",hou-i);
            break;
        }
    }
    return 0;
}