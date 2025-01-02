#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 
 
int main(){
    
    int n, m , a, b;
    cin >> n >> m >> a >> b;

    if (n <= m){
        if((a * n) > b){
            cout << b << endl;
        }
        else{
            cout << ( a * n );
        }
    }else{
        int passes = 1; 
        int passes1 = 1;
        while((n) > (passes * m)){
            passes++;
        }

        while(n >= (passes1 * m)){
            passes1++;
        }
        passes1--;


        int diff = n - (passes1 * m);

        int TC = (diff * a) + (passes1 * b);



        if((n * a) > (passes * b)){
            if((passes * b) > TC){
                cout << TC;
            }else{
                cout << (passes * b);    
            }
            
        }else{
            if((n * a) > TC){
                cout << TC;
            }
            else{
                cout << (n * a);    
            }
            
        }
    }
} 
