#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath> 

using namespace std;

double x, y, v_max, t_max, vx, vy, wx, wy;

double solve(double left, double right, int depth = 0) {
    if(depth == 100) return right;
    double mid = (left+right)/2;
    double gx = x, gy = y;
    gx += (-vx) * min(mid, t_max) + (-wx) * max(0.0, mid-t_max);
    gy += (-vy) * min(mid, t_max) + (-wy) * max(0.0, mid-t_max);
    double d = sqrt(gx*gx +gy *gy);
    if(mid*v_max>=d) return solve(left, mid, depth+1);
    else return solve(mid, right, depth+1);
}

int main(){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    x = x2-x1, y = y2-y1;
    cin >> v_max >> t_max;

    cin >> vx >> vy >> wx >> wy;

    double left = 0,right = 1e18;

    cout << fixed << setprecision(18) << solve(left, right) << endl;
}