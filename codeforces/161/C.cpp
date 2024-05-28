#include<bits/stdc++.h>
using namespace std;
int p(int a,int b,int c,int d,int now){
if(a>b||c>d)return 0;
int l=1<<now,fl=1;
while(fl){
fl=0;
while(c>l)c-=l,d-=l,fl=1;
while(a>l)a-=l,b-=l,fl=1;
while(l>max(b,d))now--,l>>=1,fl=1;
if(a>c||a==c&&d>b)swap(a,c),swap(b,d);
}
if(b>=d)return d-c+1;
return max(max(p(a,b,c,l-1,now),p(1,d-l,a,b,now)),b-c+1);
}
int main(){
int a,b,c,d;
cin>>a>>b>>c>>d;
cout<<p(a,b,c,d,30);
}