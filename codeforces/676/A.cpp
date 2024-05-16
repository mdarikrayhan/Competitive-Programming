#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int max=0,min=101,max_i,min_i,n,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        if(num>max){
            max=num;
        max_i=i;
        }
        if(num<min){
            min=num;
        min_i=i;
    }}
    int a=(min_i-0);
    int b=((n-min_i)-1);
    int c=((n-max_i)-1);
    int d=(max_i-0);
    int e=n-1;
   if((max_i==0&&min_i==e)||((max_i==e)&&(min_i==0)))
    {
     cout<<(n-1);
    }else{
        cout<<(a > b ? (a > c ? (a > d ? a : d) : (c > d ? c : d)) : (b > c ? (b > d ? b : d) : (c > d ? c : d)));
}
}