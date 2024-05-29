// LUOGU_RID: 112540202
#include<bits/stdc++.h>
using namespace std;int T;string s;int main(){scanf("%d",&T);while(T--){cin>>s;int le=0,flag=1;for(char i:s)if(i=='b'||i=='d'||i=='f'||i=='h'||i=='k'||i=='l'||i=='t')le++;else if(i=='g'||i=='j'||i=='p'||i=='q'||i=='y'){if(le==0){flag=0;break;}else le--;}puts((flag&&le==0)?"YES":"NO");}return 0;}