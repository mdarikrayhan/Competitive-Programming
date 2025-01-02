#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <limits>
#include <conio.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef float ft;
typedef vector<int> vint;
#define push push_back
#define vsrt(v) sort(v.begin(), v.end())
#define rep(i, j, k) for (long long i = j; i < k; i++)
#define endl '\n'
#define fk " "
#define la 1e+18

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    int a[n][n];
    rep(i,0,n) {a[0][i]=1;}
    rep(i,1,n){
        rep(j,0,n){
            if(j==0) a[i][j]=1;
            else{
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
    }
    cout<<a[n-1][n-1]<<endl;
}
		 	 		 	 	     	  	 		 				 	