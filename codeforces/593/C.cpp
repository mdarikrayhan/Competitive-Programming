// LUOGU_RID: 158211421
#include<iostream>
#include<cstdio>
using namespace std;
/*struct node{
	int x;
	int y;
	int r;
}a[55];*/
int n,a[55][5];
void work(int l2,int r2,int d){
    if(l2==r2){
    	printf("(%01d*abs(((1-abs((t-%d)))+abs((abs((t-%d))-1)))))",a[l2][d]/2,l2,l2);
    }
    else{
	  printf("(");
	  work(l2,(l2+r2)>>1,d);
	  printf("+");
	  work(((l2+r2)>>1)+1,r2,d);
	  printf(")");
	}
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
    	//cin>>a[i].x>>a[i].y>>a[i].r;
    	cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	work(1,n,0);
	cout<<"\n";
	work(1,n,1);
    return 0;
}