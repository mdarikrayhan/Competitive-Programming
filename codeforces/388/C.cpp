// LUOGU_RID: 160136309
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')
          f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	  write(x/10);
	putchar(x%10+'0');
}
ll A,B,n,x,y;
priority_queue<ll> Q;
bool f=1;
int main(){
	n=read();
	while(n--){
		x=read();
		for(int i=1;i<=x;i++){
			y=read();
			if((x&1ll)&&i==((x+1)>>1ll))
			  Q.push(y);
			else{
				if(i<=(x>>1ll))
				  A+=y;
				else
				  B+=y;
			}
		}
	}
	while(!Q.empty()){
		if(f)
		  A+=Q.top();
		else
		  B+=Q.top();
		Q.pop();
		f^=1ll;
	}
	write(A);
	putchar(' ');
	write(B);
	return 0;
}
