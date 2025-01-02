#include<bits/stdc++.h>
#define Exp 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 10000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
char str[N];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    int pos=n/2;
    for(int i=1;i<=pos;i++){
        if(str[i]=='L')
            printf("%d %d\n",i,i+pos);
        else if(str[i]=='R')
            printf("%d %d\n",i+pos,i);
    }
    return 0;
}