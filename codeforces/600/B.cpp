#include<bits/stdc++.h>
using namespace std;
#define junayed() ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    junayed();
    int n,m,i,sum=0,c;
    cin>>n>>m;
    int a[n+1];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    a[n]=INT_MAX;
   int b[m];
    for(i=0;i<m;i++){
        cin>>b[i];
    }
    for(i=0;i<m;i++){
        int l=0,r=n-1;
        int mid=(l+r)/2;
        if(b[i]<a[0]){
            cout<<"0"<<endl;
            continue;
        }
        while(l<=r){
            if(a[mid]<=b[i] && a[mid+1]>b[i]){
                 cout<<mid+1<<endl;
                break;
            }
            if(a[mid]>b[i]){
                r=mid-1;
            }else{
                l=mid+1;
            }
            mid=(l+r)/2;
        }

    }

}
 			     		  				   	 	 	  	 		