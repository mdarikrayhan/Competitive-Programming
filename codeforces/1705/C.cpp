#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin>>t;
while(t--)
{
int n,c,q;
cin>>n>>c>>q;
string s;
cin>>s;
long long l[c+1],r[c+1],len[c+2];
len[0]=n;

for(int i=1;i<=c;i++){
cin>>l[i]>>r[i];
len[i] =len[i-1]+ r[i]-l[i]+1;
}

while(q--){
long long k;
cin>>k;
for(int i=c-1;i>=0;i--){
if(k>len[i]){
k = l[i+1]+(k-len[i]-1);
}
}
assert(k<=n);
cout<<s[k-1]<<endl;
}
}
}