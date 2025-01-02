#include <bits/stdc++.h>
 using namespace std;

int main()
{   unsigned long long count;
    unsigned long long n;
    cin>>n;
    unsigned long long min_ind[n];
    unsigned long long a[n];
    unsigned long long min, gap=0;
    cin>>a[0];
    min=a[0];
    count=1;
    min_ind[0]=0;
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(min>a[i]){
            min=a[i];
            count=0;
        }
        if(a[i]==min){
            count+=1;
            min_ind[count-1]=i;
        }
    }
    if(count==1){
        cout<<n*min+n-1;
    }else{
        for(int i=0;i<count-1;i++){
            if(gap<min_ind[i+1]-min_ind[i]-1){
                gap=min_ind[i+1]-min_ind[i]-1;
            }
        }
        if(gap<n-min_ind[count-1]-1+min_ind[0]){
                gap=n-min_ind[count-1]-1+min_ind[0];
            }
    cout<<(n*min)+gap;
    }




    return 0;
}
