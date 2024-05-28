#include<bits/stdc++.h>
#define ll long long
using namespace std;
int bit=1;
//0xx1开头
ll rec1(int i,int j,vector<int> &b){
    if(i>=j) return i!=j || b[i]==0?1:0;
    ll cur = 0;
    if(i>bit) return rec1(i+1,j-1,b)*2+(((ll)1)<<(j-i-1));
    if(b[i]==0&&(j>bit||b[j]==1))cur = rec1(i+1,j-1,b);
    if(b[i]==1&&(j>bit||b[j]==0)) cur += rec1(i+1,j-1,b);
    if(b[i]==0&&(j>bit||b[j]==0)) cur += ((ll)1)<<(bit>=j-1?0:bit>=i+1?j-bit-1:j-i-1);
    return cur;
}
//0xx0开头
ll rec2(int i,int j,vector<int> &b){
    if(i>=j) return i!=j || bit>=i ? 1:2;
    ll cur = 0;
    if(i>bit) return rec2(i+1,j-1,b)*2+(((ll)1)<<(j-i-1));
    if(b[i]==0&&(j>bit||b[j]==0))cur = rec2(i+1,j-1,b);
    if(b[i]==1&&(j>bit||b[j]==1)) cur += rec2(i+1,j-1,b);
    if(b[i]==0&&(j>bit||b[j]==1)) cur += ((ll)1)<<(bit>=j-1?0:bit>=i+1?j-bit-1:j-i-1);
    return cur;
}
int main(){
    ll n,k;
    cin>>n>>k;
    k++;
    vector<int> b(n+1,0);
    ll cur;
    cur = rec1(2, n - 1, b) + rec2(2, n - 1, b);
    if(cur<k){
        cout<<-1;
        return 0;
    }
    cout<<0;
    //0000 0001 0010 0011 0101 0110
    for(bit=2;bit<=n;bit++){
        cur = bit<n?rec1(2, n - 1, b) + rec2(2, n - 1, b):rec2(2, n - 1, b);
        if(cur < k){
            cout<<1;
            b[bit] = 1;
            k-=cur;
        }else{
            cout<<0;
        }
    }
}