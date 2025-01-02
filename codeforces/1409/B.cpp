#include<bits/stdc++.h>
using namespace std;

int main(){
   long long  int t;
    cin  >> t;
    while(t--){
  long long int a , b ,x , y, n;
   cin >> a >> b >> x >> y >> n;
   long long int l = a,o = b,e=n;
   long long int k = a - x;
   long long int p = b -  y;
   long long int r = min(k,n);
   a = a - r;
   n = n - r;
   long long int q = min(p,n);
   b = b - q;
   n = n - q;
   long long int s = min(p,e);
   o = o - s;
   e = e - s;
   long long int f = min(k,e);
   l = l - f;
   e = e- f;
   cout << min(a*b,l*o) << endl;
    }

   
}
