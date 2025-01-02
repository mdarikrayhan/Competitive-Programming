#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findGCD(int a, int b) {
   if (b == 0)
      return a;
      return findGCD(b, a % b);
   }
   void lowestFraction(int num1, int num2){
      int denom;
      denom = findGCD(num1,num2);
      num1/=denom;
      num2/=denom;
      cout << num1<<"/"<<num2;
}
int main()
{
   int y,w, highest, n1, n2;
   
   cin >> y>> w;
   if (y>w || y ==w){
       highest=y;
       n1=7-y;
   }else {
       highest=w;
       n1=7-w;
   }
   n2=6;
   lowestFraction(n1,n2);
   

    return 0;
}