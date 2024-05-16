#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int x=1,i=1;
    while(n>=x){
        i+= 1;
        x += (i*(i+1))/2;
    }
    cout << i-1;
}
