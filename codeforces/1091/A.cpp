/*
  author: thanhbl-chler-hust;
  ** Ha Long High School for gifted **
  ** CS - SOICT/HUST **
*/

#include<bits/stdc++.h>

using namespace std;


void solve(){
  int a, b, c; cin >> a >> b >> c;

  /*c > b > a*/

  int st = 1;
  while(a >= st and b >= st + 1 and c >= st + 2) st += 1;
  cout << 3 * st;
}

int main(){
  solve();
  return 0;
}