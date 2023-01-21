#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string s;
        int n;
        cin >> n;
        if(n>=90)
            s = "A+";
        else if(n>=80)
            s = "A";
        else if(n>=70)
            s = "A-";
        else if(n>=60)
            s = "B+";
        else if(n>=50)
            s = "B-";
        else if(n>=40)
            s = "C";
        else if(n>=35)
            s = "D";
        else
            s = "F";
        cout << "Student " << i << ": " << s << "\n";
    }
    return 0;
}