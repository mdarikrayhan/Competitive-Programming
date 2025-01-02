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

    int D;
    D = 1;
   cin >> D;
  

   while (D--) {
      
       int n, b;
       cin >> n >> b;
       int x = 0;
       for (int i = 0; i < n; i++) {
           if (i < b-1)cout << 'a';
           else {
               char ch = 'a';
               ch += x;
               cout << ch;
               x++; x %= 3;
               
           }
       }
       cout << endl;


   }
    return 0; 
}