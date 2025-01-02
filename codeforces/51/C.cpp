#include <iostream>
#include <vector> 
#include <math.h>
#include <string>
#include <algorithm>    
#include <queue>
#include <unordered_map>    
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision



using namespace std;

const int N = 2e5 + 5;
const double EPS = 1e-6;


int n, positions[N];


bool ok(double t){
    
    int secondStart = upper_bound(positions, positions+n, positions[0] + 2*t ) - positions; 
    if (secondStart == n) return 1;
    
    int thirdStart = upper_bound(positions, positions+n, positions[secondStart] + 2*t ) - positions; 
    if (thirdStart == n) return 1;
    
    int fourthStart = upper_bound(positions, positions+n, positions[thirdStart] + 2*t ) - positions; 
    if (fourthStart == n) return 1;
    
    return 0;
}


double bs(){

    double lo= 0.0, med, hi = 1e9 +5;

    while(hi-lo > EPS){
        med  = (lo + hi) / 2;
        if ( ok(med) ) hi = med;    
        else lo = med;       
    }
    return med;
}


int main(){
    
    int temp;
    // long long mid, lo, hi;
    
    cin >> n; 
    
    for( int i=0; i < n ; i++){
        cin >> temp;
        positions[i] = temp;
    }
    
    sort(positions, positions+n);
    
    double r = bs();
    
    cout << fixed << setprecision(6) << r << endl << positions[0] + r << " ";

    int secondPos = upper_bound(positions, positions+n, positions[0] + 2*(r+EPS) ) - positions; 
    cout << positions[secondPos] + r << " ";
    
    int thirdPos = upper_bound(positions, positions+n, positions[secondPos] + 2*(r+EPS) ) - positions; 
    cout << positions[thirdPos] + r << endl;

    
    return 0;

}
		 						   		        	 			 	