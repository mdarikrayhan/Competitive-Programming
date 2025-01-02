#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{int n;
cin >> n;
while(n--){
int x;
string s;
int l, r;
cin >> x >> s ;
l=s.find('1');
r=s.rfind('0');
if(r>l&&l!=-1&&r!=-1)
s.erase(l, r-l);
cout << s <<endl;
}
}