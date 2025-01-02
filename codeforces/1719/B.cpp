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
       ll n, m;
       cin >> n >> m;
       m %= 4;
       if (m == 0) {
           cout << "NO" << endl;
       }
       if (m % 2) {
           cout << "YES" << endl;
           for (int i = 1; i < n ; i+=2) {
               cout << i << " " << i + 1 << endl;
           }
       }
       if (m == 2) {
           cout << "YES" << endl;
           for (int i = 1; i < n; i += 2) {
               if((i+1)%4)cout << i+1 << " " << i << endl;
               else cout << i << " " << i + 1 << endl;
           }

       }
       

   }
    return 0
; 
}