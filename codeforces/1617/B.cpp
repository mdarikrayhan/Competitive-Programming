
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <set>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>

#include <climits>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#define ll long long int
#define lf long float

#define PI 3.1415926535897932384626433832795
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll a;
        cin>>a;
        if(a%2==0){
            cout<<a/2<<" "<<(a-2)/2<<" "<<1<<endl;
        }
        else{
            int r = (a-1)/2;
            if(r%2==0){
                cout<<r-1 <<" "<<r +1 <<" "<< 1 <<endl;
            }else{
                cout<<r-2 << " " << r+2 << " "<<1<<endl;
            }
        }
    }
    return 0;
}
