// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int sign(int x){
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

int main() {
    int t;
    int x1,x2,y1,y2;
    
    cin >> t;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;
    
    int difx = sign(x2-x1);
    int dify = sign(y2-y1);
    
    
    string s;
    cin >> s;
    int i = 0;
    for (; i < s.length(); i++)
    {
        if (s[i] == 'S' && dify == -1) y1--; 
        else if (s[i] == 'N' && dify == 1) y1++;
        else if (s[i] == 'E' && difx == 1) x1++; 
        else if (s[i] == 'W' && difx == -1) x1--;
        
        difx = sign(x2-x1);
        dify = sign(y2-y1);
        if ((difx == 0 && dify == 0)) break;
    }
    
    if (i+1 <= t)
    {
        cout << i+1;
    } else {
        cout << -1;
    }
    
    return 0;
}

