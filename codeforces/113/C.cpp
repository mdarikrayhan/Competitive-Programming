#include <bits/stdc++.h>
using namespace std;
int l, r, i, j, a;
const int M=3e8; 
bitset<M> P;
int main()
{
    cin >> l >> r;
    for (i=3;i*i<=M; i+=2) for(j=i*i; !P[i]&j<M; P[j]=1, j+=2*i){}
    for (i=5; i<=r; i+=4) a+=!P[i]&i>=l; cout << a+(l<=2&r>=2);
}