#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int b[2*n];
        map<int, int> m1;
        map<int, int> m2;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m1[a[i]]++;
        }
        for (int i = 0; i < 2 * n; i++)
        {
            b[i] = -1;
            m2[i + 1]++;
        }
        if (m1[1] == 0 || m1[2*n]==1)
        {
            cout << -1 << endl;
        }
        else
        {
            int k=0;
            for (int i = 0; i < 2 * n; i = i + 2)
            {
                b[i] = a[k];
                // cout<<b[i]<<" "<<a[k]<<endl;
                m2[a[k]] = 0;
                k++;
            }
            for (int i = 0; i < 2 * n; i++)
            {
                if (b[i] == -1)
                {
                    for(int j=1;j<=2*n;j++){
                         if(j>b[i-1] && m2[j]!=0){
                            b[i]=j;
                            m1[j]++;
                            m2[j]=0;
                            break;
                         }
                    }
                }
            }
            int k1=0;
            for (k1 = 0; k1 < 2 * n; k1++)
            {
                if(b[k1]==-1 || m1[b[k1]]>1){
                    break;
                }
            }
            if(k1==2*n){
            for (int i = 0; i < 2 * n; i++)
            {
                cout << b[i] << " ";
            }
            cout << endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
}