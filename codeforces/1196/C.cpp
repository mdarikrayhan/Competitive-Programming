#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std ;
using namespace __gnu_pbds ; 

#define F first
#define S second
#define pb push_back
#define ll long long 
#define ld long double
#define rev greater < int >()
#define all(x) (x).begin () , (x).end ()
#define RF(F) freopen(F , "r" , stdin ) 
#define WF(F) freopen(F , "w" , stdout) 
#define IOS ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
#define ordered_set tree < int , null_type , less < int > , rb_tree_tag , tree_order_statistics_node_update > 


typedef pair < int , int > pii ;
typedef pair < long long , long long > pll ;
typedef map  < int , int > mii ; 
typedef map  < long long , long long > mll ;
typedef vector < int > vi ;
typedef vector < long long > vl ;


const ld  pi  = 3.14159265359 ;
const ld  eps = 1e-9 ;
const ll  INF = 1e9 ;
const int mod = 1e9 + 7 ;
const int MAX_N = 1e6 + 7 ;


int a[MAX_N] ;


struct robot{
    
    int x , y , f1 , f2 , f3 , f4 ;
    
    robot(int tx = 0 , int ty = 0 , int tf1 = 0 , int tf2 = 0 , int tf3 = 0 , int tf4 = 0){

        x = tx ;
        y = ty ;
        f1 = tf1 ;
        f2 = tf2 ;
        f3 = tf3 ;
        f4 = tf4 ;

    }


};



void solve(int testCase){
    
    int n ;
    scanf("%d" , &n) ;

    vector < robot > v(n) ;

    for(int i = 0 ; i < n ; i ++){
        scanf("%d %d %d %d %d %d" , &v[i].x , &v[i].y , &v[i].f1 , &v[i].f2 , &v[i].f3 , &v[i].f4) ; 
    }

    int lx = -1e5 , rx = 1e5 , ly = -1e5 , ry = 1e5 ;

    for(int i = 0 ; i < n ; i ++){

        if(v[i].f1 == 0) {
            lx = max(lx , v[i].x) ;
        }
        if(v[i].f2 == 0) {
            ry = min(ry , v[i].y) ;
        }
        if(v[i].f3 == 0){
            rx = min(rx , v[i].x) ;
        }
        if(v[i].f4 == 0){
            ly = max(ly , v[i].y) ;
        }

    } 



    if((lx > rx) || (ly > ry)){
        printf("0\n") ;
        return ;
    }


    printf("1 %d %d\n" , lx , ly) ;

}

int main() {

    int testCase = 1 ;

    scanf("%d" , &testCase) ;

    for(int T = 1 ; T <= testCase ; T ++){
        solve(T) ;
    }

    return 0 ;
}
