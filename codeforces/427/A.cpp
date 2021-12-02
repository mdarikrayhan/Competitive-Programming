#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, event[200000],count=0,pcount=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> event[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(event[i]>0){
            pcount=pcount+event[i];
        }
        else if(pcount>0){
            pcount--;
        }
        else{
            count++;
        }
    }
    cout << count;
}
