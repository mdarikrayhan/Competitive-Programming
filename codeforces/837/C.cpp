#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;

struct Node{
	int x,y;
	int area;
}h[105];

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	for(int i=0;i<n;i++){
		cin >> h[i].x;
		cin >> h[i].y;
		h[i].area=h[i].x*h[i].y;
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(h[i].x+h[j].x<=a&&max(h[i].y,h[j].y)<=b)
				ans=max(ans,h[i].area+h[j].area);
			else if(h[i].x+h[j].y<=a&&max(h[i].y,h[j].x)<=b)
				ans=max(ans,h[i].area+h[j].area);
			else if(h[i].y+h[j].x<=a&&max(h[i].x,h[j].y)<=b)
				ans=max(ans,h[i].area+h[j].area);
			else if(h[i].y+h[j].y<=a&&max(h[i].x,h[j].x)<=b)
				ans=max(ans,h[i].area+h[j].area);
				
			else if(h[i].x+h[j].x<=b&&max(h[i].y,h[j].y)<=a)
				ans=max(ans,h[i].area+h[j].area);
			else if(h[i].x+h[j].y<=b&&max(h[i].y,h[j].x)<=a)
				ans=max(ans,h[i].area+h[j].area);
			else if(h[i].y+h[j].x<=b&&max(h[i].x,h[j].y)<=a)
				ans=max(ans,h[i].area+h[j].area);
			else if(h[i].y+h[j].y<=b&&max(h[i].x,h[j].x)<=a)
				ans=max(ans,h[i].area+h[j].area);
		}
	}
	cout << ans << endl;
}