#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
long long int num,sum=0;
cin >> num;
if(num&1){
    sum= -num;
    num--;
    sum+=num/2;
}
else{
    sum=num/2;
}
cout<<sum<<nl;

return 0;
}