//code by Vivek Reddy
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,c=-1;
    cin >> n >> m;
    int a[n],b[m];
    for(int i = 0; i < n;i++)
        cin >> a[i];
    for(int i = 0;i < m;i++)
        cin >> b[i];
    sort(a,a+n);
    sort(b,b+m);
    for(int i = 0,j = 0; i < n && j < m;){
        if(a[i]==b[j]){
            c = a[i];
            break;
        }else if(a[i]>b[j])
            j++;
        else
            i++;
    }
    if(c != -1)
        cout <<c << endl;
    else
        cout << ((min(a[0],b[0])*10)+max(a[0],b[0])) << endl;
    return 0;
}
