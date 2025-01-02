#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, sum=0;
    cin >> n;
    for(int i=2; i<n; i++){
        int div = i;
        int a = n;
        while(a){
            sum = sum+(a%div);
            a = a/i;
        }
    }
    int den = n-2;
    for(int i=2; i<=den; i++){
        while(((sum%i)==0) && ((den%i)==0)){
            sum = sum/i;
            den = den/i;
        }
    }
    cout << sum << "/" << den;
}