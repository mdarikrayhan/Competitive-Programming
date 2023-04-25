#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n,m;

cin >> n >> m;
string s(m, 'B');
while (n--) {
int x; cin >> x;
x--;
x = min(x, m - x - 1);
if (s[x] == 'B') s[x] = 'A';
else s[m - x - 1] = 'A';
}
cout << s <<endl;
}
return 0;
}