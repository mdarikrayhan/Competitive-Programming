#include <bits/stdc++.h>
using namespace std;
int t,n,a;
int solve(){
scanf("%d",&n);
int s=0, ss=0;
while(n--){
scanf("%d",&a);
s+=a;
ss=max(ss,s);
}
return ss;
}
int main(){
scanf("%d",&t);
while(t--) printf("%d\n",solve()+solve());
}