// LUOGU_RID: 157846572
#include<bits/stdc++.h>
using namespace std;
#define ying puts("Stannis")
#define shu puts("Daenerys")
int read(){//��Ū���
	int sz=0,zf=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-') zf=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sz=sz*10+(ch-'0');
		ch=getchar();
	}
	return sz*zf;
}

int ji,ou;
int main(){
    int n=read(),k=read();
    for(int i=0;i<n;i++){
        int a=read();
        if(a%2==0) ou++;
        else ji++;
    } 
    int m=n-k;
    if(m==0){
        if(ji%2!=0) ying;
        else shu;
        return 0;
    }
    if(m%2!=0){
        if((m>>1)>=ji){
            shu;
            return 0;
        }
        if((m>>1)>=ou&&k%2==0){
            shu;
            return 0;
        }
        ying;
    }else{
        if((m>>1)>=ji){
            shu;
            return 0;
        }
        if((m>>1)>=ou&&k%2!=0){
            ying;
            return 0;
        }
        shu;
    }
    return 0;
}