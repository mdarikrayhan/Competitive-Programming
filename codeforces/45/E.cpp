// LUOGU_RID: 160563554
#include<bits/stdc++.h>
using namespace std;
string a[500],b[500];
int i,n,j,k;
int with[500],use[500],c[500],d[500];
int main(){
    cin>>n; 
    for(i=1;i<=n;i++){
      cin>>a[i];
      c[a[i][0]]++;
    }     
    for(i=1;i<=n;i++){
      cin>>b[i];
      d[b[i][0]]++;
	  } 
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    j=1;
    k=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
	    if(use[j]==0){
               if((c[b[j][0]]<d[b[j][0]]||a[i][0]==b[j][0])){
                  if(d[a[i][0]]<c[a[i][0]]||b[j][0]>=a[i][0]){
                		break;
					}
				}
        	}
		} 
    	with[i]=j;
        use[j]=1;
        d[b[j][0]]--;
        c[a[i][0]]--;
    }
    cout<<a[1]<<" "<<b[with[1]];
    for(i=2;i<=n;i++){
    	cout<<", "<<a[i]<<" "<<b[with[i]];
    }
    return 0;
}