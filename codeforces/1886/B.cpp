#include <bits/stdc++.h>
using namespace std;
//#define int long long
double dist(int x1,int y1,int x2,int y2){
	double d=sqrt(1.0*(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return d;
}
bool checkInRound(double r,int rx,int ry,int tx,int ty){
	return dist(rx,ry,tx,ty)<r+1e-12;
}
void solve(){
	int px,py,ax,ay,bx,by;
	cin>>px>>py>>ax>>ay>>bx>>by;
	if(px*px+py*py==0){
		cout<<"0\n";
		return;
	}
	double l=0,r=1e8;
	while(r-l>1e-12){
		double mid=(l+r)/2;
		int statea=0,stateb=0;
		if(checkInRound(mid,ax,ay,px,py))statea++;
		if(checkInRound(mid,ax,ay,0,0))statea+=2;
		if(checkInRound(mid,bx,by,px,py))stateb++;
		if(checkInRound(mid,bx,by,0,0))stateb+=2;
		if(stateb>=3||statea>=3||((stateb|statea)>=3&&dist(ax,ay,bx,by)<=mid*2+1e-12)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	cout<<fixed<<setprecision(10)<<l<<"\n";
	return;
}

signed main(){
	int ____=1;
	cin>>____;
	while(____--)solve();
	return 0;
}