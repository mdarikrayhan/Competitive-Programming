// LUOGU_RID: 159013067
#include<bits/stdc++.h>
using namespace std;
long long n;
char a,b,c,d,e;
int main(){
   cin>>n>>a>>b>>c>>d>>e;
   if(d>='6')d='0';
   if(n==12)
   {
   	if(a=='0'&&b=='0')
   		b='1';
   	else if(10*(a-'0')+(b-'0')>12&&b>'0')
   	    a='0';
   	else if(10*(a-'0')+(b-'0')>12&&b=='0')
   	    a='1';
   }
   if(n==24&&10*(a-'0')+(b-'0')>=24)
   	    a='0';
   cout<<a<<b<<c<<d<<e;
   return 0;
}