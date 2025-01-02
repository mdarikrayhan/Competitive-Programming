// LUOGU_RID: 159222288
#include<bits/stdc++.h>

using namespace std;
int n,b;
int id[205];
int st[205],tp;
int now[205];
bool check(int x,int op){
    printf("%d ",x);
    for(int i=1;i<=tp;i++)printf("%d",now[i]);
    if(tp!=b){
        putchar(op?'1':'0');
        for(int i=1;i<=b-tp-1;i++)putchar('1');
    }
    putchar('\n');
    fflush(stdout);
    char s[5];
    scanf("%s",s+1);
    if(s[1]=='y')return true;
    else return false;
}
void Solve(int last){
    if(!n)return;
    for(int i=1;i<=n;i++){
        int x=id[i];
        while(tp>last&&check(x,1)){
            while(tp>last&&now[tp]==1)tp--;
            if(tp>last)tp--;
        }
        if(tp!=b)now[tp+1]=check(x,0),st[++tp]=x;
    }
    for(int i=tp;i>last;i--)
        if(check(st[i],1))tp=i;
    n=0;
    for(int i=last+1;i<=tp;i++)id[++n]=st[i];
    Solve(tp);
}
int main(){
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++)id[i]=i;
    Solve(0);
    printf("%d ",0);
    for(int i=tp+1;i<=b;i++)now[i]=0;
    for(int i=1;i<=b;i++)printf("%d",now[i]);
    putchar('\n');
    fflush(stdout);
    return 0;
}