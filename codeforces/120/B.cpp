// Hydro submission #665173770980bc4294f989c3@1716614008354
#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
	freopen("input.txt", "r", stdin);  
	freopen("output.txt", "w", stdout);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    if(a[k]==1){
        cout << k;
        return 0;
    }
    else{
    	int i=k,d=0;
        while(!d){
            i++;
            if(i>n)
                i=1;
            d=a[i];
        }
        cout << i;
    }
    return 0;
}