#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int z=0;z<t;z++){
        int a,b,c,d;
        int mx1,mn1,mx2,mn2;
        cin >> a >> b >> c >> d;
        if (a>b){
            mx1=a;
            mn1=b;
        }
        else {
            mx1=b;
            mn1=a;
        }
        if (c>d){
            mx2=c;
            mn2=d;
        }
        else {
            mx2=d;
            mn2=c;
        }
        //cout << mx1 << ">" << mn2 << endl;
        //cout << mx2 << ">" << mn1 << endl;
        if (mx1>mn2 && mx2 > mn1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}