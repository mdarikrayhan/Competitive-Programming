#include<bits/stdc++.h>
using namespace std;
int main(){

    string o[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight" , "nine" };
    string p[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen" ,
     "eighteen", "nineteen" };
    string d[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy" ,
     "eighty", "ninety" };

     int n;
     cin >> n;

     if(n < 10){
        cout << o[n] << endl;
     }
     else if(n >= 10 && n < 20){
        cout << o[n] << endl;
     }
     else if( n % 10 == 0){
        cout << d[n/10] << endl;
     }
     else {
        cout << d[n/10] << "-" << o[n%10] << endl;
     }


return 0;
}
