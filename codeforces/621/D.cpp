#include<bits/stdc++.h>
 
using namespace std;

const int MAX = 2e5+5;
const long double EPS = 1e-9;

long double x,y,z,ans = -1e9,res;
string s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>x>>y>>z;
	
	res = log(x) * pow(y, z);
	if(res > ans+EPS)ans = res, s = "x^y^z";
	
	res = log(x) * pow(z, y);
	if(res > ans+EPS)ans = res, s = "x^z^y";
	
	res = log(x) * y * z;
	if(res > ans+EPS)ans = res, s = "(x^y)^z";
	
	res = log(y) * pow(x, z);
	if(res > ans+EPS)ans = res, s = "y^x^z";
	
	res = log(y) * pow(z, x);
	if(res > ans+EPS)ans = res, s = "y^z^x";
	
	res = log(y) * x * z;
	if(res > ans+EPS)ans = res, s = "(y^x)^z";
	
	res = log(z) * pow(x, y);
	if(res > ans+EPS)ans = res, s = "z^x^y";
	
	res = log(z) * pow(y, x);
	if(res > ans+EPS)ans = res, s = "z^y^x";
	
	res = log(z) * x * y;
	if(res > ans+EPS)ans = res, s = "(z^x)^y";
	
	cout<<s<<endl;
	return 0;
}