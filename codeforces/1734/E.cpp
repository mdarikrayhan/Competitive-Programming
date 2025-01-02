#include <bits/stdc++.h>
using namespace std;

int want[355];
int board[355][355];
int main() {

	// CONSTRUCTIVE
    // OBSERVATION 1: adding a constant "c" to any row/column still preserves the "good matrix" property (DIDN'T GET THIS!)

    // i wrote a(r1,c1)-a(r2,c1) != a(r1,c2)-a(r2,c2) (mod n)  
    // so, if i just multiplied those indices, i would have constructed my matrix!

    // some other observations 
    // 1. For each j, the values a(i,j) − a(i−1,j) over all 0≤i<n must be a permutation of 0,1,⋯,n−1

	// 2. Let b be the two dimensional difference array of a, bij = a(i,j) − a(i−1,j) − a(i,j−1) + a(i−1,j−1). 
	// Then, the condition becomes sum of any rectangles of b must be nonzero (mod n) It is easy to see always b=1 can happen easily when a(i,j) = i*j 

	// THERE WAS NO USE OF n being prime OR n <= 350 !!

    int n;
    cin >> n;
    for(int i = 0; i < n ; i ++){
        cin >> want[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = (i * j) % n;
        }
    }
    for(int j = 0; j < n; j ++){
        int extra = (want[j] + n - board[j][j] )% n ;
        for (int i = 0; i < n; i++) {
            board[i][j] += extra;
            board[i][j] %= n;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}