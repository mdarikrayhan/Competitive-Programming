#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x,y,c1,c2,c3,c4,c5,c6;
        cin >> x >> y;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
        swap(c5,c3);
        swap(c2,c6);
        if(x>=0 && y>=0){
            if(x > y){
                cout << min(c2*x+c6*y,min(c1*x+c3*(x-y),c1*y+c2*(x-y)))  << endl;
            }
            else{
                cout << min(c2*x+c6*y,min(c1*y+c5*(y-x),c1*x+c6*(y-x)))  << endl;
            }
        }
        else if(x <= 0 && y>= 0){
            x=-1*x;
            int z=min( (c4+c6)*x+c6*y,min(c6*y+c5*x,(c1+c5)*y+c5*x));
            cout << z << endl;
        }
        else if(x>=0 && y <= 0){
            y=-1*y;
            int z=min((c3+c1)*x+c3*y,min(c3*y+c2*x,(c4+c2)*y+c2*x));
            cout << z << endl;
        }
        else{
            x=abs(x);
            y=abs(y);
            if(x  > y ){
                cout << min(c5*x+c3*y,min(c4*y+c5*(x-y),c4*x+c6*(x-y))) << endl;
            }
            else{
                cout << min(c5*x+c3*y,min(c4*x+c3*(y-x),c4*y+c2*(y-x))) << endl;
            }
           
        }
        
        
    
    }
}
