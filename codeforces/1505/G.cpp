#include<cstdio>
const int N=100005;
int y[27]={10010,11020,20011,21012,11011,21021,22022,12021,11011,12012,10120,11130,20121,21122,11121,21131,22132,12131,11121,12122,10221,11231,12113,20222,21223,11222};
char x[30000];
int t,s,z;
int main(){
    for(int i=0;i<26;i++){
        if(!x[y[i]])x[y[i]]=i+'a';
    }
    scanf("%d",&t);
    while(t--){
        z=0;
        for(int i=0;i<5;i++)
            scanf("%d",&s),z=z*10+s;
        putchar(x[z]);
    }
    return 0;
}