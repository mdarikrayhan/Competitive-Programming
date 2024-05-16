#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int w,d,h;
		cin>>w>>d>>h;
		int a,b,f,g;
		cin>>a>>b>>f>>g;
		int x=h+abs(f-a)+min(b+g,2*d-b-g);
		int y=h+abs(b-g)+min(a+f,2*w-f-a);
		cout<<min(x,y)<<endl;
	}
}