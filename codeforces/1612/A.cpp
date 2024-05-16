#include <bits/stdc++.h>
  #include <cstdio>

  using namespace std;

  int main (int argc, char *argv[]) {
    int t; scanf("%d", &t);
    int xb, yb;
    while(t--) {
     scanf("%d %d", &xb, &yb);
     if(((xb + yb) % 2) != 0) {
      printf("-1 -1\n");
      continue;
     }
    
     int maxd = (xb + yb)/2;
     int sol = -1;
     for(int i = 0; i <= maxd; ++i) {
      if(abs(xb - i) + abs(yb - maxd + i) == maxd) {
       sol = i;
       break;
      }
     }
     if(sol == -1) printf("-1 -1\n");
     else printf("%d %d\n", sol, maxd - sol);
   
    }
    return 0;
  }
			 					 				 	    	 	   			