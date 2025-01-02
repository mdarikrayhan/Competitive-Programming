// LUOGU_RID: 159465853
#include<bits/stdc++.h>
using namespace std;
int main (){
int a , b , c , d;
cin>> a >> b >> d;
for(int i = 2 ; i <= d ; i++){
c = a + b;
a = b;
b = c;
}
cout << b << endl;
return 0;
}