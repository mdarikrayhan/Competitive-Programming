#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool check(int a,int m){
  int cnt=0;
  while (a>0){
    cnt+=a/5;
    a/=5;
  }
  if (cnt>m){return true;}
  else return false;
}
bool check1(int a,int m){
  int cnt=0;
  while (a>0){
    cnt+=a/5;
    a/=5;
  }
  if (cnt>=m){return true;}
  else return false;
}
void solve(){
    int m;
    cin>>m;
    int low=1;
    int high=m*100;
    while (high-low>1){
        int mid=(low+high)/2;
        if (check(mid,m)){
            high=mid;
        }
        else{low=mid;}
    }
    int low1=1;
    int high1=m*100;
    while (high1-low1>1){
        int mid=(low1+high1)/2;
        if (check1(mid,m)){
            high1=mid;
        }
        else{low1=mid;}
    }
    cout<<low-high1+1<<'\n';
    for (int i=high1;i<=low;i++){
      cout<<i<<' ';
    }


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin>>t;
    t=1;
    while (t--){
      solve();
    }
}