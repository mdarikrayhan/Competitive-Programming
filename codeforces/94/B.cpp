#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map> 
#include <set>
#include <map>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ON(n , k) ((n) | (1<<(k)))
#define OFF(n , k) ((n) & ~(1<<(k)))
#define forn(n) for(int i = 0; i < n; i++)
using namespace std;
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
typedef long long ll;
typedef unsigned long long ull;
int main() {
  fast
  int n, a, b;
  cin >> n;
  map<int , int>mp;
  for (int i = 1; i <= 5; i++)
  {
    mp[i] = 0;
  }    
  while (n--){
    cin >> a >> b;
    mp[a]++;
    mp[b]++;
  }
  for(auto i : mp){
    if(i.second != 2){
      cout << "WIN";
      return 0;
    }
  }
  cout << "FAIL";
  return 0;
}
	  		  		 		 	 	 			   		 				