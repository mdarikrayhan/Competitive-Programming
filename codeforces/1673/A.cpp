#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>
#include<time.h>
#include <sys/types.h>


typedef long long int ll;
//#include<bits/stdc++.h>


using namespace std;



int main()
{

    int Q;
    Q = 1;
   cin >> Q;
    
    
   while (Q--) {
       string p;
       cin >> p;
       int  n = p.size();
       int r = 0;
       for (int i = 0; i < n; i++) {
           r += p[i] - 'a'+1;
         //  cout << r;
       }
       
       if (n % 2) {
           
           if (n>1) {
               if (p[0] >= p[n - 1])r -= (p[n - 1]-'a'+1)*2;
               else r -= (p[0]-'a'+1)*2;
               cout << "Alice" << " ";
               cout << r << endl;
           }
           else {
               cout << "Bob" << " ";
               cout << r << endl;
           }
       }
       else {
           cout << "Alice" << " ";
           cout << r << endl;
       }

   }
    return 0
; 
}