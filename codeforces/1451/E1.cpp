#include<bits/stdc++.h>
using namespace std;
int n,i,x,x12,x13,x23,a12,a13,a23,s12,s13,s23,a[70000];

int get_xor(int u, int v){
	int val;
	cout<<"XOR "<<u<<' '<<v<<endl;
	cin>>val;
	return val;
}

int get_and(int u, int v){
	int val;
	cout<<"AND "<<u<<' '<<v<<endl;
	cin>>val;
	return val;
}

void Sol(){
	cin>>n;
	x12=get_xor(1,2);
	x23=get_xor(2,3);
	x13=x12^x23;
	a12=get_and(1,2);
	a13=get_and(1,3);
	a23=get_and(2,3);
	s12=x12+2*a12;
	s23=x23+2*a23;
	s13=x13+2*a13;
	a[1]=(s12+s13-s23)/2;
	a[2]=s12-a[1];
	a[3]=s13-a[1];
	for(i=4;i<=n;i++)
	{
		x=get_xor(1,i);
		a[i]=a[1]^x;
	}
	cout<<"! ";
	for(i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    Sol();
    return 0;
}
/*Dattebayo*/