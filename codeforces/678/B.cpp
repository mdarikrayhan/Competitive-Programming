#include <iostream>
using namespace std;

bool isleap(int y){
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

int main(){
    int y;
    cin >> y;
    bool save = isleap(y);
    int days = 0;
    do{
        days++;
        if (isleap(y))  days++;
        y++;
        days %= 7;
    } while (days || isleap(y) != save);
    cout << y << endl;
}