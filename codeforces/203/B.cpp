#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    ll n , m ;
    cin >> n >> m ;

    bool arr[n][n]; 

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ) arr[i][j] = 0 ;
    }

    int ans=-1 ;              

    for( ll i=1 ; i<=m ; i++ ){
        int x , y ;
        cin >> x >> y ;

        x-- ;
        y-- ;

        arr[x][y] = 1 ;

        bool flag = 0 ;

        if( y-2>=0 && arr[x][y-1] && arr[x][y-2] ){

            if( x-1>=0 && x+1<n && arr[x-1][y] && arr[x-1][y-1] && arr[x-1][y-2] && arr[x+1][y] && arr[x+1][y-1] && arr[x+1][y-2]) flag = 1 ;

            if( x-2>=0 && arr[x-1][y] && arr[x-1][y-1] && arr[x-1][y-2] && arr[x-2][y] && arr[x-2][y-1] && arr[x-2][y-2] ) flag=1 ;

            if( x+2<n && arr[x+1][y] && arr[x+1][y-1] && arr[x+1][y-2] && arr[x+2][y] && arr[x+2][y-1] && arr[x+2][y-2] ) flag=1 ;

        }

        if( y+2<n && arr[x][y+1] && arr[x][y+2] ){

            if( x-1>=0 && x+1<n && arr[x-1][y] && arr[x-1][y+1] && arr[x-1][y+2] && arr[x+1][y] && arr[x+1][y+1] && arr[x+1][y+2]) flag = 1 ;

            if( x-2>=0 && arr[x-1][y] && arr[x-1][y+1] && arr[x-1][y+2] && arr[x-2][y] && arr[x-2][y+1] && arr[x-2][y+2] ) flag=1 ;

            if( x+2<n && arr[x+1][y] && arr[x+1][y+1] && arr[x+1][y+2] && arr[x+2][y] && arr[x+2][y+1] && arr[x+2][y+2] ) flag=1 ;

        }

        if( y-1>=0 && y+1<n && arr[x][y-1] && arr[x][y+1] ){
            if( x-1>=0 && x+1<n && arr[x-1][y-1] && arr[x-1][y] && arr[x-1][y+1] && arr[x+1][y-1] && arr[x+1][y] && arr[x+1][y+1] ) flag=1 ;

            if( x-2>=0 && arr[x-1][y-1] && arr[x-1][y] && arr[x-1][y+1] && arr[x-2][y-1] && arr[x-2][y] && arr[x-2][y+1] ) flag =1 ;

            if( x+2<n && arr[x+1][y-1] && arr[x+1][y] && arr[x+1][y+1] && arr[x+2][y-1] && arr[x+2][y] && arr[x+2][y+1] ) flag =1 ;
        }

        if( flag && ans==-1 ) ans = i ;
    }
 
    cout << ans << endl ;

    return 0;
}